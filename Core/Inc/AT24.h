#ifndef __AT24_h
#define __AT24_h

#include "i2c.h"

// 设备地址高四位1010，低三位全部接地，000，最后一位0表示写，1表示读
//写地址：0xA0 
//读地址：0xA1

void AT24c02_init(void);


void AT_writebyte(uint8_t address,uint8_t byte );

uint8_t AT_readbyte(uint8_t address);


void AT_writebytes(uint8_t address,uint8_t *byte ,uint8_t size);
//m24c02一次最多写一页16个字节
//我用的是at24c，最多写八个字节


void AT_readbytes(uint8_t address,uint8_t *buffer,uint8_t size);
//一共有2的8次方的字节，size最多2的8次方


#endif
