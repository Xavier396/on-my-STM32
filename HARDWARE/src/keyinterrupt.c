#include "keyinterrupt.h"
void GPIO_init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//启用浮空输入模式
	myStruct.GPIO_Pin=GPIO_Pin_2;//enable引脚2
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOC,&myStruct);//enable gpioC口
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);
}
void key_intrerr()
{
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line2;//中断在2线上
	keystru.EXTI_LineCmd=ENABLE;//enable中断
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//中断模式
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&keystru);//使能结构体
}
void keyinter_config() //配置中断控制器
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//中断分组，第一组
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI2_IRQn;//中断线
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	keyconfig.NVIC_IRQChannelSubPriority=0;//从优先级0
	NVIC_Init(&keyconfig);
}
void EXTI2_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line2)=)//等于啥不知道！
	{
	
	}
	if(GPIO_ReadInputData(GPIOC)==0)
	{
		//点亮一盏灯
	}
}
