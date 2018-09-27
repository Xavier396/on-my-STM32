#include "keyinterrupt.h"
void GPIO_init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_2;//enable����2
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOC,&myStruct);//enable gpioC��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);
}
void key_intrerr()
{
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line2;//�ж���2����
	keystru.EXTI_LineCmd=ENABLE;//enable�ж�
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�ģʽ
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&keystru);//ʹ�ܽṹ��
}
void keyinter_config() //�����жϿ�����
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�жϷ��飬��һ��
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI2_IRQn;//�ж���
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	keyconfig.NVIC_IRQChannelSubPriority=0;//�����ȼ�0
	NVIC_Init(&keyconfig);
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)=)//����ɶ��֪����
	{
	
	}
	if(GPIO_ReadInputData(GPIOC)==0)
	{
		//����һյ��
	}
}
