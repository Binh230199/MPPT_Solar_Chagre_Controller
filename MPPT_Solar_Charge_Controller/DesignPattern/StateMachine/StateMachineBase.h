/*
 * StateMachineBase.h
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef STATEMACHINE_STATEMACHINEBASE_H_
#define STATEMACHINE_STATEMACHINEBASE_H_

#include "Log.h"

namespace blib
{
    namespace dp
    {
        template<typename T>
        class StateMachineBase
        {
            public:

            protected:
                StateMachineBase()
                {
                    LOGI();
                }

                virtual ~StateMachineBase()
                {

                }

            private:
        };
    }    // namespace dp
}    // namespace blib

#endif /* STATEMACHINE_STATEMACHINEBASE_H_ */
