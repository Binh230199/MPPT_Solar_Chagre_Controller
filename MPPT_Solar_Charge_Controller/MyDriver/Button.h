/*
 * Button.h
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "Singleton.h"

namespace blib
{
    class ButtonHandler : public blib::dp::Singleton<ButtonHandler>
    {
        public:
            ButtonHandler();
            virtual ~ButtonHandler();

        private:
            uint8_t m;
    };
}

#endif /* BUTTON_H_ */
