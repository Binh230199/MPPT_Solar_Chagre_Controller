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

// Add librarys
#include "Log.h"
#include "Constant.h"
// Add main header
#include "main.h"

namespace blib
{
    class ChargeControl : public dp::Singleton<ChargeControl>
    {
        public:
            ChargeControl();
            virtual ~ChargeControl();
            void run();

            void setBuckEnable(const bool val);
            bool getBuckEnable() const;
            void setMpptMode(const bool val);
            bool getMpptMode() const;

            void buckEnable();
            void buckDisable();
            void inverterDisable();
            void inverterEnable();
            uint32_t predictPwm();
            void generatePwm(uint32_t val);
            void pwmInit(uint32_t frequency, uint32_t dutyCycle);
            void pwmWrite();

            TIM_HandleTypeDef *mHtim;
            bool mChargePause = false;
            bool mChargeState = false;

            OutputMode mOutputMode = OutputMode::PSU;    // Dung de bam xung
            bool mMpptMode = false;    // Dung de xac dinh thuat toan
            bool mBuckEnable = false;
            uint32_t mPwm;
            uint32_t mPredictPwm;
            uint32_t mPwmMax;
            uint32_t mPwmMaxLimit;

            static constexpr float mPredictPwmMargin = 99.5f;    //  Minimum Operating Duty Cycle for Predictive PWM (%)
            static constexpr float mPwmMaxDc = 97.0f;    // Maximum Operating Duty Cycle (%) 90%-97% is good
    };

}    // namespace blib

#endif /* CHARGECONTROL_H_ */
