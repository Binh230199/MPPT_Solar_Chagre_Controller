/*
 * Monitor.h
 *
 *  Created on: May 13, 2024
 *      Author: This PC
 */

#ifndef MONITOR_H_
#define MONITOR_H_

#include <string>

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"

// Add log library
#include "Log.h"

namespace blib
{
    // Monitor is a derived state machine
    class Monitor : public blib::dp::Singleton<Monitor>
    {
        public:
            enum class DisplayLevel
            {
                DISPLAY_LEVEL_CONFIG_0 = 0,    // Do not show anything
                DISPLAY_LEVEL_CONFIG_1 = 1,    // Show display config 1
                DISPLAY_LEVEL_CONFIG_2 = 2,    // Show display config 2
                DISPLAY_LEVEL_CONFIG_3 = 3,    // Show display config 3
                DISPLAY_LEVEL_CONFIG_4 = 4,    // Show temperature status
                DISPLAY_LEVEL_CONFIG_5 = 5,    // Show setting menu
                DISPLAY_LEVEL_CONFIG_6 = 6,    // Show factory reset
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
            };

            Monitor();
            virtual ~Monitor();

            void showInit();
            void showMenu();
            void showSetting();
            void showDisplay();

            void setSettingMode(const bool val);
            bool getSetttingMode() const;

            void setSettingLevel(const SettingLevel val);
            SettingLevel getSettingLevel() const;

            void setDisplayLevel(const DisplayLevel val);
            DisplayLevel getDisplayLevel() const;

            void setFactoryReset(const bool val);
            bool getFactoryReset() const;
            void setConfirmFactoryReset(const bool val);
            bool getConfirmFactoryReset() const;
        private:
            void showDisplayLevel1();
            void showDisplayLevel2();
            void showDisplayLevel3();
            void showDisplayLevel4();
            void showScreenChooseSettingMode();
            void showScreenFactoryReset();

            void showSettingL();

        private:
            bool mSettingMode = false;    // false - display mode, true - setting mode
            SettingLevel mSettingLevel = SettingLevel::SETTING_LEVEL_CONFIG_0;    //
            DisplayLevel mDisplayLevel = DisplayLevel::DISPLAY_LEVEL_CONFIG_0;

            // Factory reset
            bool mFactoryResetEnable = false;    // false = disable, true = enable
            bool mConfirmFactoryReset = false;    // false = no, true = yes
    };

}

#endif /* MONITOR_H_ */
