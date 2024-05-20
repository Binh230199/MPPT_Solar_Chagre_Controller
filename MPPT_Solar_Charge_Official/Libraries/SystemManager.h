/*
 * SystemManager.h
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef SYSTEMMANAGER_H_
#define SYSTEMMANAGER_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"

// Add libraries
#include "Log.h"
#include "SerialMonitor.h"
#include "ChargeControl.h"
#include "Analog.h"

// Add main header
#include "main.h"

namespace blib
{
    class SystemManager : public dp::Singleton<SystemManager>
    {
        public:
            SystemManager()
            {

            }
            virtual ~SystemManager()
            {

            }
            void process()
            {
                if (enableFan == true)
                {
                    HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_RESET);
                }
                else
                {
                    HAL_GPIO_WritePin(FAN_GPIO_Port, FAN_Pin, GPIO_PIN_SET);
                }

                auto &analog = Analog::getInstance();

                if (ChargeControl::getInstance().mBuckEnable == true)
                {
                    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);
                }
                else
                {
                    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_SET);
                }

                if (analog.mBatteryPercent >= 99)
                {
                    HAL_GPIO_WritePin(LED_YEL_GPIO_Port, LED_YEL_Pin, GPIO_PIN_SET);
                    HAL_GPIO_WritePin(LED_GRE_GPIO_Port, LED_GRE_Pin, GPIO_PIN_RESET);
                }
                else if (analog.mBatteryPercent < 10)
                {
                    HAL_GPIO_WritePin(LED_YEL_GPIO_Port, LED_YEL_Pin, GPIO_PIN_RESET);
                    HAL_GPIO_WritePin(LED_GRE_GPIO_Port, LED_GRE_Pin, GPIO_PIN_SET);
                }
                else
                {
                    HAL_GPIO_WritePin(LED_YEL_GPIO_Port, LED_YEL_Pin, GPIO_PIN_SET);
                    HAL_GPIO_WritePin(LED_GRE_GPIO_Port, LED_GRE_Pin, GPIO_PIN_SET);
                }
            }

            bool enableFan = false;
            bool isLoadCfgFromFlash = false;
    };
}    // namespace blib

#endif /* SYSTEMMANAGER_H_ */
