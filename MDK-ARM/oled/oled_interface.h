/*
 * oled_interface.h
 *
 * Bus abstraction used by the SSD1306 controller layer.
 */

#ifndef OLED_INTERFACE_H_
#define OLED_INTERFACE_H_

#include "oled_includes_.h"

#if (OLED_INTERFACE == OLED_INTERFACE_I2C)
#include "oled_iic.h"
#elif (OLED_INTERFACE == OLED_INTERFACE_SPI)
#include "oled_spi_.h"
#else
#error "Unsupported OLED_INTERFACE"
#endif

void OLED_InterfaceInit(void);
void OLED_InterfaceReset(void);
void OLED_InterfaceWriteCommand(uint8_t cmd);
void OLED_InterfaceWriteData(uint8_t data);
void OLED_InterfaceWriteBuffer(uint8_t *buffer, uint16_t size);

#endif /* OLED_INTERFACE_H_ */
