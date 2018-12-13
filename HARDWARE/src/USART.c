
#include "USART.h"
u32 sr,tsr=0;
int ch;
float length,sum_length,ave_length;
void usart_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	myStruct.GPIO_Mode=GPIO_Mode_AF_PP;//�����������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_9;//enable����9,A9=���TXD
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOA,&myStruct);//enable gpioA��
	
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;
	myStruct.GPIO_Pin=GPIO_Pin_10;//enable����10,A10=����RXD
	GPIO_Init(GPIOA,&myStruct);
	
	
	USART_DeInit(USART1);
	USART_InitTypeDef myusart;
	myusart.USART_BaudRate=115200;//�����ʣ�9600
	myusart.USART_Parity=USART_Parity_No;//У�����ͣ���У��
	myusart.USART_WordLength=USART_WordLength_8b;//����λ��С��8λ
	myusart.USART_HardwareFlowControl=USART_HardwareFlowControl_None;//Ӳ������������
	myusart.USART_StopBits=USART_StopBits_1;//ֹͣλ���ȣ�1λ
	myusart.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_Init(USART1,&myusart);
	USART_Cmd(USART1,ENABLE);
}
void hc_sr04_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	myStruct.GPIO_Mode=GPIO_Mode_Out_PP;//�����������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_5;//enable����5,A5=�����
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOA,&myStruct);//enable gpioA��
	
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;
	myStruct.GPIO_Pin=GPIO_Pin_6;//enable����6,A6=�����
	GPIO_Init(GPIOA,&myStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//�жϷ��飬��һ��
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=TIM3_IRQn;//�ж���
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	keyconfig.NVIC_IRQChannelSubPriority=0;//�����ȼ�0
	NVIC_Init(&keyconfig);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);//RCC
	TIM_TimeBaseInitTypeDef myTim; 
  myTim.TIM_Period =1000-1;           //��Ƶϵ��
  myTim.TIM_Prescaler =72-1;       
  myTim.TIM_ClockDivision = TIM_CKD_DIV1; 
  myTim.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM3,&myTim);
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
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
void USART_IRQHandler(void)
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE)==1)
	ch=USART_ReceiveData(USART1);
	USART_SendData(USART1,ch);
	while(USART_GetFlagStatus(USART1,USART_IT_TXE)==0);
}




