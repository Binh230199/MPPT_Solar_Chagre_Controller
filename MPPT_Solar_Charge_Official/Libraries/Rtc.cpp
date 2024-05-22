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
        if (!isTimeValid(hour, minute, date, month, year))
        {
            return;
        }

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

    // Function to check if a year is a leap year
    bool Rtc::isLeapYear(uint8_t year)
    {
        // Assume years 00-99 refer to 2000-2099
        uint16_t actualYear = 2000 + year;

        // A year is a leap year if it is divisible by 4, except for years divisible by 100.
        // However, years divisible by 400 are leap years.
        return ((actualYear % 4 == 0) && (actualYear % 100 != 0)) || (actualYear % 400 == 0);
    }

    // Function to check if the provided time parameters are valid
    bool Rtc::isTimeValid(uint8_t hour, uint8_t minute, uint8_t date, uint8_t month, uint8_t year)
    {
        // Check hour range (0-23)
        if (hour > 23 && hour < 0)
            return false;

        // Check minute range (0-59)
        if (minute > 59 && minute < 0)
            return false;

        // Check date range (1-31)
        if (date < 1 || date > 31)
            return false;

        // Check month range (1-12)
        if (month < 1 || month > 12)
            return false;

        // Check year range (0-99)
        if (year > 99)
            return false;

        // Check if the month is February and the year is a leap year
        if (month == 2 && date > 28)
        {
            if (isLeapYear(year))
            {
                // February in a leap year has 29 days
                if (date > 29)
                    return false;
            }
            else
            {
                // February in a non-leap year has 28 days
                return false;
            }
        }

        // All parameters are valid
        return true;
    }

    void Rtc::incrementParameter(int selectedParameter, uint8_t &hour, uint8_t &minute,
            uint8_t &date, uint8_t &month, uint8_t &year)
    {
        // Increment the selected parameter
        switch (selectedParameter)
        {
            case 0:    // Hour
                hour = (hour + 1) % 24;
                break;
            case 1:    // Minute
                minute = (minute + 1) % 60;
                break;
            case 2:    // Date
                date = (date + 1)
                        % (isLeapYear(year) && month == 2 ?
                                30 :
                                (month == 2 ?
                                        29 :
                                        (month == 4 || month == 6 || month == 9 || month == 11 ?
                                                30 : 31)));
                if (date == 0)
                    date = 1;
                break;
            case 3:    // Month
                month = (month + 1) % 13;
                if (month == 0)
                    month = 1;
                break;
            case 4:    // Year
                year = (year + 1) % 100;
                break;
        }
    }

    void Rtc::decrementParameter(int selectedParameter, uint8_t &hour, uint8_t &minute,
            uint8_t &date, uint8_t &month, uint8_t &year)
    {
        // Decrement the selected parameter
        switch (selectedParameter)
        {
            case 0:    // Hour
                hour = (hour + 23) % 24;
                break;
            case 1:    // Minute
                minute = (minute + 59) % 60;
                break;
            case 2:    // Date
                date = (date
                        + (isLeapYear(year) && month == 2 ?
                                29 :
                                (month == 2 ?
                                        28 :
                                        (month == 4 || month == 6 || month == 9 || month == 11 ?
                                                29 : 30))) - 1)
                        % (isLeapYear(year) && month == 2 ?
                                30 :
                                (month == 2 ?
                                        29 :
                                        (month == 4 || month == 6 || month == 9 || month == 11 ?
                                                30 : 31))) + 1;
                break;
            case 3:    // Month
                month = (month + 12) % 13;
                if (month == 0)
                    month = 1;
                break;
            case 4:    // Year
                year = (year + 99) % 100;
                break;
        }
    }

}

