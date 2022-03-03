/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 15:27:23
 * @LastEditTime: 2022-03-03 16:07:42
 * @Description: 
 */
#ifndef BSP_GPIO_H
#define BSP_GPIO_H
#include "hw_config.h"

void bsp_gpio_init(void *_port, uint16_t _pin, );

void bsp_gpio_set(void *_port, uint16_t _pin);

void bsp_gpio_reset(void *_port, uint16_t _pin);

void bsp_gpio_toggle(void *_port, uint16_t _pin);

uint8_t bsp_gpio_read(void *_port, uint16_t _pin);


#endif /* BSP_GPIO_H */

