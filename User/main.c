#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
#include "tiktok.h"
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
	SystemInit();//获得72M的时种
	led_Init(); //初始化io
	delay_init();//1ms中断一次
	key_intrerr();
	keyinter_config();
	GPIO_init();
	timeinit();
	
	//key_Init(); //初始化输入端
	

	//GPIO_SetBits(GPIOE,P0|P2|P5);
	while (1)
	{
		delay_us(500000);
		GPIO_SetBits(E,P3);
		delay_us(500000);
		GPIO_ResetBits(E,P3);
		
	}
}


