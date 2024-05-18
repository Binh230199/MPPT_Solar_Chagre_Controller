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
        if (mOutputMode == OutputMode::PSU)    // PSU mode: force backflow MOSFET on
        {
            mBypassEnable = true;
        }
        //Charger Mode
        else if (mOutputMode == OutputMode::CHARGER)
        {
            // Normal Condition - Turn on Backflow MOSFET (on by default when not in MPPT charger mode)
            if (analog.mVin > analog.mVout + k_voltage_dropout)
            {
                mBypassEnable = true;
            }
            // Input Undervoltage - Turn off bypass MOSFET and prevent PV Backflow (SS)
            else
            {
                mBypassEnable = false;    // Vsolar < Vbattery -> Dien chay tu battery -> solar => khong cho xay ra van de nay
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
        if (analog.getTemp() > k_temperature_max)
        {
            mOTE = true;    // Set co qua nhiet
            mERR++;
        }
        else
        {
            mOTE = false;
        }

        // Qua dong input
        if (analog.getSolarCurrent() > k_current_in_absolute)
        {
            mIOC = true;
            mERR++;
        }
        else
        {
            mIOC = false;
        }

        // Qua dong output
        if (analog.getIout() > k_current_out_absolute)
        {
            mOOC = true;
            mERR++;
        }
        else
        {
            mOOC = false;
        }

        // Qua ap output
        if (analog.getVout() > k_voltage_battery_max + k_voltage_battery_thresh)
        {
            mOOV = true;
            mERR++;
        }
        else
        {
            mOOV = false;
        }

        // Qua dong input
        if (analog.getSolarVoltage() < k_v_in_system_min && analog.getVout() < k_v_in_system_min)
        {
            mFLV = true;
            mERR++;
        }
        else
        {
            mFLV = false;
        }

        //PSU MODE specific protection protocol
        if (mOutputMode == OutputMode::PSU)
        {
            //Clear recovery and battery not connected boolean identifiers
            mREC = false;
            mBNC = false;

            //IUV - INPUT UNDERVOLTAGE: Input voltage is below battery voltage (for psu mode only)
            if (analog.getSolarVoltage() < k_voltage_battery_max + k_voltage_dropout)
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
        else if (mOutputMode == OutputMode::CHARGER)
        {
            // Enable backflow current detection & control
            backFlowControl();

            // BNC - BATTERY NOT CONNECTED (for charger mode only, does not treat BNC as error when not under MPPT mode)
            if (analog.getVout() < k_v_in_system_min)
            {
                mBNC = true;
                mERR++;
            }
            else
            {
                mBNC = false;
            }

            //IUV - INPUT UNDERVOLTAGE: Input voltage is below max battery charging voltage (for charger mode only)
            if (analog.getSolarVoltage() < k_voltage_battery_max + k_voltage_dropout)
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

