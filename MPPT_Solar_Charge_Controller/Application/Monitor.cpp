/*
 * Monitor.cpp
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#include "Monitor.h"
#include "Button.h"

namespace blib
{
    Monitor::Monitor()
    {
        showInit();
    }
    Monitor::~Monitor()
    {

    }

    // Show when begin
    void Monitor::showInit()
    {
        LOGI("MPPT INITIALIZED");
        LOGI("FIRMWARE V1.00");
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

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_1:

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_2:

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_3:

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_4:

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_5:

                break;
            case Monitor::SettingLevel::SETTING_LEVEL_CONFIG_6:

                break;
            default:
                break;
        }
    }
    void Monitor::showDisplay()
    {
        switch (getDisplayLevel())
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
                showScreenChooseSettingMode();
                break;
            case Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_6:
                showScreenFactoryReset();
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
        mSettingLevel = val;
    }
    Monitor::SettingLevel Monitor::getSettingLevel() const
    {
        return mSettingLevel;
    }

    void Monitor::setDisplayLevel(const DisplayLevel val)
    {
        mDisplayLevel = val;
    }
    Monitor::DisplayLevel Monitor::getDisplayLevel() const
    {
        return mDisplayLevel;
    }

    void Monitor::showDisplayLevel1()
    {

    }
    void Monitor::showDisplayLevel2()
    {

    }
    void Monitor::showDisplayLevel3()
    {

    }
    void Monitor::showDisplayLevel4()
    {

    }
    void Monitor::showScreenChooseSettingMode()
    {
        LOGI("SETTINGS MENU");
        LOGI("--PRESS SELECT--");
    }
    void Monitor::showScreenFactoryReset()
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
}

