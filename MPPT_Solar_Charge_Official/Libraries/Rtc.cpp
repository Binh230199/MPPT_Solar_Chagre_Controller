/*
 * Rtc.cpp
 *
 *  Created on: May 21, 2024
 *      Author: This PC
 */

#include "Rtc.h"

namespace blib
{
    Rtc::Rtc()
    {
        mHrtc = &hrtc;

        readTime();
    }
    Rtc::~Rtc()
    {

    }
    void Rtc::readTime()
    {
        RTC_TimeTypeDef sTime;
        RTC_DateTypeDef sDate;

        HAL_RTC_GetTime(mHrtc, &sTime, RTC_FORMAT_BIN);
        HAL_RTC_GetDate(mHrtc, &sDate, RTC_FORMAT_BIN);

        mHour = sTime.Hours;
        mMinute = sTime.Minutes;
        mDate = sDate.Date;
        mMonth = sDate.Month;
        mYear = sDate.Year;
    }
    void Rtc::setTime(uint8_t hour, uint8_t minute, uint8_t date, uint8_t month, uint8_t year)
    {
        RTC_TimeTypeDef sTime;
        RTC_DateTypeDef sDate;

        sTime.Hours = RTC_ByteToBcd2(hour);
        sTime.Minutes = RTC_ByteToBcd2(minute);
        sTime.Seconds = RTC_ByteToBcd2(0);
        sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
        sTime.StoreOperation = RTC_STOREOPERATION_RESET;
        if (HAL_RTC_SetTime(mHrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
        {
        }
        sDate.WeekDay = RTC_WEEKDAY_MONDAY;
        sDate.Month = RTC_ByteToBcd2(month);
        sDate.Date = RTC_ByteToBcd2(date);
        sDate.Year = RTC_ByteToBcd2(year);

        if (HAL_RTC_SetDate(mHrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
        {
        }
    }

}
