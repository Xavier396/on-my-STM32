#include "tiktok.h"
void timeinit(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //����1
	NVIC_InitTypeDef tiktokConfig;
	tiktokConfig.NVIC_IRQChannel=TIM4_IRQn; //�ж���4
	tiktokConfig.NVIC_IRQChannelCmd=ENABLE;
	tiktokConfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	tiktokConfig.NVIC_IRQChannelSubPriority=2;//�����ȼ�2
	NVIC_Init(&tiktokConfig); 
	
  
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4,ENABLE);//ʹ��RCC
  TIM_TimeBaseInitTypeDef myTim; 
  myTim.TIM_Period =8-1;           //��Ƶϵ��
  myTim.TIM_Prescaler = 9-1;       
  myTim.TIM_ClockDivision = TIM_CKD_DIV1; 
  myTim.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM4,&myTim); 
	
	TIM_ITConfig(TIM4,TIM_IT_Update, ENABLE ); //ʹ���ж�tim4
	TIM_Cmd(TIM4, ENABLE);                      //ʹ������
	
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
		 
		TIM_ClearITPendingBit(TIM4,TIM_IT_Update); //���ж�
 }
