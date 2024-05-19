/*
 * TestLcd.h
 *
 *  Created on: May 17, 2024
 *      Author: This PC
 */

#ifndef TESTLCD_H_
#define TESTLCD_H_

// Add design patterns template library
#include "Singleton.h"
#include "StateMachineBase.h"
#include "Analog.h"
#include "DeviceProtection.h"
#include "ChargeControl.h"
#include "Button.h"
#include "Constant.h"
// Add log library
#include "Log.h"

#include "Lcd.h"

extern I2C_HandleTypeDef hi2c1;
namespace blib
{
    class LcdSimulate;

    using Callback = void (LcdSimulate::*)();

    class LcdSimulate : public dp::Singleton<LcdSimulate>
    {
        public:
            LcdSimulate() : mLcd(Lcd::LcdType::LCD_TYPE_2004, &hi2c1, 0x27 << 1)
            {
                mLcd.clearDisplay();
                mLcd.displayLine(0, 1, "DO AN TOT NGHIEP");
                mLcd.displayLine(1, 1, "NAM HOC: 2023-2024");
                mLcd.displayLine(2, 1, "LOP: DTD61DH");
                mLcd.displayLine(3, 1, "DAI HOC HANG HAI VN");
                mLcd.clearDisplay();
                HAL_Delay(2000);
                mCallback = &LcdSimulate::impl_1_HomeScreen;
            }
            virtual ~LcdSimulate()
            {

            }
            void run()
            {
                (LcdSimulate::getInstance().*mCallback)();
            }
            void impl_1_HomeScreen()
            {
                auto &button = Button::getInstance();
                auto &analog = Analog::getInstance();

                char line0[21] = { 0 }, line1[21] = { 0 }, line2[21] = { 0 }, line3[21] = { 0 };

                snprintf(line0, 21, "I:%2.1fV %2.1fA %2.1fW", analog.mVin, analog.mIin,
                        analog.mPin);
                snprintf(line1, 21, "O:%2.1fV %2.1fA %2.1fW", analog.mVout, analog.mIout,
                        analog.mPout);
                if (analog.mInputSource == PowerSrc::USB_PORT)
                {
                    snprintf(line2, 21, "Src: USB");
                }
                else if (analog.mInputSource == PowerSrc::SOLAR)
                {
                    snprintf(line2, 21, "Src: SOLAR");
                }
                else if (analog.mInputSource == PowerSrc::BATTERY)
                {
                    snprintf(line2, 21, "Src: BAT [%.1f%%]", analog.mBatteryPercent);
                }

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                mLcd.displayLine(0, 0, line0);
                mLcd.displayLine(1, 0, line1);
                mLcd.displayLine(2, 0, line2);
                mLcd.displayLine(3, 2, "Press any button");

                // Nhan nut bat ky thi se chuyen sang man hinh menu
                if (button.getLatestPressedButton() == Button::ButtonName::UP
                        || button.getLatestPressedButton() == Button::ButtonName::DOWN
                        || button.getLatestPressedButton() == Button::ButtonName::SEL
                        || button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go to menu screen");
                    mCallback = &LcdSimulate::impl_2_MenuScreen;
                    button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
                }
            }

