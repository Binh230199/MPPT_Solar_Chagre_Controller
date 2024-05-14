/*
 * Analog.h
 *
 *  Created on: May 14, 2024
 *      Author: This PC
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
            double getVin() const;
            double getIin() const;
            double getVout() const;
            double getIout() const;
            double getTemp() const;
        private:
            double convertAdcChannel1(uint32_t adcValue);    // Convert adcValue -> Vin
            double convertAdcChannel2(uint32_t adcValue);    // Convert adcValue -> Iin
            double convertAdcChannel3(uint32_t adcValue);    // Convert adcValue -> Vout
            double convertAdcChannel4(uint32_t adcValue);    // Convert adcValue -> Iout
            double convertAdcChannel5(uint32_t adcValue);    // Convert adcValue -> Temperature
        private:
            // Channel 1: VIN
            // Channel 2: IIN
            // Channel 3: VOUT
            // Channel 4: IOUT
            // Channel 5: TEMP
            static const uint8_t NUMBER_OF_CHANNELS = 5U;
            static constexpr double CHANNEL_1_RATIO = 10.0;
            static constexpr double CHANNEL_2_RATIO = 3.0;
            static constexpr double CHANNEL_3_RATIO = 5.0;
            static constexpr double CHANNEL_4_RATIO = 10.0;
            static constexpr double CHANNEL_5_RATIO = 10.0;

            uint32_t mAdcValues[NUMBER_OF_CHANNELS] = { 0 };
            ADC_HandleTypeDef *mHadc;
            DMA_HandleTypeDef *mHdmaAdc;

            double mVin;
            double mIin;
            double mVout;
            double mIout;
            double mTemp;
    };
}

#endif /* ANALOG_H_ */
