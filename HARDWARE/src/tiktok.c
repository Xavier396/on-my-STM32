#include "tiktok.h"
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
  myTim.TIM_Period =8-1;           //分频系数
  myTim.TIM_Prescaler = 9-1;       
  myTim.TIM_ClockDivision = TIM_CKD_DIV1; 
  myTim.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4,&myTim); 
	
	TIM_ITConfig(TIM4,TIM_IT_Update, ENABLE ); //使能中断tim4
	TIM_Cmd(TIM4, ENABLE);                      //使能外设
	
}
void delay_ms(int time)
{
	j=time*1000;
	while(j!=0);
}
void delay_us(int time)
{
	j=time;
	while(j!=0);
}



 void TIM4_IRQHandler(void)
 {
	 j--;	 
		 
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update); //清中断
 }
