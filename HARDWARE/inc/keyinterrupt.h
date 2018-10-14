#ifndef _KEYINTERRUPT_H_
#define _KEYINTERRUPT_H_

#include "stm32f10x.h"//it's lib function
#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock
extern int FLAG;
//static int FLAG;
void GPIO_init(void);
void key_intrerr(void);
void keyinter_config(void);
void safe_delay(int time);
void walkk(void);
void EXTI2_IRQHandler(void);

#endif
