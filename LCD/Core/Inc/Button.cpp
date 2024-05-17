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

        if (monitor.getScreenLevel() == Monitor::ScreenLevel::HOME_SCREEN)
        {
            monitor.jumpIn();
        }
        else if (monitor.getScreenLevel() == Monitor::ScreenLevel::NEXT_1)
        {
            if (getLatestPressedButton() == ButtonName::UP)
            {
                monitor.decrementArrowLine();
            }
            else if (getLatestPressedButton() == ButtonName::DOWN)
            {
                monitor.incrementArrowLine();
            }
            else if (getLatestPressedButton() == ButtonName::SEL)
            {
                monitor.jumpIn();
            }
            else if (getLatestPressedButton() == ButtonName::BACK)
            {
                monitor.jumpOut();
            }
            else
            {

            }
        }
        else if (monitor.getScreenLevel() == Monitor::ScreenLevel::NEXT_2)
        {
            if (getLatestPressedButton() == ButtonName::UP)
            {
                monitor.decrementArrowLine();
            }
            else if (getLatestPressedButton() == ButtonName::DOWN)
            {
                monitor.incrementArrowLine();
            }
            else if (getLatestPressedButton() == ButtonName::SEL)
            {
                monitor.jumpIn();
            }
            else if (getLatestPressedButton() == ButtonName::BACK)
            {
                monitor.jumpOut();
            }
            else
            {

            }
        }

    }

}    // namespace blib
