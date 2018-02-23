/*
    MIT License

    Copyright (c) 2018, Alexey Dynda

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/
/**
 * @file oled_ssd1331.h support for RGB OLED 96x64 display
 */


#ifndef _OLED_SSD1331_H_
#define _OLED_SSD1331_H_

#include "hal/io.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Macro to generate 8-bit color for SSD1331 OLED display */
#define RGB_COLOR8(r,g,b)    ( (r & 0xE0) | ((g >> 3)&0x1C) | (b>>6) )

/**
 * @brief Sets default color, generated by RGB_COLOR8 macros
 *
 * Sets color generated by RGB_COLOR8 macros.
 * For now only 8-bit RGB mode of SSD1331 display is supported
 * @param color - new  color to use for monochrome operations.
 */
void        ssd1331_setColor(uint16_t color);

/**
 * @brief Sets default color.
 *
 * Sets default color for monochrome operations.
 * For now only 8-bit RGB mode of SSD1331 display is supported
 * @param r - red in 0-255 range.
 * @param g - green in 0-255 range.
 * @param b - blue in 0-255 range.
 */
void        ssd1331_setRgbColor(uint8_t r, uint8_t g, uint8_t b);

void        ssd1331_setMode(uint8_t vertical);


/**
 * @defgroup LCD_DISPLAY_API LCD Display control functions
 * @{
 */

/**
 * @brief Inits 96x64 RGB OLED display (based on SSD1331 controller).
 *
 * Inits 96x64 RGB OLED display (based on SSD1331 controller).
 * User must init communication interface (i2c, spi) prior to calling this function.
 * @see ssd1306_i2cInit()
 * @see ssd1306_spiInit()
 */
void         ssd1331_96x64_init(void);

/**
 * @brief Inits 96x64 RGB OLED display over spi (based on SSD1331 controller).
 *
 * Inits 96x64 RGB OLED display over spi (based on SSD1331 controller)
 * @param rstPin - pin controlling LCD reset (-1 if not used)
 * @param cesPin - chip enable pin to LCD slave (-1 if not used)
 * @param dcPin - data/command pin to control LCD dc (required)
 */
void         ssd1331_96x64_spi_init(int8_t rstPin, int8_t cesPin, int8_t dcPin);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

// ----------------------------------------------------------------------------
#endif // _OLED_SSD1331_H_
