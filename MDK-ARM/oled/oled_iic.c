/*
 * oled_iic.c
 *
 *  Created on: 2019年2月9日
 *      Author: XIAOSENLUO
 */

#include "oled_iic.h"
#include "i2c.h"
#include "string.h"

void OLED_InterfaceInit(void)
{
	/* I2C1 is initialized by MX_I2C1_Init() in main.c. */
}

void OLED_InterfaceReset(void)
{
	HAL_Delay(10);
}

void OLED_InterfaceWriteCommand(uint8_t cmd)
{
	uint8_t data[2] = {OLED_I2C_CMD_CONTROL, cmd};
	HAL_I2C_Master_Transmit(&hi2c1, OLED_I2C_ADDR, data, sizeof(data), OLED_I2C_TIMEOUT);
}

void OLED_InterfaceWriteData(uint8_t data)
{
	uint8_t txData[2] = {OLED_I2C_DATA_CONTROL, data};
	HAL_I2C_Master_Transmit(&hi2c1, OLED_I2C_ADDR, txData, sizeof(txData), OLED_I2C_TIMEOUT);
}

void OLED_InterfaceWriteBuffer(uint8_t *buffer, uint16_t size)
{
	uint8_t txBuffer[17];
	uint16_t offset = 0;
	uint16_t chunk;

	while(offset < size)
	{
		chunk = size - offset;
		if(chunk > 16)
		{
			chunk = 16;
		}

		txBuffer[0] = OLED_I2C_DATA_CONTROL;
		memcpy(&txBuffer[1], &buffer[offset], chunk);
		HAL_I2C_Master_Transmit(&hi2c1, OLED_I2C_ADDR, txBuffer, chunk + 1, OLED_I2C_TIMEOUT);
		offset += chunk;
	}
}

void IICInit(void)
{
	OLED_InterfaceInit();
}

void IICWriteCommand(uint8_t cmd)
{
	OLED_InterfaceWriteCommand(cmd);
}

void IICWriteData(uint8_t data)
{
	OLED_InterfaceWriteData(data);
}

void IICWriteBuffer(uint8_t *buffer, uint16_t size)
{
	OLED_InterfaceWriteBuffer(buffer, size);
}
