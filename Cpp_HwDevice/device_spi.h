/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 16:37:18
 * @LastEditTime: 2022-03-03 17:22:00
 * @Description: 
 */

#ifndef DEVICE_SPI_H
#define DEVICE_SPI_H
// #define __cplusplus 1

// #ifdef __cplusplus
#include <stdint.h>
#include "bsp_spi.h"

typedef enum SPIMODE
{
	Mode0,//CPOL 0, CPHA 0
	Mode1,//CPOL 0, CPHA 1
	Mode2,//CPOL 1, CPHA 0
	Mode4 //CPOL 1, CPHA 1
}spi_mode_t;

class DEVSPI
{
	public :
		DEVSPI();
		~DEVSPI();
		uint8_t spi_open(uint8_t device_num,uint32_t speed, spi_mode_t mode);
		uint8_t get_device_id(void);
		uint8_t spi_write(uint8_t *buff,uint16_t len);
		uint8_t spi_read(uint8_t *buff,uint16_t len);
		uint8_t set_raed_interrupt(bool En,IRQn_Type IRQnum);
		uint8_t set_write_interrupt(bool En,IRQn_Type IRQnum);
	private:
		uint8_t _device_id;
        uint8_t _nss_num;
		void spi_read_callback(void);
		void spi_write_callback(void);
		IRQn_Type SPI_READ_IRQnum;
		IRQn_Type SPI_Write_IRQnum;
};

// #endif /* __cplusplus */
#endif /* DEVICE_SPI_H */


