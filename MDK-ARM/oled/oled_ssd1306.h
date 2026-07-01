/*
 * oled_ssd1306.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef OLED_SSD1306_H_
#define OLED_SSD1306_H_

#include "stdbool.h"
#include "oled_includes_.h"

#define BLACK                          0 ///< Draw 'off' pixels
#define WHITE                          1 ///< Draw 'on' pixels
#define INVERSE                        2 ///< Invert pixels

// Address for 128x32 is 0x3C
// Address for 128x64 is 0x3D (default) or 0x3C (if SA0 is grounded)

/*
 * SSD1306 display geometry.
 *
 * Configure the panel size in oled_includes_.h by enabling one of:
 *   SSD1306_128_64  128x64 pixel display
 *   SSD1306_128_32  128x32 pixel display
 *   SSD1306_96_16   96x16 pixel display
 */

#if defined SSD1306_128_64 && defined SSD1306_128_32
  #error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32 && !defined SSD1306_96_16
  #error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 32
#endif
#if defined SSD1306_96_16
  #define SSD1306_LCDWIDTH                  96
  #define SSD1306_LCDHEIGHT                 16
#endif

#define HEIGHT 									SSD1306_LCDHEIGHT
#define WIDTH										SSD1306_LCDWIDTH

#define SSD1306_MEMORYMODE          0x20 ///< See datasheet
#define SSD1306_COLUMNADDR          0x21 ///< See datasheet
#define SSD1306_PAGEADDR            0x22 ///< See datasheet
#define SSD1306_SETCONTRAST         0x81 ///< See datasheet
#define SSD1306_CHARGEPUMP          0x8D ///< See datasheet
#define SSD1306_SEGREMAP            0xA0 ///< See datasheet
#define SSD1306_DISPLAYALLON_RESUME 0xA4 ///< See datasheet
#define SSD1306_DISPLAYALLON        0xA5 ///< Not currently used
#define SSD1306_NORMALDISPLAY       0xA6 ///< See datasheet
#define SSD1306_INVERTDISPLAY       0xA7 ///< See datasheet
#define SSD1306_SETMULTIPLEX        0xA8 ///< See datasheet
#define SSD1306_DISPLAYOFF          0xAE ///< See datasheet
#define SSD1306_DISPLAYON           0xAF ///< See datasheet
#define SSD1306_COMSCANINC          0xC0 ///< Not currently used
#define SSD1306_COMSCANDEC          0xC8 ///< See datasheet
#define SSD1306_SETDISPLAYOFFSET    0xD3 ///< See datasheet
#define SSD1306_SETDISPLAYCLOCKDIV  0xD5 ///< See datasheet
#define SSD1306_SETPRECHARGE        0xD9 ///< See datasheet
#define SSD1306_SETCOMPINS          0xDA ///< See datasheet
#define SSD1306_SETVCOMDETECT       0xDB ///< See datasheet

#define SSD1306_SETLOWCOLUMN        0x00 ///< Not currently used
#define SSD1306_SETHIGHCOLUMN       0x10 ///< Not currently used
#define SSD1306_SETSTARTLINE        0x40 ///< See datasheet

#define SSD1306_EXTERNALVCC         0x01 ///< External display voltage source
#define SSD1306_SWITCHCAPVCC        0x02 ///< Gen. display voltage from 3.3V

#define SSD1306_RIGHT_HORIZONTAL_SCROLL              0x26 ///< Init rt scroll
#define SSD1306_LEFT_HORIZONTAL_SCROLL               0x27 ///< Init left scroll
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29 ///< Init diag scroll
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL  0x2A ///< Init diag scroll
#define SSD1306_DEACTIVATE_SCROLL                    0x2E ///< Stop scroll
#define SSD1306_ACTIVATE_SCROLL                      0x2F ///< Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA             0xA3 ///< Set scroll range

void ssd1306_Init(uint8_t _vccState);

void ssd1306_updateScreen(void);
void ssd1306_updataArea(uint8_t startcol, uint8_t stopcol, uint8_t startpage, uint8_t stoppage);
void ssd1306_clearScreen(void);

void ssd1306_invertDisplay(bool _invert);
void ssd1306_dimDisplay(bool _dim);

void ssd1306_drawPixel(int16_t x, int16_t y, uint8_t color);
void ssd1306_drawFastHLine(int16_t x, int16_t y, int16_t w, uint8_t color);
void ssd1306_drawFastVLine(int16_t x, int16_t y, int16_t h, uint8_t color);
void ssd1306_drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);

void ssd1306_fillScreen(uint8_t color);

void ssd1306_startScrollRight(uint8_t start, uint8_t stop);
void ssd1306_startScrollLeft(uint8_t start, uint8_t stop);
void ssd1306_startScrollDiagRight(uint8_t start, uint8_t stop);
void ssd1306_startScrollDiagLeft(uint8_t start, uint8_t stop);
void ssd1306_stopScroll(void);

void ssd1306_command(uint8_t com);

bool ssd1306_getPixel(int16_t x, int16_t y);
uint8_t* ssd1306_getBuffer(void);

int16_t ssd1306_getHeight(void);
int16_t ssd1306_getWidth(void);

// get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
void ssd1306_setCursor(int16_t x, int16_t y);
int16_t ssd1306_getCursorX(void);
int16_t ssd1306_getCursorY(void);

void ssd1306_setRotation(uint8_t r);
uint8_t ssd1306_getRotation(void);

void ssd1306_setTextWrap(bool w);

void ssd1306_cp437(bool x);










#endif 
/* NEW_OLED_SSD1306_H_ */
