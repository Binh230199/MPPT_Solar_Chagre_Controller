/*
 * Button.h
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <cstdint>

#include "Singleton.h"
#include "Monitor.h"

namespace blib
{
    class Button : public blib::dp::Singleton<Button>
    {
        public:
            enum class ButtonName
            {
                UNDEFINED = 0, UP, DOWN, SEL, BACK
            };

            Button();
            virtual ~Button();

            void setLatestPressedButton(const ButtonName button);
            ButtonName getLatestPressedButton() const;
            void handleSignal();
        private:
            ButtonName mLatestPressedButton;
    };
}

#endif /* BUTTON_H_ */