            void impl_2_MenuScreen()
            {
                auto &button = Button::getInstance();

                static int arrowLine = 0;

                // Nhan nut UP -> mui ten di len
                if (button.getLatestPressedButton() == Button::ButtonName::UP)
                {
                    if (arrowLine == 0)
                    {
                        arrowLine = 2;
                    }
                    else
                    {
                        arrowLine--;
                    }
                }
                // Nhan nut DOWN ->  mui ten di xuong
                else if (button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    if (arrowLine == 2)
                    {
                        arrowLine = 0;
                    }
                    else
                    {
                        arrowLine++;
                    }
                }
                // Nhan nut BACK ->  ve trang truoc (homescreen)
                else if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to homescreen");
                    mCallback = &LcdSimulate::impl_1_HomeScreen;
                    arrowLine = 0;
                }
                // Nhan nut SEL ->  ve trang truoc (homescreen)
                else if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    // Chon DISPLAY MODE
                    if (arrowLine == 0)
                    {
                        LOGI("Go to Display Menu");
                        mCallback = &LcdSimulate::impl_3_DisplayScroll;
                    }
                    // Chon SETTING MODE
                    else if (arrowLine == 1)
                    {
                        LOGI("Go to Setting Menu");
                        mCallback = &LcdSimulate::impl_3_SettingScroll;
                    }
                    // Chon ABOUT
                    else if (arrowLine == 2)
                    {
                        LOGI("Go to About");
                        mCallback = &LcdSimulate::impl_3_AboutScreen;
                    }
                    //Erorr
                    else
                    {

                    }
                }
                else
                {

                }

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                mLcd.displayLine(0, 1, "1 DISPLAY MODE");
                mLcd.displayLine(1, 1, "2 SETTING MODE");
                mLcd.displayLine(2, 1, "3 ABOUT");
                mLcd.displayLine(3, 0, "1UP 2DOWN 3SEL 4BACK");
                mLcd.displayLine(arrowLine, 0, ">");

                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_AboutScreen()
            {
                auto &button = Button::getInstance();

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                mLcd.displayLine(0, 0, "MPPT SOLAR CHARGER");
                mLcd.displayLine(1, 0, "FIRMWARE VER: 1.0.0");
                mLcd.displayLine(2, 0, "CONTACT:09123123123");
                mLcd.displayLine(3, 15, "4BACK");

                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    mCallback = &LcdSimulate::impl_2_MenuScreen;
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_DisplayScroll()
            {
                const int COL = 21;
                const int ROW = 5;

                char list[ROW][COL] = { "", "1 DISPLAY VIEW 1", "2 DISPLAY VIEW 2",
                        "3 DISPLAY VIEW 3", "4 DISPLAY VIEW 4" };

                static int arrowLine = 0;
                static int mIndexLine = 1;

                auto &button = Button::getInstance();
                // Nhan nut UP -> mui ten di len
                if (button.getLatestPressedButton() == Button::ButtonName::UP)
                {
                    if (mIndexLine == 1)
                    {
                        mIndexLine = ROW - 1;
                        arrowLine = 2;
                    }
                    else
                    {
                        mIndexLine--;
                    }

                    if (mIndexLine == 1 || mIndexLine == ROW - 2)
                    {
                        if (arrowLine == 0)
                        {
                            arrowLine = 2;
                        }
                        else
                        {
                            arrowLine--;
                        }
                    }
                }
                // Nhan nut DOWN ->  mui ten di xuong
                else if (button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    // Dong bo > voi index
                    if (mIndexLine == 1 || mIndexLine == ROW - 2)
                    {
                        if (arrowLine == 2)
                        {
                            arrowLine = 0;
                        }
                        else
                        {
                            arrowLine++;
                        }
                    }

                    if (mIndexLine == ROW - 1)
                    {
                        mIndexLine = 1;
                        arrowLine = 0;
                    }
                    else
                    {
                        mIndexLine++;
                    }
                }
                // Nhan nut BACK ->  ve trang truoc (menuscreen)
                else if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Menu screen");
                    mCallback = &LcdSimulate::impl_2_MenuScreen;    //
                    arrowLine = 0;
                    mIndexLine = 1;
                }
                // Nhan nut SEL
                else if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    // Chon DISPLAY MODE
                    if (mIndexLine == 1)
                    {
                        LOGI("Go to Display Config 1");
                        mCallback = &LcdSimulate::impl_3_1_DisplayConfig1;
                    }
                    // Chon SETTING MODE
                    else if (mIndexLine == 2)
                    {
                        LOGI("Go to Display Config 2");
                        mCallback = &LcdSimulate::impl_3_1_DisplayConfig2;
                    }
                    // Chon ABOUT
                    else if (mIndexLine == 3)
                    {
                        LOGI("Go to Display Config 3");
                        mCallback = &LcdSimulate::impl_3_1_DisplayConfig3;
                    }
                    else if (mIndexLine == 4)
                    {
                        LOGI("Go to Display Config 4");
                        mCallback = &LcdSimulate::impl_3_1_DisplayConfig4;
                    }
                    //Erorr
                    else
                    {

                    }
                }
                else
                {

                }

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }

                if (mIndexLine == 1)
                {
                    mLcd.displayLine(0, 1, list[mIndexLine]);
                    mLcd.displayLine(1, 1, list[mIndexLine + 1]);
                    mLcd.displayLine(2, 1, list[mIndexLine + 2]);
                }
                else if (mIndexLine == ROW - 1)
                {
                    mLcd.displayLine(0, 1, list[mIndexLine - 2]);
                    mLcd.displayLine(1, 1, list[mIndexLine - 1]);
                    mLcd.displayLine(2, 1, list[mIndexLine]);
                }
                else
                {
                    mLcd.displayLine(0, 1, list[mIndexLine - 1]);
                    mLcd.displayLine(1, 1, list[mIndexLine]);
                    mLcd.displayLine(2, 1, list[mIndexLine + 1]);
                }

                mLcd.displayLine(3, 0, "1UP 2DOWN 3SEL 4BACK");
                mLcd.displayLine(arrowLine, 0, ">");
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_SettingScroll()
            {
                // Trong che do setting thi dung sac
                ChargeControl::getInstance().mChargePause = true;

                const int COL = 21;
                const int ROW = 12;

                char list[ROW][COL] = { "", "1 SUPPLY ALGORITHM", "2 MODE", "3 MAX BATTERY VOLT",
                        "4 MIN BATTERY VOLT", "5 CHARGING CURRENT", "6 COOLING FAN",
                        "7 FAN TRIGGER TEMP", "8 SHUTDOWN TEMP", "9 AUTOLOAD", "10BACKLIGHT SLEEP",
                        "11FACTORY RESET" };
                static int arrowLine = 0;
                static int mIndexLine = 1;

                auto &button = Button::getInstance();
                // Nhan nut UP -> mui ten di len
                if (button.getLatestPressedButton() == Button::ButtonName::UP)
                {
                    /*
                     Feature: Dong bo giua index va mui ten '>'
                     - Mui ten phu thuoc vao index.
                     - Moi lan, chi hien thi 3 tuy chon, nen index va mui ten phai dong bo voi nhau
                     */
                    if (mIndexLine == 1)
                    {
                        mIndexLine = ROW - 1;
                        arrowLine = 2;
                    }
                    else
                    {
                        mIndexLine--;
                    }

                    if (mIndexLine == 1 || mIndexLine == ROW - 2)
                    {
                        if (arrowLine == 0)
                        {
                            arrowLine = 2;
                        }
                        else
                        {
                            arrowLine--;
                        }
                    }
                }
                // Nhan nut DOWN ->  mui ten di xuong
                else if (button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    if (mIndexLine == 1 || mIndexLine == ROW - 2)
                    {
                        if (arrowLine == 2)
                        {
                            arrowLine = 0;
                        }
                        else
                        {
                            arrowLine++;
                        }
                    }

                    if (mIndexLine == ROW - 1)
                    {
                        mIndexLine = 1;
                        arrowLine = 0;
                    }
                    else
                    {
                        mIndexLine++;
                    }
                }
                // Nhan nut BACK ->  ve trang truoc (menuscreen)
                else if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Menu screen");
                    mCallback = &LcdSimulate::impl_2_MenuScreen;    //
                    arrowLine = 0;
                    mIndexLine = 1;

                    // Thoat che do setting thi tiep tuc sac
                    ChargeControl::getInstance().mChargePause = false;
                }
                // Nhan nut SEL
                else if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    // Chon DISPLAY MODE
                    if (mIndexLine == 1)
                    {
                        LOGI("Go to Supply Algorithm");
                        mCallback = &LcdSimulate::impl_3_2_SupplyAlgorithm;
                    }
                    // Chon SETTING MODE
                    else if (mIndexLine == 2)
                    {
                        LOGI("Go to Charge mode");
                        mCallback = &LcdSimulate::impl_3_2_ChargeMode;
                    }
                    // Chon ABOUT
                    else if (mIndexLine == 3)
                    {
                        LOGI("Go to Max battery voltage");
                        mCallback = &LcdSimulate::impl_3_2_MaxBatteryVolt;
                    }
                    else if (mIndexLine == 4)
                    {
                        LOGI("Go to Min battery voltage");
                        mCallback = &LcdSimulate::impl_3_2_MinBatteryVolt;
                    }
                    else if (mIndexLine == 5)
                    {
                        LOGI("Go to Charging current");
                        mCallback = &LcdSimulate::impl_3_2_ChargingCurrent;
                    }
                    else if (mIndexLine == 6)
                    {
                        LOGI("Go to Cooling fan");
                        mCallback = &LcdSimulate::impl_3_2_CoolingFan;
                    }
                    else if (mIndexLine == 7)
                    {
                        LOGI("Go to Fan trigger temp");
                        mCallback = &LcdSimulate::impl_3_2_FanTriggerTemp;
                    }
                    else if (mIndexLine == 8)
                    {
                        LOGI("Go to Shutdown temp");
                        mCallback = &LcdSimulate::impl_3_2_ShutdownTemp;
                    }
                    else if (mIndexLine == 9)
                    {
                        LOGI("Go to Autoload config");
                        mCallback = &LcdSimulate::impl_3_2_AutoloadCfg;
                    }
                    else if (mIndexLine == 10)
                    {
                        LOGI("Go to Backlight");
                        mCallback = &LcdSimulate::impl_3_2_Backlight;
                    }
                    else if (mIndexLine == 11)
                    {
                        LOGI("Go to Factory reset");
                        mCallback = &LcdSimulate::impl_3_2_FactoryReset;
                    }
                    //Erorr
                    else
                    {

                    }
                }
                else
                {

                }

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                if (mIndexLine == 1)
                {
                    mLcd.displayLine(0, 1, list[mIndexLine]);
                    mLcd.displayLine(1, 1, list[mIndexLine + 1]);
                    mLcd.displayLine(2, 1, list[mIndexLine + 2]);
                }
                else if (mIndexLine == ROW - 1)
                {
                    mLcd.displayLine(0, 1, list[mIndexLine - 2]);
                    mLcd.displayLine(1, 1, list[mIndexLine - 1]);
                    mLcd.displayLine(2, 1, list[mIndexLine]);
                }
                else
                {
                    mLcd.displayLine(0, 1, list[mIndexLine - 1]);
                    mLcd.displayLine(1, 1, list[mIndexLine]);
                    mLcd.displayLine(2, 1, list[mIndexLine + 1]);
                }

                mLcd.displayLine(3, 0, "1UP 2DOWN 3SEL 4BACK");
                mLcd.displayLine(arrowLine, 0, ">");

                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_1_DisplayConfig1()
            {
//                char line0[21] = { 0 }, line1[21] = { 0 }, line2[21] = { 0 }, line3[21] = { 0 };
//
//                snprintf(line0, 21, "%03.1W %04.2fWh ", 25.1);    //P:025.1W A:0003.4Wh
//
//                if (isBatteryPlugin)
//                {
//                    snprintf(line1, 21, "Bat: %03.1%%");    // Bat:100.0%
//                }
//                else
//                {
//                    snprintf(line1, 21, "Bat: NOBAT");    // Bat: NOBAT
//                }
//
//                snprintf(line2, 21, "Iout: %03.1fA", 5.1f);    // Iout: 005.1A
//
//                //mLcd.clearDisplay();
//                mLcd.displayLine(0, 0, line0);
//                mLcd.displayLine(1, 0, line1);
//                mLcd.displayLine(2, 0, line2);
//                mLcd.displayLine(3, 0, "1UP 2DOWN 3SEL 4BACK");
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Display screen");
                    mCallback = &LcdSimulate::impl_3_DisplayScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_1_DisplayConfig2()
            {
//                char line0[21] = { 0 }, line1[21] = { 0 }, line2[21] = { 0 }, line3[21] = { 0 };
//
//                snprintf(line0, 21, "%03.1W %04.2fWh ", 25.1);    //P:025.1W A:0003.4Wh
//                snprintf(line2, 21, "Iout: %03.1fA", 5.1f);    // Iout: 005.1A
//
//                //mLcd.clearDisplay();
//                mLcd.displayLine(0, 0, line0);
//                mLcd.displayLine(1, 0, line1);
//                mLcd.displayLine(2, 0, line2);
//                mLcd.displayLine(3, 0, "1UP 2DOWN 3SEL 4BACK");
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Display screen");
                    mCallback = &LcdSimulate::impl_3_DisplayScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_1_DisplayConfig3()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Display screen");
                    mCallback = &LcdSimulate::impl_3_DisplayScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_1_DisplayConfig4()
            {
//                char line0[21] = { 0 }, line1[21] = { 0 }, line2[21] = { 0 }, line3[21] = { 0 };
//
//                snprintf(line0, 21, "%s", "Temp: %.2f\u00B0C", Analog::getInstance().getTemp());    //Temperature
//                snprintf(line1, 21, "%s", "Fan: %s", (isFanStatus == RUN) ? "RUN" : "OFF");    //Fan: RUN
//                snprintf(line2, 21, "Thres:[%.2f-%.2f]", 60, 90);
//
//                //mLcd.clearDisplay();
//                mLcd.displayLine(0, 0, line0);
//                mLcd.displayLine(1, 0, line1);
//                mLcd.displayLine(2, 0, line2);
//                mLcd.displayLine(3, 15, "4BACK");
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Display screen");
                    mCallback = &LcdSimulate::impl_3_DisplayScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_SupplyAlgorithm()
            {
                auto &button = Button::getInstance();
                auto &chargeCtrl = ChargeControl::getInstance();

                static bool supplyAlgorithm = 0;    // MPPT+CC-CV va CC-CV Only

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                mLcd.displayLine(0, 0, "SUPPLY ALGORITHM");

                if (button.getLatestPressedButton() == Button::ButtonName::UP
                        || button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    supplyAlgorithm = !supplyAlgorithm;
                }

                if (supplyAlgorithm == 0)
                {
                    mLcd.displayLine(2, 0, "MPPT+CC-CV");
                }
                else if (supplyAlgorithm == 1)
                {
                    mLcd.displayLine(2, 0, "CC-CV Only");
                }
                else
                {
                    mLcd.displayLine(2, 0, "Error");
                }

                if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    if (supplyAlgorithm == 0)
                    {
                        chargeCtrl.mMpptMode = supplyAlgorithm;
                        mLcd.displayLine(1, 0, ">> MPPT+CC-CV");
                    }
                    else if (supplyAlgorithm == 1)
                    {
                        chargeCtrl.mMpptMode = supplyAlgorithm;
                        mLcd.displayLine(1, 0, ">> CC-CV Only");
                    }
                    else
                    {
                        mLcd.displayLine(1, 0, "Error alogrithm");
                    }

                    // TODO: phai set va luu lai vao flash
                }

                if (chargeCtrl.mMpptMode == 0)
                {
                    mLcd.displayLine(1, 0, "MPPT+CC-CV");
                }
                else if (chargeCtrl.mMpptMode == 1)
                {
                    mLcd.displayLine(1, 0, "CC-CV Only");
                }
                else
                {
                    mLcd.displayLine(1, 0, "Error");
                }

                mLcd.displayLine(3, 0, "1-2CHANGE 3SEL 4BACK");

                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_ChargeMode()
            {
                auto &button = Button::getInstance();
                auto &chargeCtrl = ChargeControl::getInstance();

                static OutputMode ouputMode = OutputMode::PSU;

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }
                mLcd.displayLine(0, 0, "MODE");

                if (button.getLatestPressedButton() == Button::ButtonName::UP)
                {
                    if (ouputMode == OutputMode::PSU)
                    {
                        ouputMode = OutputMode::INVERTER;
                    }
                    else
                    {
                        uint8_t u8 = (uint8_t) ouputMode;
                        u8--;
                        ouputMode = (OutputMode) u8;
                    }
                }
                else if (button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    if (ouputMode == OutputMode::INVERTER)
                    {
                        ouputMode = OutputMode::PSU;
                    }
                    else
                    {
                        uint8_t u8 = (uint8_t) ouputMode;
                        u8++;
                        ouputMode = (OutputMode) u8;
                    }
                }

                if (ouputMode == OutputMode::PSU)
                {
                    mLcd.displayLine(2, 0, "PSU");
                }
                else if (ouputMode == OutputMode::CHARGER)
                {
                    mLcd.displayLine(2, 0, "Charger");
                }
                else if (ouputMode == OutputMode::INVERTER)
                {
                    mLcd.displayLine(2, 0, "Inverter");
                }

                if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    if (ouputMode == OutputMode::PSU)
                    {
                        chargeCtrl.mOutputMode = ouputMode;
                        mLcd.displayLine(1, 0, ">>PSU");
                    }
                    else if (ouputMode == OutputMode::CHARGER)
                    {
                        chargeCtrl.mOutputMode = ouputMode;
                        mLcd.displayLine(1, 0, ">>Charger");
                    }
                    else if (ouputMode == OutputMode::INVERTER)
                    {
                        chargeCtrl.mOutputMode = ouputMode;
                        mLcd.displayLine(1, 0, ">>Inverter");
                    }
                    else
                    {
                        mLcd.displayLine(1, 0, "Error mode");
                    }

                    // TODO: phai set va luu lai vao flash
                }

                if (chargeCtrl.mOutputMode == OutputMode::PSU)
                {
                    mLcd.displayLine(1, 0, "PSU");
                }
                else if (chargeCtrl.mOutputMode == OutputMode::CHARGER)
                {
                    mLcd.displayLine(1, 0, "Charger");
                }
                else if (chargeCtrl.mOutputMode == OutputMode::INVERTER)
                {
                    mLcd.displayLine(1, 0, "Inverter");
                }

                mLcd.displayLine(3, 0, "1-2CHANGE 3SEL 4BACK");

                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_MaxBatteryVolt()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_MinBatteryVolt()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_ChargingCurrent()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_CoolingFan()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_FanTriggerTemp()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_ShutdownTemp()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_AutoloadCfg()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_Backlight()
            {
                auto &button = Button::getInstance();

                static bool isBacklight = true;

                if (button.getLatestPressedButton() == Button::ButtonName::UP
                        || button.getLatestPressedButton() == Button::ButtonName::DOWN)
                {
                    isBacklight = !isBacklight;
                }

                else if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }

                if (button.getLatestPressedButton() != Button::ButtonName::UNDEFINED)
                {
                    mLcd.clearDisplay();
                }

                mLcd.displayLine(0, 0, "LCD BACKLIGHT");

                if (isBacklight)
                {
                    mLcd.displayLine(1, 0, "YES");
                }
                else
                {
                    mLcd.displayLine(1, 0, "NO ");
                }

                if (button.getLatestPressedButton() == Button::ButtonName::SEL)
                {
                    if (isBacklight == true)
                    {
                        impl_backLight();
                        mLcd.displayLine(2, 0, "> Backlight on");
                    }
                    else
                    {
                        impl_Nobacklight();
                        mLcd.displayLine(2, 0, "> Backlight off");
                    }
                }

                mLcd.displayLine(3, 15, "4BACK");

                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_3_2_FactoryReset()
            {
                auto &button = Button::getInstance();
                if (button.getLatestPressedButton() == Button::ButtonName::BACK)
                {
                    LOGI("Go back to Setting screen");
                    mCallback = &LcdSimulate::impl_3_SettingScroll;    //
                }
                button.setLatestPressedButton(Button::ButtonName::UNDEFINED);
            }

            void impl_Nobacklight()
            {
                mLcd.noBackligth();
            }

            void impl_backLight()
            {
                mLcd.backlight();
            }

            void impl_ClearScreen()
            {
                mLcd.clearDisplay();
            }
        private:
            bool isNeedRefreshScreen()
            {
                return Button::getInstance().getLatestPressedButton()
                        != Button::ButtonName::UNDEFINED;
            }
            Callback mCallback;

            Lcd mLcd;    // lcd display monitor
    };

}    // namespace blib

#endif /* TESTLCD_H_ */
