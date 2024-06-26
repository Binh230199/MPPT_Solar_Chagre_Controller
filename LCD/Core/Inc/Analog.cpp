/*
 * Analog.cpp
 *
 *  Created on: May 14, 2024
 *      Author: binhhv.23.1.99@gmail.com
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

    float Analog::getVin() const
    {
        return mVin;
    }
    float Analog::getIin() const
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
        mVin = convertAdcChannel1(mAdcValues[0]);
        mIin = convertAdcChannel2(mAdcValues[1]);
        mVout = convertAdcChannel3(mAdcValues[2]);
        mIout = convertAdcChannel4(mAdcValues[3]);
        mTemp = convertAdcChannel5(mAdcValues[4]);

//        LOGI("mVin : [%.2f] V", mVin);
//        LOGI("mIin : [%.2f] A", mIin);
//        LOGI("mVout : [%.2f] V", mVout);
//        LOGI("mIout : [%.2f] A", mIout);
//        LOGI("mTemp : [%.2f] C", mTemp);
    }

    float Analog::convertAdcChannel1(uint32_t adcValue)    // Convert adcValue -> Vin
    {
        return CHANNEL_1_RATIO * ((float) adcValue / 4095) * 3.3;
    }

    float Analog::convertAdcChannel2(uint32_t adcValue)    // Convert adcValue -> Iin
    {
        float voltage = CHANNEL_2_RATIO * ((float) adcValue / 4095) * 3.3;
        float current = (voltage - (5 * 0.5)) / ACS_SENSITIVITY;    // Vic = 5V

        return current;
    }
    float Analog::convertAdcChannel3(uint32_t adcValue)    // Convert adcValue -> Vout
    {
        return CHANNEL_3_RATIO * ((float) adcValue / 4095) * 3.3;
    }
    float Analog::convertAdcChannel4(uint32_t adcValue)    // Convert adcValue -> Iout
    {
        float voltage = CHANNEL_4_RATIO * ((float) adcValue / 4095) * 3.3;
        float current = (voltage - (5 * 0.5)) / ACS_SENSITIVITY;    // Vic = 5V

        return current;
    }
    float Analog::convertAdcChannel5(uint32_t adcValue)    // Convert adcValue -> Temperature NTC 10k
    {
        return CHANNEL_5_RATIO * ((float) adcValue / 4095) * 3.3;
    }
}
// namespace blib

