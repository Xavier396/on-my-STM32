#include "delay.h"
int times;
int delay_init(void)
{
	if(SysTick_Config(72000)==1)//1ms�����ж�
	{
		while(1);
	}
	return 0;
}

void SysTick_Handler(void)//�жϴ�����
{
	
	times--;
	
	
}
void transVal(int delayTime)//����ֵ�������ӳ�ʱ��
{
	times=delayTime;
	while(times>0);
	
	
	
}
