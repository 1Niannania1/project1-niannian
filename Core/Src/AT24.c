#include "AT24.h"


void AT24c02_init()
{
    
MX_I2C2_Init();


}
void AT_writebyte(uint8_t address,uint8_t byte )
{



HAL_I2C_Mem_Write(&hi2c2,w_address,address,I2C_MEMADD_SIZE_8BIT,&byte,1,1000);

//内部写周期，延时五ms让eeprom写入
//发完一段字节后延时5ms留给写入，不需要每一个字节都留
HAL_Delay(5);



}

uint8_t AT_readbyte(uint8_t address)
{
    uint8_t recive_byte=0;

HAL_I2C_Mem_Read(&hi2c2,r_address,address,I2C_MEMADD_SIZE_8BIT,&recive_byte,1,1000);

return recive_byte;

}

//连续写多个字节
void AT_writebytes(uint8_t address,uint8_t *byte ,uint8_t size)
{
HAL_I2C_Mem_Write(&hi2c2,w_address,address,I2C_MEMADD_SIZE_8BIT,byte,size,1000);
HAL_Delay(5);

}



void AT_readbytes(uint8_t address,uint8_t *buffer,uint8_t size)

{

HAL_I2C_Mem_Read(&hi2c2,r_address,address,I2C_MEMADD_SIZE_8BIT,buffer,size,1000);
}
