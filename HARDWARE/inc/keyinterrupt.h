#ifndef _KEYINTERRUPT_H_
#define _KEYINTERRUPT_H_

#include "stm32f10x.h"//it's lib function
#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock

void GPIO_init(void);
void key_intrerr(void);
void keyinter_config(void);

#endif
