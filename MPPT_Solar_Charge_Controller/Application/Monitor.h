/*
 * Monitor.h
 *
 *  Created on: May 13, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

#include "Lcd.h"

extern I2C_HandleTypeDef hi2c1;

namespace blib
{
    // Monitor is a derived state machine
    class Monitor : public blib::dp::Singleton<Monitor>
    {
        public:
            enum class ScreenLevel
            {
                HOME_SCREEN = 0, NEXT_1 = 1, NEXT_2 = 2, NEXT_3 = 3
            };

            enum class DisplayLevel
            {
                DISPLAY_LEVEL_CONFIG_0 = 0,    // Do not show anything
                DISPLAY_LEVEL_CONFIG_1 = 1,    // Show display config 1
                DISPLAY_LEVEL_CONFIG_2 = 2,    // Show display config 2
                DISPLAY_LEVEL_CONFIG_3 = 3,    // Show display config 3
                DISPLAY_LEVEL_CONFIG_4 = 4,    // Show temperature status
                DISPLAY_LEVEL_CONFIG_5 = 5,    // Show setting menu
                DISPLAY_LEVEL_CONFIG_6 = 6,    // Show factory reset
                DISPLAY_LEVEL_MAX
            };

            enum class SettingLevel
            {
                SETTING_LEVEL_CONFIG_0 = 0,    // Do not show anything
                SETTING_LEVEL_CONFIG_1 = 1,    // Show display config 1
                SETTING_LEVEL_CONFIG_2 = 2,    // Show display config 2
                SETTING_LEVEL_CONFIG_3 = 3,    // Show display config 3
                SETTING_LEVEL_CONFIG_4 = 4,    // Show temperature status
                SETTING_LEVEL_CONFIG_5 = 5,    // Show setting menu
                SETTING_LEVEL_CONFIG_6 = 6,    // Show factory reset
                SETTING_LEVEL_CONFIG_7 = 7,
                SETTING_LEVEL_CONFIG_8 = 8,
                SETTING_LEVEL_CONFIG_9 = 9,
                SETTING_LEVEL_CONFIG_10 = 10,
                SETTING_LEVEL_MAX
            };

            Monitor();
            virtual ~Monitor();

            void showInit();
            void homeScreen();
            void menuScreen();
            void showMenu();
            void showSetting();
            void showDisplay();

            void setSettingMode(const bool val);
            bool getSetttingMode() const;

            void setSettingLevel(const SettingLevel val);
            SettingLevel getSettingLevel() const;

            void setDisplayLevel(const DisplayLevel val);
            DisplayLevel getDisplayLevel() const;

            void jumpIn();
            void jumpOut();
            ScreenLevel getScreenLevel() const;

            void incrementArrowLine();
            void decrementArrowLine();
            uint8_t getArrowLine() const;

        private:
            bool isNeedRefreshLcd();
            void showArrow();
            void showDisplayLevel1();
            void showDisplayLevel2();
            void showDisplayLevel3();
            void showDisplayLevel4();
            void showDisplayChooseSettingMode();
            void showDisplayFactoryReset();

            void showSettingSupplyAlgorithm();
            void showSettingChargerPsuMode();
            void showSettingMaxBatteryVoltage();
            void showSettingMinBatteryVoltage();
            void showSettingChargingCurrent();
            void showSettingCoolingFan();
            void showSettingFanTriggerTemp();
            void showSettingShutdownTemp();
            void showSettingAutoLoadFeature();
            void showSettingBackligthSleep();
            void showSettingFactoryReset();

        private:
            volatile ScreenLevel mScreenLevel = ScreenLevel::HOME_SCREEN;
            volatile bool mSettingMode = false;    // false - display mode, true - setting mode
            volatile uint8_t mArrowLine = 0;    // Mui ten chi dong nao, thi dang o dong do
            volatile SettingLevel mSettingLevel = SettingLevel::SETTING_LEVEL_CONFIG_0;    //
            volatile DisplayLevel mDisplayLevel = DisplayLevel::DISPLAY_LEVEL_CONFIG_0;

            Lcd mLcdDisplay;    // lcd display monitor
    };

}

#endif /* MONITOR_H_ */
