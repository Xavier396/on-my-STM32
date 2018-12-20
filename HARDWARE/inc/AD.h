#ifndef _AD_H_

#define _AD_H_
#include "stm32f10x.h"//it's lib function
#include "stm32f10x_gpio.h"//it's io
#include "stm32f10x_rcc.h"//it's clock
#include "stm32f10x_adc.h"//AD×¨ÓÃº¯Êý¿â
u16 get_ADC(u8 ch);
void AD_Init(void);

#endif
