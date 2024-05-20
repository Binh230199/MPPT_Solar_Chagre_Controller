/*
 * DeviceProtection.h
 *
 *  Created on: May 17, 2024
 *      Author: This PC
 */

#ifndef DEVICEPROTECTION_H_
#define DEVICEPROTECTION_H_

#include "Log.h"
#include "Singleton.h"
#include "main.h"
#include "Constant.h"

namespace blib
{
    class DeviceProtection : public dp::Singleton<DeviceProtection>
    {
        public:
            DeviceProtection();
            virtual ~DeviceProtection();
            void backFlowControl();
            void run();

            OutputMode mOutputMode;    // false: PSU
            bool mBypassEnable;
            int mERR = 0;
            bool mBNC = false;    // SYSTEM PARAMETER -
            bool mREC = false;    // SYSTEM PARAMETER -
            bool mFLV = false;    // SYSTEM PARAMETER -
            bool mIUV = false;    // SYSTEM PARAMETER -
            bool mIOV = false;    // SYSTEM PARAMETER -
            bool mIOC = false;    // SYSTEM PARAMETER -
            bool mOUV = false;    // SYSTEM PARAMETER -
            bool mOOV = false;    // SYSTEM PARAMETER -
            bool mOOC = false;    // SYSTEM PARAMETER -
            bool mOTE = false;    // SYSTEM PARAMETER -
    };
}
#endif /* DEVICEPROTECTION_H_ */