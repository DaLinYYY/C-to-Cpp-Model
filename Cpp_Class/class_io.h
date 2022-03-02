/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-02 13:42:10
 * @LastEditTime: 2022-03-02 17:00:24
 * @Description: 
 */

#ifndef GPIOPORTBASE_H_
#define GPIOPORTBASE_H_

#include "../stm32f4xx_lib/stm32f4xx.h"
#include "../stm32f4xx_lib/STM32F4xx_StdPeriph_Driver/inc/stm32f4xx_gpio.h"

namespace BSP {

typedef void (*pFun)(void*);

// 中断优先级结构体
struct NVIC_Priority
{
	uint32_t PreemptPriority;
	uint32_t SubPriority;

	NVIC_Priority(): PreemptPriority(0), SubPriority(0) {}
	NVIC_Priority(uint32_t pre, uint32_t sub) : PreemptPriority(pre), SubPriority(sub) {}
};

typedef enum 
{
    reset = 0,
    set
}PinState;


class GPIOBase
{
public:
	// 默认构造函数，不做时钟使能和引脚初始化
	GPIOBase();
	// 以下重载函数主要初始化输出模式
	GPIOBase(GPIO_InitTypeDef &initStruct, GPIO_TypeDef *port, PinState state);
	GPIOBase(uint32_t mode, GPIO_TypeDef *port, uint16_t pin, PinState state);
	GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin, PinState state);
	GPIOBase(uint32_t mode, uint32_t pull, uint32_t speed, GPIO_TypeDef *port, uint16_t pin, PinState state);

	// 以下重载函数主要初始化输入模式
	GPIOBase(GPIO_InitTypeDef &initStruct, GPIO_TypeDef *port, uint16_t pin);
	GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin);
	GPIOBase(uint32_t mode, uint32_t pull, GPIO_TypeDef *port, uint16_t pin, NVIC_Priority priority);		// 中断初始化

	virtual ~GPIOBase();


	PinState read_pin();
	void init_exti_callback(void(*callback), void *arg);	// 初始化中断服务的回调函数


protected:
	uint32_t _mode;				// 输入/输出模式
	uint32_t _pull;				// 上/下拉
	uint32_t _speed;			// 速度
	uint32_t _pin;				// pin口：0~7
	GPIO_TypeDef * _port;		// 端口：A~G
	PinState _state;		// 默认输出状态：高/低电平

	uint8_t _EXTI_Line;			// 中断线索引

private:
	void gpiox_clk_enable(GPIO_TypeDef* port);		// 端口时钟使能：A~G
	IRQn_Type get_exti_iqr();						// 获取中断通道

};

} /* namespace BSP */

// 中断服务函数不能放在类里面，函数名称编译后会被修改（C++的Name Mangling机制）
extern "C"
{
	void NMI_Handler(void);
	void HardFault_Handler(void);
	void MemManage_Handler(void);
	void BusFault_Handler(void);
	void UsageFault_Handler(void);
	void SVC_Handler(void);
	void DebugMon_Handler(void);
	void PendSV_Handler(void);
	void SysTick_Handler(void);
	void EXTI0_IRQHandler(void);
	void EXTI2_IRQHandler(void);
	void EXTI3_IRQHandler(void);
	void EXTI4_IRQHandler(void);
}


#endif /* GPIOPORTBASE_H_ */
