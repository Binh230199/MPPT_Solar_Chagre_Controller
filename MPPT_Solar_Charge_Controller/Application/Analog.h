/*
 * Analog.h
 *
 *  Created on: May 14, 2024
 *      Author: This PC
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

namespace blib
{
    struct AnalogLine
    {
            uint8_t ratio;    // He so cau phan ap

    };

    class Analog : public dp::Singleton<Analog>
    {
        public:
            Analog();
            virtual ~Analog();

        private:
    };
}

#endif /* ANALOG_H_ */