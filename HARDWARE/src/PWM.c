#include "PWM.h"

void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//推挽输出
	myStruct.GPIO_Pin=GPIO_Pin_7;//enable引脚0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOA,&myStruct);//enable gpioA口
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_Low;//极性低
	myOc.TIM_Pulse=5000;
	myOc.TIM_OutputState=ENABLE;
	TIM_OC2Init(TIM3,&myOc);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //分频系数
  myPWM.TIM_Prescaler = 144;       
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myPWM); 
	
	
	TIM_Cmd(TIM3, ENABLE);                      //使能外设

}
