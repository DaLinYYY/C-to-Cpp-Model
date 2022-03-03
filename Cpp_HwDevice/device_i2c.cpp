/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 17:24:54
 * @LastEditTime: 2022-03-03 17:46:23
 * @Description: 
 */
#include "device_i2c.h"

DEVICEI2C::DEVICEI2C(M4_I2C_TypeDef *dev,rt_device_ops_t *ops)
{
	I2C_DEV = dev;
	op = ops;
}
DEVICEI2C::~DEVICEI2C()
{
	op->close(I2C_DEV);
	op = NULL;
}
uint8_t DEVICEI2C::i2c_init(uint32_t baudrate)
{
	op->init(I2C_DEV,baudrate);
	return 0;
}
uint8_t DEVICEI2C::i2c_read(uint8_t device_addr,uint8_t addr,uint8_t *buffer, uint16_t len)
{
	op->read(I2C_DEV,device_addr,addr,buffer,len);
	return 0;
}
uint8_t DEVICEI2C::i2c_write(uint8_t device_addr,uint8_t addr, const uint8_t *buffer, uint16_t len)
{
	op->write(I2C_DEV,device_addr,addr,buffer,len);
	return 0;
}

