#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
#include "tiktok.h"
#include "stdlib.h"
#include "PWM.h"
#include "motor.h"
#include "motor_Control.h"
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
	
	SystemInit();//获得72M的时种
	led_Init(); //初始化io
	//delay_init();//1ms中断一次
	speak_init();
	motor_Init();
	GPIO_init();
	key_intrerr();
	keyinter_config();

	timeinit();//延时初始化
	pwm_init();//pwm
	//PORT_init();
	//keys_intrerr();
	//keyinters_config();
	
	//key_Init(); //初始化输入端
	
	TIM_SetCompare2(TIM3,1);//1/10000小于10%，所以默认停转
	
	while (1)
	{
		
	}
}
void breath()//呼吸灯
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




