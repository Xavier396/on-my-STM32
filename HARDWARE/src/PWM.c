#include "PWM.h"

/*void pwm_init(void)
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���a
	GPIO_InitTypeDef myStruct;//��ʼ��io
	//GPIO_PinRemapConfig(GPIO_PartialRemap_TIM3,ENABLE);//������ӳ��,B5
	//GPIO_PinRemapConfig(GPIO_FullRemap_TIM3,ENABLE);*///C7
	/*myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//�������
	myStruct.GPIO_Pin=GPIO_Pin_7;//enable����0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOB,&myStruct);//enable gpioA,B,C��
	
	TIM_OCInitTypeDef myOc;
	myOc.TIM_OCMode=TIM_OCMode_PWM2;
	myOc.TIM_OCPolarity=TIM_OCPolarity_Low;//���Ե�
	myOc.TIM_Pulse=5000;//5000/ARR=ռ�ձ�
	myOc.TIM_OutputState=ENABLE;
	TIM_OC2Init(TIM3,&myOc);
	
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//ʹ��RCC
  TIM_TimeBaseInitTypeDef myPWM; 
  myPWM.TIM_Period =9999;           //����ֵ��Ҳ����ARR
  myPWM.TIM_Prescaler = 144;       //��Ƶϵ��,f=72000000/(ARR*��Ƶϵ��)
  myPWM.TIM_ClockDivision = TIM_CKD_DIV1; 
  myPWM.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myPWM); 
	
	
	TIM_Cmd(TIM3, ENABLE);                      //ʹ������

}*/
void pwm_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//?a??RCC����?
	GPIO_InitTypeDef GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;//��?������?3?
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_7;//��1?����y??
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//��y???��?��
	GPIO_Init(GPIOA,&GPIO_InitStructure);//��1?��IO
	
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

