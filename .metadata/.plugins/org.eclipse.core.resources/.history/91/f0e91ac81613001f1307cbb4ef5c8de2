/*
 * Log.cpp
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#include "Log.h"

extern UART_HandleTypeDef huart2;

namespace blib
{
    char Logger::mBuffer[LOG_BUFFER_SIZE] = { 0 };
    UART_HandleTypeDef *Logger::mHuart = &huart2;
}

