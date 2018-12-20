
#include "USART.h"
u32 sr,tsr=0;
int ch;
float length,sum_length,ave_length;
void usart_Init()
{
	GPIO_InitTypeDef GPIO_InitStructure;                   //2.定义结构体
	USART_InitTypeDef USART_InitStructure;                                                     //3.初始化IO
	//NVIC_InitTypeDef NVIC_InitStructure;
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	 //RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	USART_DeInit(USART1); 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;    //推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9; //选择引脚
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//  引脚速度
	GPIO_Init(GPIOA, &GPIO_InitStructure); //4.使能IO
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;   //推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10; //选择引脚
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//  引脚速度
	GPIO_Init(GPIOA, &GPIO_InitStructure); //4.使能IO
  
	
USART_InitStructure.USART_BaudRate =115200;
USART_InitStructure.USART_WordLength = USART_WordLength_8b;
USART_InitStructure.USART_StopBits = USART_StopBits_1;
USART_InitStructure.USART_Parity = USART_Parity_No;
USART_InitStructure.USART_HardwareFlowControl =USART_HardwareFlowControl_None;
USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

USART_Init(USART1, &USART_InitStructure);

	USART_Cmd(USART1,ENABLE);
}
void hc_sr04_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure; 
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;    //推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6; //选择引脚
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//  引脚速度
	GPIO_Init(GPIOA, &GPIO_InitStructure); //4.使能IO
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;    //推挽输出
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5; //选择引脚
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;//  引脚速度
	GPIO_Init(GPIOA,&GPIO_InitStructure); //4.使能IO
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	GPIO_ResetBits(GPIOA,GPIO_Pin_6);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_DeInit(TIM3);
	TIM_TimeBaseInitTypeDef TIM_Basestructure;
	
	TIM_Basestructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_Basestructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_Basestructure.TIM_Period=1000-1;
	TIM_Basestructure.TIM_Prescaler=72-1;
	TIM_TimeBaseInit(TIM3,&TIM_Basestructure);
	TIM_ClearFlag(TIM3,TIM_FLAG_Update);  
	  TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
		
		 
		 NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); //中断分组，组1
	NVIC_InitTypeDef NVIC_keyInitStructure;
	NVIC_keyInitStructure.NVIC_IRQChannel=TIM3_IRQn; //中断线
	NVIC_keyInitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_keyInitStructure.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	NVIC_keyInitStructure.NVIC_IRQChannelSubPriority=0;//从优先级0
	NVIC_Init(&NVIC_keyInitStructure); 
	TIM_Cmd(TIM3,DISABLE);
}
void TIM3_IRQHandler(void)
{
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==1)
	{
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
		sr++;
	}
}
int gettime(void)
{
	tsr=0;
	tsr=sr*1000;
	tsr+=TIM_GetCounter(TIM3);
	return tsr;
}
float getlength(void)
{
	//int t1,t2;
	u32 hc_srtime=0;
	float hc_srlenth=0.0;
	float hc_srsum=0.0;
	int i=0;
	while(i<=5){
	GPIO_SetBits(GPIOA,GPIO_Pin_5);//???
	delay_us(15);
	GPIO_ResetBits(GPIOA,GPIO_Pin_5);
	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)!=1);
	TIM_SetCounter(TIM3,0);
	sr=0;
	TIM_Cmd(TIM3,ENABLE);
	while(GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)!=0);
	TIM_Cmd(TIM3,DISABLE);
	
	hc_srtime=gettime();
		hc_srlenth=(float)(hc_srtime/58.0);
		hc_srsum+=hc_srlenth;
		i++;
	
}
	hc_srlenth=hc_srsum/5.0;
	return hc_srlenth;
	}
int fputc(int ch,FILE *p)
{
	USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
	
}
/*void USART_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
	ch=USART_ReceiveData(USART1);
	USART_SendData(USART1,ch);
	while(USART_GetFlagStatus(USART1,USART_IT_TXE)==0);
}*/




