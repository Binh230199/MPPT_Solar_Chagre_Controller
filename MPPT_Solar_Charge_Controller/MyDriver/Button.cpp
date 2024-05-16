/*
 * Button.cpp
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "Button.h"
#include "Monitor.h"

namespace blib
{
    Button::Button()
    {

    }
    Button::~Button()
    {

    }
    void Button::setLatestPressedButton(const Button::ButtonName button)
    {
        mLatestPressedButton = button;
    }
    Button::ButtonName Button::getLatestPressedButton() const
    {
        return mLatestPressedButton;
    }
    void Button::handleSignal()
    {
        auto &monitor = Monitor::getInstance();

        // In display mode
        if (monitor.getSetttingMode() == false)
        {
            switch (monitor.getDisplayLevel())
            {
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_0:
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_1:
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_2:
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_3:
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_4:
                    break;

                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_5:
                    if (getLatestPressedButton() == ButtonName::SELECT)
                    {
                        monitor.setSettingMode(true);
                    }
                    break;
                case blib::Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_6:
                    if (monitor.getFactoryReset() == false)
                    {
                        if (getLatestPressedButton() == ButtonName::SELECT)
                        {
                            monitor.setFactoryReset(true);
                        }
                    }
                    else
                    {

                    }

                default:

                    break;
            }

            uint8_t u8DisplayLevel = 0;

            // Press left button - go to previous screen
            if (getLatestPressedButton() == ButtonName::LEFT)
            {
                u8DisplayLevel = (uint8_t) monitor.getDisplayLevel() - 1;
            }
            // Press right buton - go to next screen
            else if (getLatestPressedButton() == ButtonName::RIGHT)
            {
                u8DisplayLevel = (uint8_t) monitor.getDisplayLevel() + 1;
            }

            monitor.setDisplayLevel((Monitor::DisplayLevel) u8DisplayLevel);
        }
        // In setting mode
        else
        {
            switch (monitor.getSettingLevel())
            {
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_0:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_1:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_2:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_3:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_4:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_5:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_6:
                case blib::Monitor::SettingLevel::SETTING_LEVEL_CONFIG_7:
                    break;
                default:
                    break;
            }

            uint8_t u8SettingLevel = 0;

            // Press left button - go to previous screen
            if (getLatestPressedButton() == ButtonName::LEFT)
            {
                u8SettingLevel = (uint8_t) monitor.getSettingLevel() - 1;
            }
            // Press right buton - go to next screen
            else if (getLatestPressedButton() == ButtonName::RIGHT)
            {
                u8SettingLevel = (uint8_t) monitor.getSettingLevel() + 1;
            }

            monitor.setSettingLevel((Monitor::SettingLevel) u8SettingLevel);
        }
    }

}    // namespace blib

