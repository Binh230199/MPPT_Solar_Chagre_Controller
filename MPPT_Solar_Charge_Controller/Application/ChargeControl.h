/*
 * ChargeControl.h
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef CHARGECONTROL_H_
#define CHARGECONTROL_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

// Add main header
#include "main.h"

namespace blib
{
    class ChargeControl : public dp::Singleton<ChargeControl>
    {
        public:
            enum class OutputMode
            {
                PSU, CHARGER, INVERTER
            };

            ChargeControl();
            virtual ~ChargeControl();
            void run();

            void setBuckEnable(const bool val);
            bool getBuckEnable() const;
            void setMpptMode(const bool val);
            bool getMpptMode() const;

            void buckEnable();
            void buckDisable();
            uint32_t predictPwm();
            void generatePwm(uint32_t val);
            void pwmInit(uint32_t frequency, uint32_t dutyCycle);
            void pwmWrite();

            TIM_HandleTypeDef *mHtim;
            bool mChargePause = false;
            bool mChargeState = false;

            OutputMode mOutputMode = OutputMode::PSU;

            bool mBuckEnable = false;
            bool mMpptMode = false;    // false: CC-CV Buck PSU, true: MPPT & CC-CV charging
            uint32_t mPwm;
            uint32_t mPredictPwm;
            uint32_t mPwmMax;
            uint32_t mPwmMaxLimit;

            static constexpr float mPredictPwmMargin = 99.5f;    //  Minimum Operating Duty Cycle for Predictive PWM (%)
            static constexpr float mPwmMaxDc = 97.0f;    // Maximum Operating Duty Cycle (%) 90%-97% is good
    };

}    // namespace blib

#endif /* CHARGECONTROL_H_ */
