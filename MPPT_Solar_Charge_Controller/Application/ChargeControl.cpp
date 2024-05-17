/*
 * ChargeControl.cpp
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "ChargeControl.h"
#include "Monitor.h"
#include "Analog.h"
#include "DeviceProtection.h"

namespace blib
{
    template<typename T>
    T constrainValue(T value, T minVal, T maxVal)
    {
        if (value < minVal)
        {
            return minVal;    // Nếu giá trị nhỏ hơn minVal, trả về minVal
        }
        else if (value > maxVal)
        {
            return maxVal;    // Nếu giá trị lớn hơn maxVal, trả về maxVal
        }
        else
        {
            return value;    // Nếu giá trị nằm trong khoảng, trả về giá trị ban đầu
        }
    }

    ChargeControl::ChargeControl()
    {

    }
    ChargeControl::~ChargeControl()
    {

    }
    void ChargeControl::run()
    {
        auto &analog = Analog::getInstance();
        if (/* ErrorCode != NO_ERROR || chargingPause = true */true)
        {
            buckDisable();
        }
        else
        {
            if (/* Recovery == true */true)
            {
//                recovery = false;
                buckDisable();

                Monitor::getInstance().impl_DisplayDetectPowerSource();
                analog.readAnalog();
                float pwm = predictPwm();
                Monitor::getInstance().impl_DisplayOff();
            }
            else
            {
                if (/*mpptMode == */false)
                {
                    static float currentCharging = analog.getIout();
                    float pwm = 0.0f;
                    float voltageBatteryMax = 30.0f;
                    float voltageBatteryMin = 11.0f;

                    if (analog.getIout() > currentCharging)
                    {
                        pwm--;
                    }
                    else if (analog.getVout() > voltageBatteryMax)
                    {
                        pwm--;
                    }
                    else if (analog.getVout() < voltageBatteryMin)
                    {
                        pwm++;
                    }
                    else
                    {

                    }

//                    pwmModulation(pwm);
                }
                else
                {
//                    static float currentCharging = analog.getIout();
//                    if (analog.getIout() > currentCharging)
//                    {
//
//                    }
                }
            }
        }
    }

    void ChargeControl::setBuckEnable(const bool val)
    {
        mBuckEnable = val;
    }
    bool ChargeControl::getBuckEnable() const
    {
        return mBuckEnable;
    }
    void ChargeControl::setMpptMode(const bool val)
    {
        mMpptMode = val;
    }
    bool ChargeControl::getMpptMode() const
    {
        return mMpptMode;
    }

    // Enable Mppt Buck converter
    void ChargeControl::buckEnable()
    {
        LOGI();
        setBuckEnable(true);
        HAL_GPIO_WritePin(BUCK_EN_GPIO_Port, BUCK_EN_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
    }

    // Disable Mppt Buck converter
    void ChargeControl::buckDisable()
    {
        LOGI();
        setBuckEnable(false);
        HAL_GPIO_WritePin(BUCK_EN_GPIO_Port, BUCK_EN_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
        mPwm = 0;
    }
    float ChargeControl::predictPwm()
    {
        auto &analog = Analog::getInstance();
        auto &devProtection = DeviceProtection::getInstance();

        float predictPwm = 0.0f, ppwmMargin = 0, pwmMax = 0, pwmMaxLimited = 1000;

        if (analog.getVin() < 0.0f)
        {
            predictPwm = 0;
        }
        else
        {
            predictPwm = (ppwmMargin * pwmMax * analog.getVout()) / (100.0f * analog.getVin());
        }

        predictPwm = constrainValue(predictPwm, 0.0f, pwmMaxLimited);

        return predictPwm;
    }
    void ChargeControl::generatePwm()
    {

    }

}    // namespace blib
