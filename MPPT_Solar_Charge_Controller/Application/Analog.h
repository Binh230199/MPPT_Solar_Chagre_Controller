/*
 * Analog.h
 *
 *  Created on: May 14, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef ANALOG_H_
#define ANALOG_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

namespace blib
{
    class Analog : public dp::Singleton<Analog>
    {
        public:
            Analog();
            virtual ~Analog();
            void readAnalog();
            void sampling();
            float getVin() const;
            float getIin() const;
            float getVout() const;
            float getIout() const;
            float getTemp() const;
        private:
            float convertAdcChannel1(uint32_t adcValue);    // Convert adcValue -> Vin
            float convertAdcChannel2(uint32_t adcValue);    // Convert adcValue -> Iin
            float convertAdcChannel3(uint32_t adcValue);    // Convert adcValue -> Vout
            float convertAdcChannel4(uint32_t adcValue);    // Convert adcValue -> Iout
            float convertAdcChannel5(uint32_t adcValue);    // Convert adcValue -> Temperature
        private:
            // Channel 1: VIN
            // Channel 2: IIN
            // Channel 3: VOUT
            // Channel 4: IOUT
            // Channel 5: TEMP
            static const uint8_t NUMBER_OF_CHANNELS = 5U;
            static constexpr float CHANNEL_1_RATIO = 10.0f;
            static constexpr float CHANNEL_2_RATIO = 3.0f;
            static constexpr float CHANNEL_3_RATIO = 5.0f;
            static constexpr float CHANNEL_4_RATIO = 10.0f;
            static constexpr float CHANNEL_5_RATIO = 10.0f;

            static constexpr float ACS_SENSITIVITY = 0.1f;

            uint32_t mAdcValues[NUMBER_OF_CHANNELS] = { 0 };
            ADC_HandleTypeDef *mHadc;
            DMA_HandleTypeDef *mHdmaAdc;

            float mVin;
            float mIin;
            float mVout;
            float mIout;
            float mTemp;
    };
}

#endif /* ANALOG_H_ */
