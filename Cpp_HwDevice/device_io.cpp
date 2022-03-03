/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 15:28:28
 * @LastEditTime: 2022-03-03 16:33:20
 * @Description: 
 */
#include "device_io.h"

/* 构造函数 */
DEVGPIO::DEVGPIO(void *port, uint16_t pin)
{
	_port = port;
	_pin = pin;
	_pin_state = false;
}

/* 置位 */
void DEVGPIO::set()
{
	bsp_gpio_set(void *_port, uint16_t _pin);
	_pin_state = true;
}

/* 复位 */
void DEVGPIO::reset()
{
	bsp_gpio_reset(void *_port, uint16_t _pin);
	_pin_state = false;
}

/* 翻转 */
void DEVGPIO::toggle()
{
	bsp_gpio_toggle(void *_port, uint16_t _pin);
	_pin_state = !_pin_state;
}

/* 读取管脚当前状态 */
bool DEVGPIO::readpin()
{
	_pin_state = bsp_gpio_read(void *_port, uint16_t _pin);
	return _pin_state;
}


/* tests */
void user_io_test(void)
{
    DEVGPIO test(PIN_GPIO_Port,PIN_Pin);
    test.set();
}