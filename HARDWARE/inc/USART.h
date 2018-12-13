#ifndef _USART_H_
#define _USART_H_

#include "stdio.h"
#include "stm32f10x.h"//it's lib function
//#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock
#include "tiktok.h"//ÑÓÊ±º¯Êý
void usart_Init(void);
int gettime(void);
float getlength(void);
void TIM3_IRQHandler(void);
void hc_sr04_init(void);



#endif
