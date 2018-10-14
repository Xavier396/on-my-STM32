#ifndef _TIKTOK_H_
#define _TIKTOK_H_

#include "stm32f10x.h"//it's lib function
#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock
void timeinit(void);
void TIM4_IRQHandler(void);
#endif
