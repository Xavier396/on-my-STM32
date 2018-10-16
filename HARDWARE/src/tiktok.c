#include "tiktok.h"
int j;
void timeinit(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //分组1
	NVIC_InitTypeDef tiktokConfig;
	tiktokConfig.NVIC_IRQChannel=TIM4_IRQn; //中断线4
	tiktokConfig.NVIC_IRQChannelCmd=ENABLE;
	tiktokConfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	tiktokConfig.NVIC_IRQChannelSubPriority=2;//从优先级2
	NVIC_Init(&tiktokConfig); 
	
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);//使能RCC
  TIM_TimeBaseInitTypeDef myTim; 
  myTim.TIM_Period =9999;           //分频系数
  myTim.TIM_Prescaler = 719;       
  myTim.TIM_ClockDivision = TIM_CKD_DIV1; 
  myTim.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4,&myTim); 
	
	TIM_ITConfig(TIM4,TIM_IT_Update, ENABLE ); //使能中断tim4
	TIM_Cmd(TIM4, ENABLE);                      //使能外设
	
}



 void TIM4_IRQHandler(void)
 {
	 if(TIM_GetITStatus(TIM4,TIM_IT_Update)!=0) 
	 {
	    j++;
		 if(j%2==1)
			GPIO_SetBits(GPIOE, GPIO_Pin_0); 
		 if(j%2==0)
			GPIO_ResetBits(GPIOE, GPIO_Pin_0); 
		 
	 }
	 
		 
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update); //清中断
 }
