/*
 * ChargeControl.cpp
 *
 *  Created on: May 15, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "ChargeControl.h"

namespace blib
{

    ChargeControl::ChargeControl()
    {

    }
    ChargeControl::~ChargeControl()
    {

    }
    void ChargeControl::run()
    {

    }

    void ChargeControl::setBuckEnable(const bool val)
    {
        mBuckEnable = val;
    }
    bool ChargeControl::getBuckEnable() const
    {
        return mBuckEnable;
    }
    void ChargeControl::setMpptMode(const bool val)
    {
        mMpptMode = val;
    }
    bool ChargeControl::getMpptMode() const
    {
        return mMpptMode;
    }
    // Enable Mppt Buck converter
    void ChargeControl::buckEnable()
    {
        LOGI();
        setBuckEnable(true);
//        HAL_GPIO_WritePin(BUCK_ENABLE_GPIO_Port, BUCK_ENABLE_Pin, GPIO_PIN_SET);
//        HAL_GPIO_WritePin(LED_INDICATE_GPIO_Port, LED_INDICATE_Pin, GPIO_PIN_SET);
    }
    // Disable Mppt Buck converter
    void ChargeControl::buckDisable()
    {
        LOGI();
        setBuckEnable(false);
//        HAL_GPIO_WritePin(BUCK_ENABLE_GPIO_Port, BUCK_ENABLE_Pin, GPIO_PIN_RESET);
//        HAL_GPIO_WritePin(LED_INDICATE_GPIO_Port, LED_INDICATE_Pin, GPIO_PIN_RESET);
        mPwm = 0;
    }
    void ChargeControl::predictPwm()
    {

    }
    void ChargeControl::generatePwm()
    {

    }

}    // namespace blib

