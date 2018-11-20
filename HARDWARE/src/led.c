#include "led.h"

void led_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_Out_PP;//启用推挽输出模式
	myStruct.GPIO_Pin=GPIO_Pin_All;//enable引脚
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOE,&myStruct);//enable gpioE口
}
void speak_init(void)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_Out_PP;//启用推挽输出模式
	myStruct.GPIO_Pin=GPIO_Pin_4;//enable引脚
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOC,&myStruct);//enable gpioC口
}
