/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 16:37:56
 * @LastEditTime: 2022-03-03 17:00:40
 * @Description: 
 */
#ifndef BSP_DEVICE_SPI_H 
#define BSP_DEVICE_SPI_H


uint8_t bsp_spi_port_init(void);
uint8_t bsp_spi_interrupt_cfg(uint8_t port);
uint8_t bsp_spi_init(uint8_t port, uint32_t baudrate, uint8_t mode);
void bsp_spi_dma_cfg(void);	
uint8_t bsp_spi_write_data8(uint8_t port, uint8_t *data, uint8_t len);


#endif /* BSP_DEVICE_SPI_H */
