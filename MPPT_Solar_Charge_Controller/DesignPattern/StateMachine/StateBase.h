/*
 * StateBase.h
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#ifndef STATEMACHINE_STATEBASE_H_
#define STATEMACHINE_STATEBASE_H_

namespace blib
{
    namespace dp
    {
        template<typename T>
        class StateBase
        {
            public:
                virtual void enter();
                virtual void exit();
                virtual void handleEvent(StateBase<T> *&nextState);
        };
    }    // namespace dp
}    // namespace blib

#endif /* STATEMACHINE_STATEBASE_H_ */
