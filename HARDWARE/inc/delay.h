#ifndef _DELAY_H_
#define _DELAY_H_
#include "stm32f10x.h"//Lib

#include "stm32f10x_rcc.h"//clock
int delay_init(void);
void SysTick_Handler(void);
void transVal(int delayTime);


#endif
