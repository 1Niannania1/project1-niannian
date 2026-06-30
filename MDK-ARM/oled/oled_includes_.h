/*
 * oled_includes.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef OLED_INCLUDES__H_
#define OLED_INCLUDES__H_

#include "stdint.h"
#include "stm32f1xx_hal.h"


/*
 * OLED driver configuration.
 *
 * The SSD1306 layer knows the display controller commands and framebuffer.
 * This file selects which bus layer sends those bytes to the panel.
 */
#define OLED_INTERFACE_I2C      1
#define OLED_INTERFACE_SPI      2

#ifndef OLED_INTERFACE
#define OLED_INTERFACE          OLED_INTERFACE_I2C
#endif

/*
 * Display geometry. Enable exactly one panel size.
 */
#ifndef SSD1306_128_64
#ifndef SSD1306_128_32
#ifndef SSD1306_96_16
#define SSD1306_128_64
#endif
#endif
#endif

#if (OLED_INTERFACE == OLED_INTERFACE_SPI)
/* 0-Polling, 1-DMA, 2-IT */
#ifndef SPI_TRANSMIT
#define SPI_TRANSMIT            0
#endif
#endif

#endif
 /* NEW_OLED_INCLUDES__H_ */
