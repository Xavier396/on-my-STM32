#include "tiktok.h"
int j;
void timeinit(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断分组，第二组
	NVIC_InitTypeDef tiktokconfig;
	tiktokconfig.NVIC_IRQChannel=EXTI2_IRQn;//中断线2
	tiktokconfig.NVIC_IRQChannelCmd=ENABLE;
	tiktokconfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	tiktokconfig.NVIC_IRQChannelSubPriority=2;//从优先级2
	NVIC_Init(&tiktokconfig);
	
	TIM_TimeBaseInitTypeDef myTim;
	myTim.TIM_ClockDivision=TIM_CKD_DIV1;//不分割
	myTim.TIM_CounterMode=TIM_CounterMode_Up;
	myTim.TIM_Period=9999;
	myTim.TIM_Prescaler=71;//分频系数，每秒1M
	//myTim.TIM_RepetitionCounter;
	
TIM_TimeBaseInit(TIM4,&myTim);
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE);//enable tim4中断
	TIM_Cmd(TIM2,ENABLE);//使能tim外设
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
