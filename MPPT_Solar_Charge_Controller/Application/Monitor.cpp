/*
 * Monitor.cpp
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include <cmath>
#include "Monitor.h"
#include "Button.h"
#include "Analog.h"
namespace blib
{
    Monitor::Monitor() : mLcdDisplay(Lcd::LcdType::LCD_TYPE_2004, &hi2c1, 0x27 << 1)
    {
        showInit();
        HAL_Delay(1500);

    }
    Monitor::~Monitor()
    {

    }

    // Show when begin
    void Monitor::showInit()
    {
        LOGI();
        mLcdDisplay.clearDisplay();
        mLcdDisplay.displayLine(0, 2, "DO AN TOT NGHIEP");
        mLcdDisplay.displayLine(1, 2, "NAM HOC: 2023-2024");
        mLcdDisplay.displayLine(2, 2, "LOP: DTD61DH");
        mLcdDisplay.displayLine(3, 1, "DAI HOC HANG HAI VN");
    }

    void Monitor::homeScreen()
    {
        LOGI();

        const uint8_t COL = 21;

        char line0[COL] = { 0 };
        char line1[COL] = { 0 };
        char line2[COL] = { 0 };
        char line3[COL] = "Press any button";

        auto &analog = Analog::getInstance();

        snprintf(line0, COL, "%02.1fV %02.1fA %02.1fW", analog.getSolarVoltage(), fabs(analog.getSolarCurrent()),
                fabs(analog.getSolarVoltage() * analog.getSolarCurrent()));
        snprintf(line1, COL, "%02.1fV %02.1fA %02.1fW", analog.getVout(), fabs(analog.getIout()),
                fabs(analog.getVout() * analog.getIout()));
        snprintf(line2, COL, "%d", 1);

        mLcdDisplay.clearDisplay();
        mLcdDisplay.displayLine(0, 2, line0);
        mLcdDisplay.displayLine(1, 2, line1);
        mLcdDisplay.displayLine(2, 2, line2);
        mLcdDisplay.displayLine(3, 1, line3);
    }

    void Monitor::menuScreen()
    {
        if (isNeedRefreshLcd())
        {
            mLcdDisplay.clearDisplay();
            mLcdDisplay.displayLine(0, 1, "1 DISPLAY MODE");
            mLcdDisplay.displayLine(1, 1, "2 SETTING MODE");
            mLcdDisplay.displayLine(2, 1, "3 ABOUT");
            mLcdDisplay.displayLine(3, 1, "1UP 2DOWN 3SEL 4BACK");
            showArrow();
        }
    }
    void Monitor::optionScreen()
    {
        if (isNeedRefreshLcd())
        {
            if (getSetttingMode())
            {
                showSetting();
            }
            else
            {
                showDisplay();
            }
        }
    }

    void Monitor::valueScreen()
    {
        if (isNeedRefreshLcd())
        {
            mLcdDisplay.clearDisplay();
            mLcdDisplay.displayLine(0, 1, "1 DISPLAY MODE");
            mLcdDisplay.displayLine(1, 1, "2 SETTING MODE");
            mLcdDisplay.displayLine(2, 1, "3 ABOUT");
            mLcdDisplay.displayLine(3, 1, "1UP 2DOWN 3SEL 4BACK");
            showArrow();
        }
    }
    // Show when button pressed
    void Monitor::showMenu()
    {
        if (mScreenLevel == Monitor::ScreenLevel::HOME_SCREEN)
        {
            homeScreen();
        }
        else if (mScreenLevel == Monitor::ScreenLevel::MENUS)
        {
            menuScreen();
        }
        else if (mScreenLevel == Monitor::ScreenLevel::OPTIONS)
        {
            optionScreen();
        }
        else
        {
//            valuesScreen();
        }
    }

    void Monitor::showSetting()
    {
        const int COL = 21;
        const int ROW = 13;

        char list[ROW][COL] = { "", "1 SUPPLY ALGORITHM", "2 MODE", "3 MAX BATTERY VOLT",
                "4 MIN BATTERY VOLT", "5 CHARGING CURRENT", "6 COOLING FAN", "7 FAN TRIGGER TEMP",
                "8 SHUTDOWN TEMP", "9 AUTOLOAD", "10BACKLIGHT SLEEP", "11FACTORY RESET" };
        mLcdDisplay.displayLine(0, 1, list[mIndexLine]);
        mLcdDisplay.displayLine(1, 1, list[mIndexLine + 1]);
        mLcdDisplay.displayLine(2, 1, list[mIndexLine + 2]);
        mLcdDisplay.displayLine(3, 1, "1UP 2DOWN 3SEL 4BACK");
        showArrow();
    }
    void Monitor::showDisplay()
    {
        const int COL = 21;
        const int ROW = 13;

        char list[ROW][COL] = { "", "1 DISPLAY1", "2 DISPLAY2", "3 DISPLAY3", "4 MIN BATTERY VOLT",
                "5 CHARGING CURRENT", "6 COOLING FAN", "7 FAN TRIGGER TEMP", "8 SHUTDOWN TEMP",
                "9 AUTOLOAD", "10BACKLIGHT SLEEP", "11FACTORY RESET" };
        mLcdDisplay.displayLine(0, 1, list[mIndexLine]);
        mLcdDisplay.displayLine(1, 1, list[mIndexLine + 1]);
        mLcdDisplay.displayLine(2, 1, list[mIndexLine + 2]);
        mLcdDisplay.displayLine(3, 1, "1UP 2DOWN 3SEL 4BACK");
        showArrow();
    }

    void Monitor::setSettingMode(const bool val)
    {
        mSettingMode = val;
    }
    bool Monitor::getSetttingMode() const
    {
        return mSettingMode;
    }

    void Monitor::jumpIn()
    {
        if (mScreenLevel == ScreenLevel::HOME_SCREEN)
        {
            mScreenLevel = ScreenLevel::MENUS;
            LOGI("Go to Menus");
        }
        else if (mScreenLevel == ScreenLevel::MENUS)
        {
            mScreenLevel = ScreenLevel::OPTIONS;
            LOGI("Go to Options");
        }
        else if (mScreenLevel == ScreenLevel::OPTIONS)
        {
            mScreenLevel = ScreenLevel::VALUES;
            LOGI("Go to Values");
        }
        else
        {
            // Do nothing
        }
    }

    void Monitor::jumpOut()
    {
        if (mScreenLevel == ScreenLevel::HOME_SCREEN)
        {
            // Do nothing
        }
        else if (mScreenLevel == ScreenLevel::MENUS)
        {
            mScreenLevel = ScreenLevel::HOME_SCREEN;
            LOGI("Go back Homescreen");
        }
        else if (mScreenLevel == ScreenLevel::OPTIONS)
        {
            mScreenLevel = ScreenLevel::MENUS;
            LOGI("Go back Menus");
        }
        else if (mScreenLevel == ScreenLevel::VALUES)
        {
            mScreenLevel = ScreenLevel::OPTIONS;
            LOGI("Go back Options");
        }
        else
        {
            // Do nothing
        }
    }

    Monitor::ScreenLevel Monitor::getScreenLevel() const
    {
        return mScreenLevel;
    }
    void Monitor::incrementArrowLine()
    {
        if (mArrowLine == 2)
        {
            mArrowLine = 0;
        }
        else
        {
            mArrowLine++;
        }
    }
    void Monitor::decrementArrowLine()
    {
        if (mArrowLine == 0)
        {
            mArrowLine = 2;
        }
        else
        {
            mArrowLine--;
        }
    }
    uint8_t Monitor::getArrowLine() const
    {
        return mArrowLine;
    }

    void Monitor::setDefaultIndexLine()
    {
        mIndexLine = 1;
    }
    void Monitor::setBackIndexLine()
    {
        mIndexLine = mLastIndexLine;
    }
    // Chi khi co su thay doi ScreenLevel moi cap nhat
    void Monitor::updateLastIndexLine()
    {
        mLastIndexLine = mIndexLine;
    }
    void Monitor::incrementIndexLine()
    {
        uint8_t max = 0;

        if (getScreenLevel() == ScreenLevel::HOME_SCREEN)
        {
            max = 0;
        }
        else if (getScreenLevel() == ScreenLevel::MENUS)
        {
            max = 3;
        }
        else if (getScreenLevel() == ScreenLevel::OPTIONS)
        {
            if (getSetttingMode() == false)    // Display mode
            {
                max = 4;
            }
            else
            {
                max = 12;
            }
        }

        if (mIndexLine == max)
        {
            mIndexLine = 1;
        }
        else
        {
            mIndexLine++;
        }
    }
    void Monitor::decrementIndexLine()
    {
        int max = 0;

        if (getScreenLevel() == ScreenLevel::HOME_SCREEN)
        {
            max = 0;
        }
        else if (getScreenLevel() == ScreenLevel::MENUS)
        {
            max = 3;
        }
        else if (getScreenLevel() == ScreenLevel::OPTIONS)
        {
            if (getSetttingMode() == false)    // Display mode
            {
                max = 4;
            }
            else
            {
                max = 12;
            }
        }

        if (mIndexLine == 1)
        {
            mIndexLine = max;
        }
        else
        {
            mIndexLine--;
        }
    }
    uint8_t Monitor::getIndexLine() const
    {
        return mIndexLine;
    }

    uint8_t Monitor::getLastIndexLine() const
    {
        return mLastIndexLine;
    }

    void Monitor::setSettingLevel(const SettingLevel val)
    {
        uint8_t u8SettingLevel = (uint8_t) val;

        if (u8SettingLevel < 0)
        {
            u8SettingLevel = 0;
        }
        else if (u8SettingLevel >= (uint8_t) SettingLevel::SETTING_LEVEL_MAX)
        {
            u8SettingLevel = 0;
        }

        mSettingLevel = (SettingLevel) u8SettingLevel;
    }
    Monitor::SettingLevel Monitor::getSettingLevel() const
    {
        return mSettingLevel;
    }

    void Monitor::setDisplayLevel(const DisplayLevel val)
    {
        uint8_t u8DisplayLevel = (uint8_t) val;

        if (u8DisplayLevel < 0)
        {
            u8DisplayLevel = 0;
        }
        else if (u8DisplayLevel >= (uint8_t) DisplayLevel::DISPLAY_LEVEL_MAX)
        {
            u8DisplayLevel = 0;
        }

        mDisplayLevel = (DisplayLevel) u8DisplayLevel;
    }
    Monitor::DisplayLevel Monitor::getDisplayLevel() const
    {
        return mDisplayLevel;
    }
    bool Monitor::isNeedRefreshLcd()
    {
        static ScreenLevel lastScreenLevel = ScreenLevel::HOME_SCREEN;
        static uint8_t lastArrLine = 0;

        if (lastScreenLevel != getScreenLevel() || lastArrLine != getArrowLine())
        {
            return true;
        }

        return false;
    }
    void Monitor::showArrow()
    {
        mLcdDisplay.displayLine(0, 0, " ");
        mLcdDisplay.displayLine(1, 0, " ");
        mLcdDisplay.displayLine(2, 0, " ");
        mLcdDisplay.displayLine(mArrowLine, 0, ">");
    }

    void Monitor::impl_DisplayOff()
    {
        mLcdDisplay.clearDisplay();
    }

    void Monitor::impl_TurnOffBacklight()
    {
//        mLcdDisplay.sendData(data)
    }
    void Monitor::impl_DisplayDetectPowerSource()
    {
        mLcdDisplay.clearDisplay();
        mLcdDisplay.displayLine(0, 0, "POWER SOURCE:");
        mLcdDisplay.displayLine(1, 0, "SOLAR PANEL DETECTED");
    }

    void Monitor::showDisplayLevel1()
    {
        LOGI();
    }
    void Monitor::showDisplayLevel2()
    {
        LOGI();
    }
    void Monitor::showDisplayLevel3()
    {
        LOGI();
    }
    void Monitor::showDisplayLevel4()
    {
        LOGI();
    }
    void Monitor::showDisplayChooseSettingMode()
    {
        LOGI("SETTINGS MENU");
        LOGI("--PRESS SELECT--");
    }
    void Monitor::showDisplayFactoryReset()
    {

    }
    void Monitor::showSettingSupplyAlgorithm()
    {
        LOGI();
    }
    void Monitor::showSettingChargerPsuMode()
    {
        LOGI();
    }
    void Monitor::showSettingMaxBatteryVoltage()
    {
        LOGI();
    }
    void Monitor::showSettingMinBatteryVoltage()
    {
        LOGI();
    }
    void Monitor::showSettingChargingCurrent()
    {
        LOGI();
    }
    void Monitor::showSettingCoolingFan()
    {
        LOGI();
    }
    void Monitor::showSettingFanTriggerTemp()
    {
        LOGI();
    }
    void Monitor::showSettingShutdownTemp()
    {
        LOGI();
    }
    void Monitor::showSettingAutoLoadFeature()
    {
        LOGI();
    }
    void Monitor::showSettingBackligthSleep()
    {
        LOGI();
    }
    void Monitor::showSettingFactoryReset()
    {
        LOGI();
    }
}

