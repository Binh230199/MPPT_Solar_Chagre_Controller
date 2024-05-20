/*
 * Rtc.h
 *
 *  Created on: May 21, 2024
 *      Author: This PC
 */

#ifndef RTC_H_
#define RTC_H_

#include "main.h"

extern RTC_HandleTypeDef hrtc;

namespace blib
{
    class Rtc
    {
        public:
            Rtc();
            ~Rtc();
            void readTime();
            void setTime(uint8_t hour, uint8_t minute, uint8_t date, uint8_t month, uint8_t year);

            RTC_HandleTypeDef *mHrtc;
            uint8_t mHour;
            uint8_t mMinute;
            uint8_t mDate;
            uint8_t mMonth;
            uint8_t mYear;
    };
}

#endif /* RTC_H_ */
