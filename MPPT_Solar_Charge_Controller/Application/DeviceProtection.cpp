/*
 * DeviceProtection.cpp
 *
 *  Created on: May 17, 2024
 *      Author: This PC
 */

#include "DeviceProtection.h"
#include "Analog.h"

namespace blib
{
    DeviceProtection::DeviceProtection()
    {

    }
    DeviceProtection::~DeviceProtection()
    {

    }
    void DeviceProtection::backFlowControl()
    {
        auto &analog = Analog::getInstance();

        // PSU Mode
        if (mOutputMode == false)    // PSU mode: force backflow MOSFET on
        {
            mBypassEnable = true;
        }
        //Charger Mode
        else
        {
            // Normal Condition - Turn on Backflow MOSFET (on by default when not in MPPT charger mode)
            if (analog.getVin() > analog.getVout() + mVoltageDropout)
            {
                mBypassEnable = true;
            }
            // Input Undervoltage - Turn off bypass MOSFET and prevent PV Backflow (SS)
            else
            {
                mBypassEnable = false;
            }
        }

        HAL_GPIO_WritePin(BFC_GPIO_Port, BFC_Pin, ((GPIO_PinState) !mBypassEnable));
    }

    void DeviceProtection::protectDevice()
    {
        auto &analog = Analog::getInstance();
        mERR = 0;

        backFlowControl();

        // Nhiet do hien tai lon hon nhiet do max
        if (analog.getTemp() > mTemperatureMax)
        {
            mOTE = true;    // Set co qua nhiet
            mERR++;
        }
        else
        {
            mOTE = false;
        }

        // Qua dong input
        if (analog.getIin() > mCurrentInAbsolute)
        {
            mIOC = true;
            mERR++;
        }
        else
        {
            mIOC = false;
        }

        // Qua dong output
        if (analog.getIout() > mCurrentOutAbsolute)
        {
            mOOC = true;
            mERR++;
        }
        else
        {
            mOOC = false;
        }

        // Qua ap output
        if (analog.getVout() > mVoltageBatteryMax + mVoltageBatteryThresh)
        {
            mOOV = true;
            mERR++;
        }
        else
        {
            mOOV = false;
        }

        // Qua dong input
        if (analog.getVin() < mVInSystemMin && analog.getVout() < mVInSystemMin)
        {
            mFLV = true;
            mERR++;
        }
        else
        {
            mFLV = false;
        }

        //PSU MODE specific protection protocol
        if (mOutputMode == false)
        {
            //Clear recovery and battery not connected boolean identifiers
            mREC = false;
            mBNC = false;

            //IUV - INPUT UNDERVOLTAGE: Input voltage is below battery voltage (for psu mode only)
            if (analog.getVin() < mVoltageBatteryMax + mVoltageDropout)
            {
                mIUV = true;
                mERR++;
            }
            else
            {
                mIUV = false;
            }
        }
        // Charger MODE specific protection protocol
        else
        {
            // Enable backflow current detection & control
            backFlowControl();

            // BNC - BATTERY NOT CONNECTED (for charger mode only, does not treat BNC as error when not under MPPT mode)
            if (analog.getVout() < mVInSystemMin)
            {
                mBNC = true;
                mERR++;
            }
            else
            {
                mBNC = false;
            }

            //IUV - INPUT UNDERVOLTAGE: Input voltage is below max battery charging voltage (for charger mode only)
            if (analog.getVin() < mVoltageBatteryMax + mVoltageDropout)
            {
                mIUV = true;
                mERR++;
                mREC = true;
            }
            else
            {
                mIUV = false;
            }
        }

    }

}    // namespace blib
