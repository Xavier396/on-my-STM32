#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
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

#define yhj main
void delay(int time);
int yhj(void)
{
	SystemInit();//���72M��ʱ��
	led_Init(); //��ʼ��io
	delay_init();//1ms�ж�һ��
	key_intrerr();
	keyinter_config();
	GPIO_init();
	
	//key_Init(); //��ʼ�������
	

	//GPIO_SetBits(GPIOE,P0|P2|P5);
	while (1)
	{
		if(FLAG==1)
		{
			walkk();
		}
		if(FLAG==2)
		{
		GPIO_ResetBits(E,All);
		}
	}
}
void delay(int time)
{
	int x;
	for (x = 0; x < time; x++)
	{
		x = x + 0;
	}
}

