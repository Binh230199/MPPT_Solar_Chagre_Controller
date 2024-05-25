/*
 * Analog.cpp
 *
 *  Created on: May 14, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#include "Analog.h"
#include <cmath>
namespace blib
{
    Analog::Analog() : mHadc(&hadc1), mHdmaAdc(&hdma_adc1)
    {
        sampling();
    }

    Analog::~Analog()
    {
        HAL_ADC_Stop_DMA(mHadc);
    }

    // Lay mau ADC bang DMA
    void Analog::sampling()
    {
        HAL_ADC_Start_DMA(mHadc, mAdcValues, NUMBER_OF_CHANNELS);
    }

    float Analog::getSolarVoltage() const
    {
        return mVin;
    }
    float Analog::getSolarCurrent() const
    {
        return mIin;
    }
    float Analog::getVout() const
    {
        return mVout;
    }
    float Analog::getIout() const
    {
        return mIout;
    }
    float Analog::getTemp() const
    {
        return mTemp;
    }

    void Analog::readAnalog()
    {
        mVin = calSolarVoltage(mAdcValues[2]);
        mIin = calSolarCurrent(mAdcValues[3]);
        mVout = calBatteryVoltage(mAdcValues[4]);
        mIout = calBatteryCurrent(mAdcValues[0]);
#ifndef TEST
        mTemp = calTemperature(mAdcValues[1]);
#else
        mTemp = 45.0f;
#endif

        // Power Source Detection
        if (mVin <= 3 && mVout < 3)
        {
            mInputSource = PowerSrc::USB_PORT;
        }
        else if (mVin > mVout)
        {
            mInputSource = PowerSrc::SOLAR;
        }
        else if (mVin < mVout)
        {
            mInputSource = PowerSrc::BATTERY;
        }
        else
        {

        }

        mPin = mVin * mIin;
        mPout = mVin * mIout;    // Cong suat ra tinh bang gia tri do duoc cua cam bien
        mOutputDeviation = (mVout / Constant::getInstance().k_voltage_battery_max) * 100.0f;

        mBatteryPercent = ((mVout - Constant::getInstance().k_voltage_battery_min)
                / (Constant::getInstance().k_voltage_battery_max
                        - Constant::getInstance().k_voltage_battery_min)) * 100;
    }

    float Analog::calSolarVoltage(uint32_t adcValue)    // Convert adcValue -> Vin
    {
        return Constant::getInstance().k_voltage_divider_input * ((float) adcValue / 4095) * 3.3;
    }

    float Analog::calSolarCurrent(uint32_t adcValue)    // Convert adcValue -> Iin
    {
        float voltage = Constant::getInstance().k_current_divider_input * ((float) adcValue / 4095)
                * 3.3;
        return abs(((5 * 0.5) - voltage) / ACS_SENSITIVITY);    // Vic = 5V
    }
    float Analog::calBatteryVoltage(uint32_t adcValue)    // Convert adcValue -> Vout
    {
        return Constant::getInstance().k_voltage_divider_output * ((float) adcValue / 4095) * 3.3;
    }
    float Analog::calBatteryCurrent(uint32_t adcValue)    // Convert adcValue -> Iout
    {
        float voltage = Constant::getInstance().k_current_divider_output * ((float) adcValue / 4095)
                * 3.3;
        return abs(((5 * 0.5) - voltage) / ACS_SENSITIVITY);    // Vic = 5V
    }
    float Analog::calTemperature(uint32_t adcValue)    // Convert adcValue -> Temperature NTC 10k
    {
        const double A = 0.003354016f;
        const double B = 0.0002569850f;
        const double C = 0.000002620131f;

        float voltage = ((float) adcValue / 4095) * 3.3;
        float resistance = (3.3f * 10000.0f / voltage) - 10000.0f;

        float logResistance = log(resistance);
        float reciprocalTemperature = A + (B * logResistance)
                + (C * logResistance * logResistance * logResistance);

        float temperature = 1.0f / reciprocalTemperature;
        return temperature;
    }
}
// namespace blib

