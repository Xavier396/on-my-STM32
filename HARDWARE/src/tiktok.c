#include "tiktok.h"
int j;
void timeinit(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�жϷ��飬�ڶ���
	NVIC_InitTypeDef tiktokconfig;
	tiktokconfig.NVIC_IRQChannel=EXTI2_IRQn;//�ж���2
	tiktokconfig.NVIC_IRQChannelCmd=ENABLE;
	tiktokconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	tiktokconfig.NVIC_IRQChannelSubPriority=2;//�����ȼ�2
	NVIC_Init(&tiktokconfig);
	
	TIM_TimeBaseInitTypeDef myTim;
	myTim.TIM_ClockDivision=TIM_CKD_DIV1;//���ָ�
	myTim.TIM_CounterMode=TIM_CounterMode_Up;
	myTim.TIM_Period=9999;
	myTim.TIM_Prescaler=71;//��Ƶϵ����ÿ��1M
	//myTim.TIM_RepetitionCounter;
	
TIM_TimeBaseInit(TIM4,&myTim);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//enable tim4�ж�
	TIM_Cmd(TIM2,ENABLE);//ʹ��tim����
}

void TIM4_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM4,TIM_IT_Update)==SET)
	{
		j++;
		if(j%2==1)
		{
			GPIO_SetBits(GPIOE,GPIO_Pin_0);
		}
		else if(j%2==0)
		{
			GPIO_ResetBits(GPIOE,GPIO_Pin_0);
		}
		
	}TIM_ClearITPendingBit(TIM4,TIM_IT_Update);
}
