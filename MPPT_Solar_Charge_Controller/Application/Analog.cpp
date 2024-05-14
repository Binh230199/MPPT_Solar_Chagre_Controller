/*
 * Analog.cpp
 *
 *  Created on: May 14, 2024
 *      Author: This PC
 */

#include "Analog.h"

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

    double Analog::getVin() const
    {
        return mVin;
    }
    double Analog::getIin() const
    {
        return mIin;
    }
    double Analog::getVout() const
    {
        return mVout;
    }
    double Analog::getIout() const
    {
        return mIout;
    }
    double Analog::getTemp() const
    {
        return mTemp;
    }

    void Analog::readAnalog()
    {
        mVin = convertAdcChannel1(mAdcValues[0]);
        mIin = convertAdcChannel2(mAdcValues[1]);
        mVout = convertAdcChannel3(mAdcValues[2]);
        mIout = convertAdcChannel4(mAdcValues[3]);
        mTemp = convertAdcChannel5(mAdcValues[4]);

        LOGI("mVin : [%.2f] V", mVin);
        LOGI("mIin : [%.2f] A", mIin);
        LOGI("mVout : [%.2f] V", mVout);
        LOGI("mIout : [%.2f] A", mIout);
        LOGI("mTemp : [%.2f] C", mTemp);
    }

    double Analog::convertAdcChannel1(uint32_t adcValue)    // Convert adcValue -> Vin
    {
        return CHANNEL_1_RATIO * ((double) adcValue / 4095) * 3.3;
    }

    double Analog::convertAdcChannel2(uint32_t adcValue)    // Convert adcValue -> Iin
    {
        return CHANNEL_2_RATIO * ((double) adcValue / 4095) * 3.3;
    }
    double Analog::convertAdcChannel3(uint32_t adcValue)    // Convert adcValue -> Vout
    {
        return CHANNEL_3_RATIO * ((double) adcValue / 4095) * 3.3;
    }
    double Analog::convertAdcChannel4(uint32_t adcValue)    // Convert adcValue -> Iout
    {
        return CHANNEL_4_RATIO * ((double) adcValue / 4095) * 3.3;
    }
    double Analog::convertAdcChannel5(uint32_t adcValue)    // Convert adcValue -> Temperature
    {
        return CHANNEL_5_RATIO * ((double) adcValue / 4095) * 3.3;
    }
}
// namespace blib

