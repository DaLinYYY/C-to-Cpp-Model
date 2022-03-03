/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-02 15:12:43
 * @LastEditTime: 2022-03-03 15:15:54
 * @Description: 
 */

#include "class_io.h"

namespace BSP {

/* 中断相关变量 */
static pFun _EXTI_Callback[16];		// 中断服务回调函数的指针，由外部提供
static void *_callbackparm[16];		// 中断服务回调函数的参数


GPIOBase::GPIOBase() :
		_mode(GPIO_MODE_INPUT),
		_pull(GPIO_NOPULL),
		_speed(GPIO_SPEED_FREQ_LOW),
		_pin(0),
		_port(0),
		_state(GPIO_PIN_RESET)
{

}

GPIOBase::GPIOBase(GPIO_InitTypeDef &initStruct, GPIO_TypeDef *port, PinState state):
		_mode(initStruct.Mode),
		_pull(initStruct.Pull),
		_speed(initStruct.Speed),
		_pin(initStruct.Pin),
		_port(port),
		_state(state)
{
	gpiox_clk_enable(_port);
	HAL_GPIO_Init(_port, &initStruct);
	HAL_GPIO_WritePin(_port, _pin, _state);
}

GPIOBase::GPIOBase(uint32_t mode, GPIO_TypeDef *port,uint16_t pin, PinState state) :
		_mode(mode),
		_pull(GPIO_NOPULL),
		_speed(GPIO_SPEED_FREQ_LOW),
		_pin(pin),
		_port(port),
		_state(state)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	gpiox_clk_enable(_port);

	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = _mode;
	GPIO_InitStruct.Pull = _pull;
	GPIO_InitStruct.Speed = _speed;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
	HAL_GPIO_WritePin(_port, _pin, _state);
}

GPIOBase::GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin, PinState state) :
		_mode(mode),
		_pull(pull),
		_speed(GPIO_SPEED_FREQ_LOW),
		_pin(pin),
		_port(port),
		_state(state)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	gpiox_clk_enable(_port);

	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = _mode;
	GPIO_InitStruct.Pull = _pull;
	GPIO_InitStruct.Speed = _speed;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
	HAL_GPIO_WritePin(_port, _pin, _state);
}

GPIOBase::GPIOBase(uint32_t mode, uint32_t pull, uint32_t speed, GPIO_TypeDef *port,
		uint16_t pin, PinState state) :
		_mode(mode),
		_pull(pull),
		_speed(speed),
		_pin(pin),
		_port(port),
		_state(state)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	gpiox_clk_enable(_port);

	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = _mode;
	GPIO_InitStruct.Pull = _pull;
	GPIO_InitStruct.Speed = _speed;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
	HAL_GPIO_WritePin(_port, _pin, _state);
}

GPIOBase::GPIOBase(GPIO_InitTypeDef &initStruct, GPIO_TypeDef *port, uint16_t pin) :
		_mode(initStruct.Mode),
		_pull(initStruct.Pull),
		_speed(initStruct.Speed),
		_pin(initStruct.Pin),
		_port(port),
		_state(GPIO_PIN_RESET)
{
	gpiox_clk_enable(_port);
	HAL_GPIO_Init(_port, &initStruct);
}

GPIOBase::GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin) :
		_mode(mode),
		_pull(pull),
		_speed(GPIO_SPEED_FREQ_LOW),
		_pin(pin),
		_port(port),
		_state(GPIO_PIN_RESET)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	gpiox_clk_enable(_port);

	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = _mode;
	GPIO_InitStruct.Pull = _pull;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);
}

GPIOBase::GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin, NVIC_Priority priority) :
		_mode(mode),
		_pull(pull),
		_speed(GPIO_SPEED_FREQ_LOW),
		_pin(pin),
		_port(port),
		_state(GPIO_PIN_RESET)
{
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };

	gpiox_clk_enable(_port);

	GPIO_InitStruct.Pin = _pin;
	GPIO_InitStruct.Mode = _mode;
	GPIO_InitStruct.Pull = _pull;
	HAL_GPIO_Init(_port, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(this->get_exti_iqr(), priority.PreemptPriority, priority.SubPriority);
	HAL_NVIC_EnableIRQ(this->get_exti_iqr());
}


/* 析构函数 */
GPIOBase::~GPIOBase()
{
	// TODO Auto-generated destructor stub
}

void GPIOBase::gpiox_clk_enable(GPIO_TypeDef *port)
{
	if(port == GPIOA)
		__HAL_RCC_GPIOA_CLK_ENABLE();
	else if(port == GPIOB)
		__HAL_RCC_GPIOB_CLK_ENABLE();
	else if(port == GPIOC)
			__HAL_RCC_GPIOC_CLK_ENABLE();
	else if(port == GPIOD)
			__HAL_RCC_GPIOD_CLK_ENABLE();
	else if(port == GPIOE)
			__HAL_RCC_GPIOE_CLK_ENABLE();
	else if(port == GPIOF)
			__HAL_RCC_GPIOF_CLK_ENABLE();
	else if(port == GPIOG)
			__HAL_RCC_GPIOG_CLK_ENABLE();
	else return;

}

PinState GPIOBase::read_pin()
{
	return HAL_GPIO_ReadPin(_port, _pin);
}



void GPIOBase::init_exti_callback(void(*callback), void *arg)
{
	_EXTI_Callback[_EXTI_Line] = (pFun)callback;
	_callbackparm[_EXTI_Line] = arg;
}



IRQn_Type GPIOBase::get_exti_iqr()
{
	IRQn_Type res;
	switch(_pin)
	{
	case GPIO_PIN_0: res = EXTI0_IRQn; _EXTI_Line = 0; break;
	case GPIO_PIN_1: res = EXTI1_IRQn; _EXTI_Line = 1; break;
	case GPIO_PIN_2: res = EXTI2_IRQn; _EXTI_Line = 2; break;
	case GPIO_PIN_3: res = EXTI3_IRQn; _EXTI_Line = 3; break;
	case GPIO_PIN_4: res = EXTI4_IRQn; _EXTI_Line = 4; break;
	case GPIO_PIN_5: res = EXTI9_5_IRQn; _EXTI_Line = 5; break;
	case GPIO_PIN_6: res = EXTI9_5_IRQn; _EXTI_Line = 6; break;
	case GPIO_PIN_7: res = EXTI9_5_IRQn; _EXTI_Line = 7; break;
	case GPIO_PIN_8: res = EXTI9_5_IRQn; _EXTI_Line = 8; break;
	case GPIO_PIN_9: res = EXTI9_5_IRQn; _EXTI_Line = 9; break;
	case GPIO_PIN_10: res = EXTI15_10_IRQn; _EXTI_Line = 10; break;
	case GPIO_PIN_11: res = EXTI15_10_IRQn; _EXTI_Line = 11; break;
	case GPIO_PIN_12: res = EXTI15_10_IRQn; _EXTI_Line = 12; break;
	case GPIO_PIN_13: res = EXTI15_10_IRQn; _EXTI_Line = 13; break;
	case GPIO_PIN_14: res = EXTI15_10_IRQn; _EXTI_Line = 14; break;
	case GPIO_PIN_15: res = EXTI15_10_IRQn; _EXTI_Line = 15; break;
	default: break;
	}
	return res;
}

} /* namespace BSP */s
