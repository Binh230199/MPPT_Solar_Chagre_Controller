/*
 * Monitor.cpp
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

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

        snprintf(line0, COL, "%02.1fV %02.1fA %02.1fW", analog.getVin(), analog.getIin(),
                analog.getVin() * analog.getIin());
        snprintf(line1, COL, "%02.1fV %02.1fA %02.1fW", analog.getVout(), analog.getIout(),
                analog.getVout() * analog.getIout());
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
            mLcdDisplay.displayLine(0, 1, "DISPLAY MODE");
            mLcdDisplay.displayLine(1, 1, "SETTING MODE");
            mLcdDisplay.displayLine(2, 1, "ABOUT");
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
        else if (mScreenLevel == Monitor::ScreenLevel::NEXT_1)
        {
            menuScreen();
        }
        else
        {

        }
    }

    void Monitor::showSetting()
    {
        switch (getSettingLevel())
        {
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_0:
                showSettingSupplyAlgorithm();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_1:
                showSettingChargerPsuMode();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_2:
                showSettingMaxBatteryVoltage();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_3:
                showSettingMinBatteryVoltage();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_4:
                showSettingChargingCurrent();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_5:
                showSettingCoolingFan();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_6:
                showSettingFanTriggerTemp();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_7:
                showSettingShutdownTemp();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_8:
                showSettingAutoLoadFeature();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_9:
                showSettingBackligthSleep();
                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_10:
                showSettingFactoryReset();
                break;
            default:
                break;
        }
    }
    void Monitor::showDisplay()
    {
        const Monitor::DisplayLevel displayLevel = getDisplayLevel();
        switch (displayLevel)
        {
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_0:
                // Do not show anything - Maybe show display off
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_1:
                showDisplayLevel1();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_2:
                showDisplayLevel2();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_3:
                showDisplayLevel3();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_4:
                showDisplayLevel4();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_5:
                showDisplayChooseSettingMode();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_6:
                showDisplayFactoryReset();
                break;
            default:
                break;
        }
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
            mScreenLevel = ScreenLevel::NEXT_1;
        }
        else if (mScreenLevel == ScreenLevel::NEXT_1)
        {
            mScreenLevel = ScreenLevel::NEXT_2;
        }
        else if (mScreenLevel == ScreenLevel::NEXT_2)
        {
            mScreenLevel = ScreenLevel::NEXT_3;
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
        else if (mScreenLevel == ScreenLevel::NEXT_1)
        {
            mScreenLevel = ScreenLevel::HOME_SCREEN;
        }
        else if (mScreenLevel == ScreenLevel::NEXT_2)
        {
            mScreenLevel = ScreenLevel::NEXT_1;
        }
        else if (mScreenLevel == ScreenLevel::NEXT_3)
        {
            mScreenLevel = ScreenLevel::NEXT_2;
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
    	mLastArrowLine = mArrowLine;
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
    	mLastArrowLine = mArrowLine;
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

