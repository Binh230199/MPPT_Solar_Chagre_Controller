/*
 * SerialMonitor.cpp
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef SERIALMONITOR_CPP_
#define SERIALMONITOR_CPP_

#include "SerialMonitor.h"

namespace blib
{

    SerialMonitor::SerialMonitor()
    {
        setSerialLevel(SerialLevel::SERIAL_LEVEL_1);    // TODO: test
    }
    SerialMonitor::~SerialMonitor()
    {
        setSerialLevel(SerialLevel::SERIAL_LEVEL_0);
    }
    void SerialMonitor::show()
    {
        switch (getSerialLevel())
        {
            case SerialLevel::SERIAL_LEVEL_1:
                serialLevel1();
                break;
            case SerialLevel::SERIAL_LEVEL_2:
                serialLevel2();
                break;
            case SerialLevel::SERIAL_LEVEL_3:
                serialLevel3();
                break;
            case SerialLevel::SERIAL_LEVEL_0:
            case SerialLevel::SERIAL_LEVEL_MAX:
            default:
                break;
        }
    }

    void SerialMonitor::setSerialLevel(const SerialLevel val)
    {
        uint8_t u8SerialLevel = (uint8_t) val;

        if (u8SerialLevel < 0)
        {
            u8SerialLevel = (uint8_t) SerialLevel::SERIAL_LEVEL_MAX - 1;    // Rotate
        }
        else if (u8SerialLevel >= (uint8_t) SerialLevel::SERIAL_LEVEL_MAX)
        {
            u8SerialLevel = 0;
        }

        mSerialLevel = (SerialLevel) u8SerialLevel;
    }
    SerialMonitor::SerialLevel SerialMonitor::getSerialLevel() const
    {
        return mSerialLevel;
    }

    void SerialMonitor::serialLevel1()
    {
        LOGI(
                " ERR:" " FLV:" " BNC:" " IUV:" " IOC:" " OOV:" " OOC:" " OTE:" " REC:" " MPPTA:" " CM:"

                " " " BYP:" " EN:" " FAN:" " WiFi:" " " " PI:" " PWM:" " PPWM:" " VI:" " VO:" " CI:" " CO:" " Wh:" " Temp:" " " " CSMPV:" " CSV:" " VO%Dev:" " SOC:" " T:" " LoopT:");
    }
    void SerialMonitor::serialLevel2()
    {
        LOGI(
                " PI:" " PWM:" " PPWM:" " VI:" " VO:" " CI:" " CO:" " Wh:" " Temp:" " EN:" " FAN:" " SOC:" " T:" " LoopT:" "");
    }
    void SerialMonitor::serialLevel3()
    {
        LOGI();
    }

}    // namespace blib

#endif /* SERIALMONITOR_CPP_ */
