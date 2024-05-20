/*
 * SerialMonitor.h
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef SERIALMONITOR_H_
#define SERIALMONITOR_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"

// Add log library
#include "Log.h"

namespace blib
{
    class SerialMonitor : public dp::Singleton<SerialMonitor>
    {
        public:
            enum class SerialLevel
            {
                SERIAL_LEVEL_0 = 0,    // Do not show anything
                SERIAL_LEVEL_1,    // Show all things
                SERIAL_LEVEL_2,    // Show essential things
                SERIAL_LEVEL_3,    //Show number only
                SERIAL_LEVEL_MAX
            };
            SerialMonitor();
            virtual ~SerialMonitor();
            void show();

            void setSerialLevel(const SerialLevel level);
            SerialLevel getSerialLevel() const;

        private:
            void serialLevel1();
            void serialLevel2();
            void serialLevel3();

        private:

            SerialLevel mSerialLevel = SerialLevel::SERIAL_LEVEL_0;
    };
}

#endif /* SERIALMONITOR_H_ */
