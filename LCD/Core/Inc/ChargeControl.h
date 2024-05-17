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

// Add log library
#include "Log.h"

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
        private:
            void buckEnable();
            void buckDisable();
            void predictPwm();
            void generatePwm();

        private:
            bool mBuckEnable = false;
            bool mMpptMode = false;    // false: CC-CV Buck PSU, true: MPPT & CC-CV charging
            uint32_t mPwm;
    };

}    // namespace blib

#endif /* CHARGECONTROL_H_ */