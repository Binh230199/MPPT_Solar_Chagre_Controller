/*
 * Button.cpp
 *
 *  Created on: May 13, 2024
 *      Author: This PC
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

        // In display mode and in display_level_5 and button Select is press => Change to setting mode
        if (monitor.getDisplayLevel() == Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_5
                && monitor.getSetttingMode() == false
                && getLatestPressedButton() == ButtonName::SELECT)
        {
            monitor.setSettingMode(true);
        }
        // In display mode and in display_level_6 and button Select is press => Factory reset enable
        else if (monitor.getDisplayLevel() == Monitor::DisplayLevel::DISPLAY_LEVEL_CONFIG_6
                && monitor.getSetttingMode() == false)
        {
            // Unenable display factory reset
            if (monitor.getFactoryReset() == false
                    && getLatestPressedButton() == ButtonName::SELECT)
            {
                monitor.setFactoryReset(true);
            }
            // Enabled - Press LEFT
            else if (getLatestPressedButton() == ButtonName::LEFT)
            {
                // User select factory reset
                monitor.setConfirmFactoryReset(false);
            }
            // Enabled - Press RIGHT
            else if (getLatestPressedButton() == ButtonName::RIGHT)
            {
                monitor.setConfirmFactoryReset(true);
            }
        }
// In display mode - press any button between 1 and 2
        else if (monitor.getSetttingMode() == false)
        {
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
// In setting mode - press any button between 1 and 2
        else if (monitor.getSetttingMode() == true)
        {
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

