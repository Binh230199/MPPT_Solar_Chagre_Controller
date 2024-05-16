/*
 * Monitor.cpp
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "Monitor.h"
#include "Button.h"

namespace blib
{
    Monitor::Monitor() : mLcdDisplay(Lcd::LcdType::LCD_TYPE_2004, &hi2c1, 0x7F)
    {
        showInit();
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
        mLcdDisplay.displayLine(0, 1, "DAI HOC HANG HAI VN");
        HAL_Delay(1500);
    }

    // Show when button pressed
    void Monitor::showMenu()
    {
        //TODO: need to add check is permission shown

        // Check whether in setting mode or not
        if (getSetttingMode() == true)
        {
            showSetting();
        }
        else    // Not in setting mode - Display mode
        {
            showDisplay();
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

    void Monitor::setFactoryReset(const bool val)
    {
        mFactoryResetEnable = val;
    }
    bool Monitor::getFactoryReset() const
    {
        return mFactoryResetEnable;
    }
    void Monitor::setConfirmFactoryReset(const bool val)
    {
        mConfirmFactoryReset = val;
    }
    bool Monitor::getConfirmFactoryReset() const
    {
        return mConfirmFactoryReset;
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
        if (getFactoryReset() == false)
        {
            LOGI("FACTORY RESET");
            LOGI("--PRESS SELECT--");
        }
        else
        {
            if (getConfirmFactoryReset() == false)
            {
                LOGI("ARE YOU SURE?");
                LOGI(" >NO   >YES");
            }
            else
            {
                LOGI("FACTORY RESET");
                LOGI("SUCCESSFULLY");

                HAL_Delay(1500);

                setConfirmFactoryReset(false);
                setFactoryReset(false);

                // Go to setting mode - show supply algorithm screen
                setSettingMode(true);
                setSettingLevel(SettingLevel::SETTING_LEVEL_CONFIG_1);    // TODO: Check correct screen
            }
        }
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

