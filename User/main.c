#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
#include "tiktok.h"
#include "stdlib.h"
#include "PWM.h"
#include "motor.h"
#include "USART.h"
#include "stdio.h"
#define P0 GPIO_Pin_0
#define P1 GPIO_Pin_1
#define P2 GPIO_Pin_2
#define P3 GPIO_Pin_3
#define P4 GPIO_Pin_4
#define P5 GPIO_Pin_5
#define P6 GPIO_Pin_6
#define P7 GPIO_Pin_7
#define All GPIO_Pin_All
#define E GPIOE


//void delay_us(int time);
//void delay_ms(int time);
int j;
int k;
void stop(int x);
void breath(void);

int main(void)
{
	//int i;
	//SystemInit();//���72M��ʱ��
	//led_Init(); //��ʼ��io
	//delay_init();//1ms�ж�һ��
	//speak_init();
	//motor_Init();
	//GPIO_init();
	//key_intrerr();
	//keyinter_config();

	//timeinit();//��ʱ��ʼ��
	//pwm_init();//pwm
	usart_Init();
	 //hc_sr04_init();
	//key_Init(); //��ʼ�������
	
	//TIM_SetCompare2(TIM3,1);//1/10000С��10%������Ĭ��ͣת
	//GPIO_SetBits(GPIOC,GPIO_Pin_4);
	printf("��ʼ���ɹ�\n");
	while (1)
	{
		/*if(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==1)
		{
			i++;
			i=USART_ReceiveData(USART1);
			USART_SendData(USART1,i);
			while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==0)*/
		float srlength=0;
		srlength=getlength();
		printf("�����ǣ�%fCM\n",srlength);
		delay_us(15);
		}
	
}
void breath()//������
{
	int temp ;
	for(temp=0;temp<10000;temp=temp+50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}
		for(temp=10000;temp>0;temp=temp-50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}
	}
		
		/*for(temp=10000;temp>0;temp=temp-50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}*/




