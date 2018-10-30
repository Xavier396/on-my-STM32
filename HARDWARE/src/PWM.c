#include "PWM.h"

void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//�������
	myStruct.GPIO_Pin=GPIO_Pin_7;//enable����0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOA,&myStruct);//enable gpioA��
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_Low;//���Ե�
	myOc.TIM_Pulse=5000;
	myOc.TIM_OutputState=ENABLE;
	TIM_OC2Init(TIM3,&myOc);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//ʹ��RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //��Ƶϵ��
  myPWM.TIM_Prescaler = 144;       
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myPWM); 
	
	
	TIM_Cmd(TIM3, ENABLE);                      //ʹ������

}
