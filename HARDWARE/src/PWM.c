#include "PWM.h"

void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//�������
	myStruct.GPIO_Pin=GPIO_Pin_3;//enable����3****��Ҫ�޸�***
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOA,&myStruct);//enable gpioC��
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_High;//���Ը�
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);//ʹ��RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //��Ƶϵ��
  myPWM.TIM_Prescaler = 719;       
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2,&myPWM); 
	
	TIM_Cmd(TIM2, ENABLE);                      //ʹ������

}
