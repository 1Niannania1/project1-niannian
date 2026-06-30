/*
 * oled_iic.h
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#ifndef NEW_OLED_IIC_H_
#define NEW_OLED_IIC_H_

#include "oled_includes_.h"

#ifndef SSD1306_I2C_ADDRESS
#define SSD1306_I2C_ADDRESS        0x3C
#endif

#define OLED_I2C_ADDR              (SSD1306_I2C_ADDRESS << 1)
#define OLED_I2C_CMD_CONTROL       0x00
#define OLED_I2C_DATA_CONTROL      0x40
#define OLED_I2C_TIMEOUT           100

void OLED_InterfaceInit(void);
void OLED_InterfaceReset(void);
void OLED_InterfaceWriteCommand(uint8_t cmd);
void OLED_InterfaceWriteData(uint8_t data);
void OLED_InterfaceWriteBuffer(uint8_t *buffer, uint16_t size);

//兼容旧接口
void IICInit(void);
void IICWriteCommand(uint8_t cmd);
void IICWriteData(uint8_t data);
void IICWriteBuffer(uint8_t *buffer, uint16_t size);


#endif /* NEW_OLED_IIC_H_ */
