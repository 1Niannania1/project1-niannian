/*
 * oled_hal.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef NEW_OLED_HAL_H_
#define NEW_OLED_HAL_H_


#include "Fonts/oled_fonts.h"
#include "stdbool.h"
#include "oled_ssd1306.h"
#include "Images/oled_images.h"

/* 获取当前显示方向下的屏幕高度，单位：像素。 */
int16_t oled_getHeight(void);
/* 获取当前显示方向下的屏幕宽度，单位：像素。 */
int16_t oled_getWidth(void);

/* 获取当前屏幕旋转方向，返回值范围 0~3。 */
uint8_t oled_getRotation(void);

/* 获取当前文字光标 X 坐标。 */
int16_t oled_getCursorX(void);
/* 获取当前文字光标 Y 坐标。 */
int16_t oled_getCursorY(void);

/* 设置屏幕旋转方向，r 取 0~3。 */
void oled_setRotation(uint8_t r);

/* 画空心矩形，左上角 (x,y)，宽 w，高 h，color 可用 WHITE/BLACK/INVERSE。 */
void oled_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);
/* 画空心圆，圆心 (x0,y0)，半径 r。 */
void oled_drawCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
/* 画圆的局部弧线，主要给圆角矩形等内部函数使用。 */
void oled_drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint8_t color);
/* 画空心三角形，三个顶点分别为 (x0,y0)、(x1,y1)、(x2,y2)。 */
void oled_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
/* 画空心圆角矩形，radius 为圆角半径。 */
void oled_drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint8_t color);
/* 画单个字符，size 为放大倍数，color 为前景色，bg 为背景色。 */
void oled_drawChar(int16_t x, int16_t y, char c, uint8_t color, uint16_t bg, uint8_t size);
/* 画字符串，从 (x,y) 开始，使用当前字体、文字颜色和文字大小。 */
void oled_drawText(int16_t x, int16_t y, char* text);

/* 显示 8 位十六进制数，例如 0xAF 显示为 AF。 */
void oled_displayHex8(int16_t x, int16_t y, uint8_t hex8);
/* 显示 16 位十六进制数。注意当前函数参数是 uint8_t，原库这里设计不严谨。 */
void oled_displayHex16(int16_t x, int16_t y, uint8_t hex16);
/* 显示 32 位十六进制数。注意当前函数参数是 uint8_t，原库这里设计不严谨。 */
void oled_displayHex32(int16_t x, int16_t y, uint8_t hex32);

/* 显示有符号整数。 */
void oled_displayInt(int16_t x, int16_t y, int num);

/* 显示浮点数，当前实现会使用 snprintf，嵌入式里会增加代码体积。 */
void oled_displayFloat(int16_t x, int16_t y, float _float);

/* 画实心圆。 */
void oled_fillCircle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
/* 填充圆的局部区域，主要给圆角矩形等内部函数使用。 */
void oled_fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint8_t color);
/* 画实心三角形。 */
void oled_fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint8_t color);
/* 画实心圆角矩形。 */
void oled_fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint8_t color);
/* 画实心矩形。 */
void oled_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint8_t color);


/* 从 Flash/const 数组画 1 位黑白位图，bitmap 通常来自图片取模数组。 */
void oled_drawBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color);
/* 从 RAM 数组画 1 位黑白位图。 */
void oled_drawBitmapFromRAM(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint8_t color);
/* 按 XBM 位序从 Flash/const 数组画图片，适合 GIMP 导出的 XBM 数据。 */
void oled_drawXBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color);
//void oled_drawGrayscaleBitmapFromFlash(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h);
//void oled_drawGrayscaleBitmapFromRAM(int16_t x, int16_t y, uint8_t *bitmap,int16_t w, int16_t h);
//void oled_drawGrayscaleBitmap(int16_t x, int16_t y,const uint8_t bitmap[], const uint8_t mask[], int16_t w, int16_t h);
//void oled_drawGrayscaleBitmap(int16_t x, int16_t y,uint8_t *bitmap, uint8_t *mask, int16_t w, int16_t h);

/* 设置文字放大倍数，1 表示原始大小，2 表示放大 2 倍。 */
void oled_setTextSize(uint8_t s);
/* 设置文字前景色和背景色，常用 WHITE/BLACK。 */
void oled_setTextColor(uint8_t color, uint8_t bg);

//void oled_setFont(const GFXfont *f);
/* 设置当前使用的点阵字体，例如 &SongFont_ASCII_8x16。 */
void oled_setUserFont(oledFont* _userfont);
/* 获取当前字体宽度，单位：像素。 */
uint8_t oled_getUserFontW(void);
/* 获取当前字体高度，单位：像素。 */
uint8_t oled_getUserFontH(void);
//void oled_getTextBounds(const char *string, int16_t x, int16_t y,int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);





#endif 
/* NEW_OLED_HAL_H_ */
