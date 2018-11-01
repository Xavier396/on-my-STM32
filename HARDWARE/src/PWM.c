#include "PWM.h"

/*void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启a
	GPIO_InitTypeDef myStruct;//初始化io
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);//部分重映射,B5
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);*///C7
	/*myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//推挽输出
	myStruct.GPIO_Pin=GPIO_Pin_7;//enable引脚0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOB,&myStruct);//enable gpioA,B,C口
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_Low;//极性低
	myOc.TIM_Pulse=5000;//5000/ARR=占空比
	myOc.TIM_OutputState=ENABLE;
	TIM_OC2Init(TIM3,&myOc);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//使能RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //计数值，也就是ARR
  myPWM.TIM_Prescaler = 144;       //分频系数,f=72000000/(ARR*分频系数)
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myPWM); 
	
	
	TIM_Cmd(TIM3, ENABLE);                      //使能外设

}*/
void pwm_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//?a??RCCê±?
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//í?íìê?3?
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;//ê1?üòy??
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//òy???ù?è
	GPIO_Init(GPIOA,&GPIO_InitStructure);//ê1?üIO
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_TimeBaseStructure.TIM_Period=9999;
	TIM_TimeBaseStructure.TIM_Prescaler=144;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	
	TIM_OCInitTypeDef TIM_OCInitStructure;
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=ENABLE;
	
	TIM_OCInitStructure.TIM_Pulse=5000;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_Cmd(TIM3,ENABLE);
}

