#ifndef _KEYINTERRUPT_H_
#define _KEYINTERRUPT_H_

#include "stm32f10x.h"//it's lib function
#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock
extern int FLAG;
//static int FLAG;
void GPIO_init(void);
void GPIO_init2(void);
void GPIO_init3(void);
void key_intrerr(void);
void keyinter_config(void);
void safe_delay(int time);
void walkk(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);


#endif
