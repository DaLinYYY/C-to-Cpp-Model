/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 16:37:31
 * @LastEditTime: 2022-03-03 17:21:01
 * @Description: 
 */
#include "device_spi.h"

DEVSPI ::DEVSPI()
{
	;
}
DEVSPI::~DEVSPI()
{
	;
}
uint8_t DEVSPI::spi_open(uint8_t device_num,uint32_t speed, spi_mode_t mode)
{
	return 0;
}
uint8_t DEVSPI::spi_write(uint8_t *buff, uint16_t len)
{
	return 0;
}
uint8_t DEVSPI::spi_read(uint8_t *buff, uint16_t len)
{
	return 0;
}
uint8_t DEVSPI::set_raed_interrupt(bool En,IRQn_Type IRQnum)
{
	return 0;
}
uint8_t DEVSPI::set_write_interrupt(bool En,IRQn_Type IRQnum)
{
	return 0;
}
void DEVSPI::spi_read_callback(void)
{
	;
}
void DEVSPI::spi_write_callback(void)
{
	;
}