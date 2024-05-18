/*
 * Lcd.h
 *
 *  Created on: May 16, 2024
 *      Author: binhhv.23.1.99@gmail.com
 */

#ifndef LCD_H_
#define LCD_H_

#include <cstdint>
#include "Log.h"
#include "main.h"

namespace blib
{
    /* 0000 1EnRwRs */
#define LCD_EN              0x04
#define LCD_RW              0x02
#define LCD_RS              0x01

    /*define command*/
#define LCD_CLEAR_DISPLAY   0x01    //Clear all the display data by writing "20H" to all DDRAM address, and set DDRAM address to "00H" in to address counter.
#define LCD_RETURN_HOME     0x02    //Return Home is cursor return home instruction.
#define LCD_ENTRY_MODE_SET  0x04    //Set the moving direction of cursor and display.
#define LCD_DISPLAY_ON_OFF  0x08    //Control display/cursor/blink ON/OFF 1 bit register.
#define LCD_CUR_DIS_SHIFT   0x10    //
#define LCD_FUNCTION_SET    0x20    //
#define LCD_CGRAM_SET       0x40    //Set CGRAM address to AC
    /*
     * The address of the DDRAM of the display is as given below:
     * Line 1 >> 0x80|0x00 [from 0x00(00) to 0x13(19)]
     * Line 2 >> 0x80|0x40 [from 0x40(40) to 0x53(59)]
     * Line 3 >> 0x80|0x14 [from 0x14(20) to 0x27(39)]
     * Line 4 >> 0x80|0x54 [from 0x54(40) to 0x67(79)]
     */
#define LCD_DDRAM_SET       0x80    //Set DDRAM address to AC. This instruction makes DDRAM data available from MPU
    /* Entry mode set */
#define LCD_CURSOR_ID_LEFT  0x00    //I/D = 0, cursor/blink moves to left and DDRAM address is decreased by 1
#define LCD_CURSOR_ID_RIGHT 0x02    //I/D = 1, cursor/blink moves to right and DDRAM address is increased by 1
#define LCD_SHIFT_S_ENABLE  0x01    //S = 1, DDRAM write operation, shift of entire display is performed according to I/D value (I/D = '1': shift left, I/D = '0': shift right)
#define LCD_SHIFT_S_UNABLE  0x00    //S = 0, shift of entire display is not performed
    /* Display ON/OFF */
#define LCD_DISPLAY_D_ON    0x04    //D = 1, entire display is turn on
#define LCD_DISPLAY_D_OFF   0x00    //D = 0, display is turned off, but display data is remained in DDRAM
#define LCD_CURSOR_C_ON     0x02    //C = 1, cursor is turned on
#define LCD_CURSOR_C_OFF    0x00    //C = 0, cursor is disappeared in current display, but I/D register remains its data
#define LCD_BLINK_B_ON      0x01    //B = 1, cursor blink is on, that performs alternate between all the high data and display character at the cursor position
#define LCD_BLINK_B_OFF     0x00    //B = 0, blink if off

    /* Cursor or display shift */
    /*
     *  S/C |   R/L |   Description                                                     |   AC value
     *  0   |   0   |   Shift cursor to the left                                        |   AC = AC - 1
     *  0   |   1   |   Shift cursor to the right                                       |   AC = AC + 1
     *  1   |   0   |   Shift display to the left. Cursor follows the display shift     |   AC = AC
     *  1   |   1   |   Shift display to the right. Cursor follows the display shift    |   AC = AC
     */
#define LCD_SHIFT_SC_CURSOR 0x00    //S/C = 0, shift cursor
#define LCD_SHIFT_SC_DISPLAY 0x08   //S/C = 1, shift display
#define LCD_SHIFT_RL_LEFT   0x00    //R/L = 0, to the left
#define LCD_SHIFT_RL_RIGHT  0x04    //R/L = 0, to the right

    /* Function set */
#define LCD_DATA_DL_8BITS   0x10    //DL = 1, it means 8-bit bus mode with MPU
#define LCD_DATA_DL_4BITS   0x00    //DL = 0, it means 4-bit bus mode with MPU. So to speak, DL is a signal to select 8-bit or 4-bit bus mode
#define LCD_LINE_N_1        0x00    //N = 0, it means 1-line display mode
#define LCD_LINE_N_2        0x08    //N = 1, 2-line display mode is set
#define LCD_FONT_F_58       0x00    //F = 0, it means 5x8 dots format display mode
#define LCD_FONT_F_511      0x04    //F = 1, 5 x  11 dots format display mode
    /* black light */
#define LCD_BLACKLIGHT      0x08    //
#define LCD_NOBLACKLIGHT    0x00    //

    class Lcd
    {
        public:
            enum class LcdType
            {
                LCD_TYPE_1602, LCD_TYPE_2004, LCD_TYPE_UNDEFINED,
            };
            Lcd(LcdType type, I2C_HandleTypeDef *mHi2c, uint8_t address);
            virtual ~Lcd();
            void sendCmd(uint8_t command);
            void sendData(uint8_t data);
            void setCursor(uint8_t row, uint8_t col);
            void rollData();
            void pushData();
            void displayLine(uint8_t row, uint8_t col, const char *string);
            void clearDisplay();
            void backlight();
            void noBackligth();
            void init();
            void makeCustomCharacter(uint8_t location, uint8_t *byte);
//            void
        private:
            LcdType mLcdType;
            I2C_HandleTypeDef *mHi2c;

            uint8_t mLcdAddress;
            uint8_t mEntryMode;
            uint8_t mDisplayControl;
            uint8_t mFunctionSet;
            uint8_t mBlackLight;
            uint8_t mRow;
            uint8_t mCol;
    };

}    // namespace blib

#endif /* LCD_H_ */
