#include "led.h"
#include "key.h"
#include "delay.h"
#include "keyinterrupt.h"
#include "tiktok.h"
#include "stdlib.h"
#include "PWM.h"
#include "motor.h"
#include "USART.h"
#include "AD.h"
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
#define C GPIOC


//void delay_us(int time);
//void delay_ms(int time);
int inn,j;
int k;
u32 adcVal;
double VOUT,lllll;
void stop(int x);
void breath(void);
void battery_Check(double volta);

int main(void)
{
	//int i;
	//SystemInit();//获得72M的时种
	led_Init(); //初始化io
	//delay_init();//1ms中断一次
	//speak_init();
	//motor_Init();
	//GPIO_init();
	//key_intrerr();
	//keyinter_config();

	//timeinit();//延时初始化
	//pwm_init();//pwm
	usart_Init();
	 //hc_sr04_init();
	//key_Init(); //初始化输入端
	AD_Init();//初始化AD
	
	printf("初始化成功\n");
	while (1)
	{
		
		for(inn=0;inn<1000;inn++)
		{
		adcVal=get_ADC(ADC_Channel_2);
		VOUT=(adcVal/4096.0)*3.3;
			lllll+=VOUT;
		
		}
		lllll/=1000;
		
		printf("输出电压的值为:%lf\n",lllll);
		
		
		safe_delay(1000000);
		battery_Check(lllll);
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
void battery_Check(double volta)
{
	if(volta<1.50)
	{
		GPIO_SetBits(C,P4);
	}
	else if(volta>=1.50)
	{
		GPIO_ResetBits(C,P4);
	}
}
		
		/*for(temp=10000;temp>0;temp=temp-50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}*/




