#include "PWM.h"

void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//推挽输出
	myStruct.GPIO_Pin=GPIO_Pin_3;//enable引脚3****需要修改***
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOA,&myStruct);//enable gpioC口
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_High;//极性高
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//使能RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //分频系数
  myPWM.TIM_Prescaler = 719;       
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&myPWM); 
	
	TIM_Cmd(TIM2, ENABLE);                      //使能外设

}
