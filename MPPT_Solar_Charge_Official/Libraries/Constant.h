/*
 * Constant.h
 *
 *  Created on: May 18, 2024
 *      Author: This PC
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_
#include <Singleton.h>

//#define TEST
enum class PowerSrc
{
    USB_PORT, SOLAR, BATTERY
};

enum class OutputMode
{
    PSU, CHARGER, INVERTER,
};

class Constant : public blib::dp::Singleton<Constant>
{
    public:
        static constexpr float k_voltage_divider_input = 10.0f;    // Max solar voltage = 30 -> 30/10 = 3V
#ifndef TEST
        static constexpr float k_voltage_divider_output = 5.0f;    // Max battery voltage = 15 -> 15/5 = 3V
#else
        static constexpr float k_voltage_divider_output = 8.0f;    // Max battery voltage = 15 -> 15/5 = 3V
#endif

        static constexpr float k_current_divider_input = 2.0f;    // 5/2 = 2.5V
        static constexpr float k_current_divider_output = 2.0f;    // 5/2 = 2.5V

        static constexpr float k_voltage_solar_max = 30.0f;    // 30V
        float k_voltage_battery_max = 15.0f;    // 15V
        float k_voltage_battery_min = 10.0f;
        float k_current_charging_max = 30.0f;    // Ampere
        static constexpr float k_efficiency_rate = 0.9f;
        static constexpr float k_voltage_dropout = 1.0f;

        static constexpr float k_predict_pwm_margin = 99.5f;
        static const uint32_t k_max_dutycycle = 3600;
        static const uint32_t k_pwm_frequency = 20000;
        static const uint32_t k_pwm_max = 3590;
        static const uint32_t k_pwm_max_limited = 3590;

        float k_temperature_max = 80.0f;    // Celcius
        float k_temperature_turn_on_fan = 50.0f;    // Celcius
        static constexpr float k_current_in_absolute = 31.0f;    // Ampere
        static constexpr float k_current_out_absolute = 50.0f;    // Ampere
        static constexpr float k_electrical_price = 9.5f;    //   USER PARAMETER - Input electrical price per kWh (Dollar/kWh,Euro/kWh,Peso/kWh)
        static constexpr float k_voltage_battery_thresh = 1.5f;    //  CALIB PARAMETER - Power cuts-off when this voltage is reached (Output V)
        static constexpr float k_v_in_system_min = 10.0f;

};
#endif /* CONSTANT_H_ */
