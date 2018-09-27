#include "led.h"
#include "key.h"
#include "delay.h"
#define P0 GPIO_Pin_0
#define P1 GPIO_Pin_1
#define P2 GPIO_Pin_2
#define P3 GPIO_Pin_3
#define P4 GPIO_Pin_4
#define P5 GPIO_Pin_5
#define P6 GPIO_Pin_6
#define P7 GPIO_Pin_7
#define E GPIOE

#define yhj main
void delay(int time);
int yhj(void)
{
	SystemInit();//获得72M的时种
	led_Init(); //初始化io
	delay_init();//1ms中断一次
	//key_Init(); //初始化输入端
	

	//GPIO_SetBits(GPIOE,P0|P2|P5);
	while (1)
	{
		GPIO_SetBits(E,P0);
		transVal(100);
		GPIO_ResetBits(E,P0);
		transVal(100);
		GPIO_SetBits(E,P1);
		transVal(100);
		GPIO_ResetBits(E,P1);
		transVal(100);
		GPIO_SetBits(E,P2);
		transVal(100);
		GPIO_ResetBits(E,P2);
		transVal(100);
		GPIO_SetBits(E,P3);
		transVal(100);
		GPIO_ResetBits(E,P3);
		transVal(100);
		GPIO_SetBits(E,P4);
		transVal(100);
		GPIO_ResetBits(E,P4);
		transVal(100);
		GPIO_SetBits(E,P5);
		transVal(100);
		GPIO_ResetBits(E,P5);
		transVal(100);
		GPIO_SetBits(E,P6);
		transVal(100);
		GPIO_ResetBits(E,P6);
		transVal(100);
		GPIO_SetBits(E,P7);
		transVal(100);
		GPIO_ResetBits(E,P7);
		transVal(100);
		
		
		}
		/*else if(GPIO_ReadInputDataBit(GPIOC,P3)!=0)
	{
		GPIO_ResetBits(GPIOE,P5|P0);
	}*/
	}
void delay(int time)
{
	int x;
	for (x = 0; x < time; x++)
	{
		x = x + 0;
	}
}

//GPIO_ResetBits(GPIOE,GPIO_Pin_All);
/*GPIO_SetBits(GPIOE,GPIO_Pin_0|GPIO_Pin_2|GPIO_Pin_4|GPIO_Pin_6);
	GPIO_SetBits(GPIOE,GPIO_Pin_1|GPIO_Pin_3|GPIO_Pin_5|GPIO_Pin_7);*/
