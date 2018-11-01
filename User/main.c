#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
#include "tiktok.h"
#include "stdlib.h"
#include "PWM.h"
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


void delay_us(int time);
void delay_ms(int time);
int j;
int k;
int main(void)
{
	int temp ;
	//SystemInit();//���72M��ʱ��
	led_Init(); //��ʼ��io
	//delay_init();//1ms�ж�һ��
	key_intrerr();
	keyinter_config();
	GPIO_init();
	timeinit();
	pwm_init();
	
	//key_Init(); //��ʼ�������
	

	//GPIO_SetBits(GPIOE,P0|P2|P5);
	while (1)
	{
		
		for(temp=0;temp<10000;temp=temp+50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(20);
			
		}
		for(temp=10000;temp>0;temp=temp-50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(20);
			
		}
		
	}
}


