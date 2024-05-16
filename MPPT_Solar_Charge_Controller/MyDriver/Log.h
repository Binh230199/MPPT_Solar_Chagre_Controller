/*
 * Log.h
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef LOG_LOG_H_
#define LOG_LOG_H_

#include <cstdint>
#include <cstdio>
#include <cstring>
#include "main.h"

#define LOG_ENABLE

#ifdef LOG_ENABLE
#define LOG(msg, ...) blib::Logger::Log(msg, ##__VA_ARGS__)
#else
#define LOG(msg, ...)
#endif

#define LOG_HDR "[%s:%d][%s]: "
#define LOG_ARGS __FILE_NAME__, __LINE__, __FUNCTION__

#define LOGI(msg, args...) LOG(LOG_HDR msg, LOG_ARGS, ##args)

namespace blib
{
    class Logger
    {
        public:
            template<typename ... Args>
            static void Log(const char *message, Args ... args)
            {
                print("[>]  ");
                snprintf(mBuffer, LOG_BUFFER_SIZE, message, args...);
                print(mBuffer);
                print("\n");
            }

        private:
            static const uint16_t LOG_BUFFER_SIZE = 1024U;
            static UART_HandleTypeDef *mHuart;
            static char mBuffer[LOG_BUFFER_SIZE];

            static void print(const char *msg)
            {
                HAL_UART_Transmit(mHuart, (uint8_t*) const_cast<char*>(msg), strlen(msg), 1000);
            }
    };
}
#endif /* LOG_LOG_H_ */
