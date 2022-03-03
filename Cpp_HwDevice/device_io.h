/*
 * @FileName: 
 * @Author: YangSL
 * @Date: 2022-03-03 15:28:18
 * @LastEditTime: 2022-03-03 16:30:37
 * @Description: 
 */

#ifndef DEVICE_IO_H
#define DEVICE_IO_H
// #define __cplusplus 1

// #ifdef __cplusplus
#include <stdint.h>
#include "bsp_io.h"

class DEVGPIO
{
public:
    void * _port;
    uint8_t _pin;
    bool pin_status;

public:
	DEVGPIO(void *port, uint16_t pii);
	DEVGPIO() {}
	void set();
	void reset();
	void toggle();
	bool readpin();

}


// #endif /* __cplusplus */
#endif /* DEVICE_IO_H */
