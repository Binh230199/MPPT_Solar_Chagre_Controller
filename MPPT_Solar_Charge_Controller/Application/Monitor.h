/*
 * Monitor.h
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

namespace blib
{
    // Monitor is a derived state machine
    class Monitor : public blib::dp::StateMachineBase<Monitor>
    {
        public:
            enum class Event
            {

            };

            Monitor();
            virtual ~Monitor();

            void showMenu();
            void showVersion();
        private:
    };

}

#endif /* MONITOR_H_ */
