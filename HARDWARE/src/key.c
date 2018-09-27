#include "key.h"
void key_Init(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//启用浮空输入模式
	myStruct.GPIO_Pin=GPIO_Pin_3;//enable引脚3
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOC,&myStruct);//enable gpioC口
}
