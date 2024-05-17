/*
 * DeviceProtection.h
 *
 *  Created on: May 17, 2024
 *      Author: This PC
 */

#ifndef DEVICEPROTECTION_H_
#define DEVICEPROTECTION_H_

#include "Log.h"
#include "Singleton.h"
#include "main.h"
namespace blib
{
    class DeviceProtection : public dp::Singleton<DeviceProtection>
    {
        public:
            DeviceProtection();
            virtual ~DeviceProtection();
            void backFlowControl();
            void protectDevice();
        private:
            static constexpr float mVoltageDropout = 1.0000f;

            bool mOutputMode;    // false: PSU
            bool mBypassEnable;
            int mERR = 0;
            bool mBNC = false;    // SYSTEM PARAMETER -
            bool mREC = false;    // SYSTEM PARAMETER -
            bool mFLV = false;    // SYSTEM PARAMETER -
            bool mIUV = false;    // SYSTEM PARAMETER -
            bool mIOV = false;    // SYSTEM PARAMETER -
            bool mIOC = false;    // SYSTEM PARAMETER -
            bool mOUV = false;    // SYSTEM PARAMETER -
            bool mOOV = false;    // SYSTEM PARAMETER -
            bool mOOC = false;    // SYSTEM PARAMETER -
            bool mOTE = false;    // SYSTEM PARAMETER -

            static constexpr float mTemperatureMax = 60.0f;    // Celcius
            static constexpr float mCurrentInAbsolute = 31.0f;    // Ampere
            static constexpr float mCurrentOutAbsolute = 50.0f;    // Ampere
            static constexpr float mVoltageBatteryMax = 27.3f;    // Maximum Battery Charging Voltage (Output V)
            static constexpr float mVoltageBatteryMin = 22.4f;    //   USER PARAMETER - Minimum Battery Charging Voltage (Output V)
            static constexpr float mCurrentCharging = 30.0f;    //   USER PARAMETER - Maximum Charging Current (A - Output)
            static constexpr float mElectricalPrice = 9.5f;    //   USER PARAMETER - Input electrical price per kWh (Dollar/kWh,Euro/kWh,Peso/kWh)
            static constexpr float mVoltageBatteryThresh = 1.5f;    //  CALIB PARAMETER - Power cuts-off when this voltage is reached (Output V)
            static constexpr float mVInSystemMin = 10.0f;
    };
}
#endif /* DEVICEPROTECTION_H_ */