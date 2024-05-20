/*
 * Log.cpp
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "Log.h"
#include "Constant.h"
#ifdef TEST
extern UART_HandleTypeDef huart2;
#else
extern UART_HandleTypeDef huart3;
#endif

namespace blib
{
    char Logger::mBuffer[LOG_BUFFER_SIZE] = { 0 };

#ifdef TEST
    UART_HandleTypeDef *Logger::mHuart = &huart2;
#else
    UART_HandleTypeDef *Logger::mHuart = &huart3;
#endif

}
