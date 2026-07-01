#include "DAC.h"



void DAC_init()
{
    
MX_I2C1_Init();


}
// void DAC_writebyte(uint8_t byte )
// {



// HAL_I2C_Master_Transmit(&hi2c2,w_address,&byte,1,1000);

// HAL_Delay(5);



// }

// uint8_t DAC_readbyte(uint8_t address)
// {
//     uint8_t recive_byte=0;

// HAL_I2C_Mem_Read(&hi2c2,r_address,address,I2C_MEMADD_SIZE_8BIT,&recive_byte,1,1000);

// return recive_byte;

// }

//连续写一个地址+2个字节
//直接传入指向DAC数组里面数字电压的指针
//每次中断时候指针加一 ，发送下一个电压
void DAC_writebytes(const uint16_t *DAC )
{
    uint8_t arr[2];
    arr[0]=(0x00<<4)+(((*DAC)>>8)&(0x0f));  //0x00-fast_mode,不关断。后一部分是取出DAC的高四位
    arr[1]=(*DAC)&(0xff);                //DAC的低八位
HAL_I2C_Master_Transmit(&hi2c1,w_address,arr,2,1000);
// HAL_Delay(1);//fast_mode,no need to eeprom write (busy flag)
                                                       
}



// void DAC_readbytes(uint8_t address,uint8_t *buffer,uint8_t size)

// {

// HAL_I2C_Mem_Read(&hi2c2,r_address,address,I2C_MEMADD_SIZE_8BIT,buffer,size,1000);
// }
