#include "delay.h"
int times;
int delay_init(void)
{
	if(SysTick_Config(72000)==1)//1ms产生中断
	{
		while(1);
	}
	return 0;
}

void SysTick_Handler(void)//中断处理函数
{
	
	times--;
	
	
}
void transVal(int delayTime)//接收值，控制延迟时间
{
	times=delayTime;
	while(times>0);
	
	
	
}
