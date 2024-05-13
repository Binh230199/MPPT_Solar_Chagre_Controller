/*
 * Monitor.cpp
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#include "Monitor.h"
#include "Button.h"

namespace blib
{
    Monitor::Monitor() : StateMachineBase()
    {
        showVersion();
    }
    Monitor::~Monitor()
    {

    }

    void Monitor::showVersion()
    {
        LOGI("MPPT INITIALIZED");
        LOGI("FIRMWARE V1.00");
    }

//    void show
}

