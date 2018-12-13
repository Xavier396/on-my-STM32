#include "keyinterrupt.h"
#include "tiktok.h"
int i=0;
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
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line2;//中断在2线上
	keystru.EXTI_LineCmd=ENABLE;//enable中断
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//中断模式
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&keystru);//使能结构体
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//中断分组，第一组
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI2_IRQn;//中断线
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	keyconfig.NVIC_IRQChannelSubPriority=0;//从优先级0
	NVIC_Init(&keyconfig);
}
void key_intrerr()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//启用浮空输入模式
	myStruct.GPIO_Pin=GPIO_Pin_1;//enable引脚1
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOC,&myStruct);//enable gpioC口
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource1);
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line1;//中断在1线上
	keystru.EXTI_LineCmd=ENABLE;//enable中断
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//中断模式
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&keystru);//使能结构体
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//中断分组，第一组
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI1_IRQn;//中断线
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	keyconfig.NVIC_IRQChannelSubPriority=0;//从优先级0
	NVIC_Init(&keyconfig);
}
void keyinter_config() //配置中断控制器
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCC时钟开启
	GPIO_InitTypeDef myStruct;//初始化io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//启用浮空输入模式
	myStruct.GPIO_Pin=GPIO_Pin_0;//enable引脚0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOC,&myStruct);//enable gpioC口
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource0);
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line0;//中断在1线上
	keystru.EXTI_LineCmd=ENABLE;//enable中断
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//中断模式
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	EXTI_Init(&keystru);//使能结构体
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//中断分组，第一组
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI0_IRQn;//中断线
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//先占优先级0
	keyconfig.NVIC_IRQChannelSubPriority=0;//从优先级0
	NVIC_Init(&keyconfig);
}

//非中断式延时，不准确
void safe_delay(int time)
{
	int temp;
	for(temp=0;temp<time;temp++);
}
void walkk()//跑马灯函数
{
	
	while(1){
		GPIO_SetBits(GPIOE,GPIO_Pin_0);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_0);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_1);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_1);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_2);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_2);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_3);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_3);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_4);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_4);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_5);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_6);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_6);
		safe_delay(1800000);
		GPIO_SetBits(GPIOE,GPIO_Pin_7);
		safe_delay(1800000);
		GPIO_ResetBits(GPIOE,GPIO_Pin_7);
		safe_delay(1800000);
}
}

void EXTI2_IRQHandler(void)//中断处理函数S3
{
	
	
	if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)==0)
	{
		safe_delay(180000);//消抖
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)==0)
			{
				//TODO:在这里添加代码以控制电机
			TIM_SetCompare2(TIM3,1);
			GPIO_SetBits(GPIOC,GPIO_Pin_4);
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
	
}

void EXTI1_IRQHandler(void)//中断处理函数S2
{
if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)==0)
	{
		safe_delay(180000);
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)==0)
			{
				//TODO:在这里添加代码以控制电机
				TIM_SetCompare2(TIM3,8000);
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
void EXTI0_IRQHandler(void)//中断处理函数S1
{
if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)==0)
	{
		safe_delay(180000);
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)==0)
			{
				//TODO:在这里添加代码以控制电机
				int i=200;
				GPIO_ResetBits(GPIOC,GPIO_Pin_4);
				while(1)
		{
			
			TIM_SetCompare2(TIM3,i);
				i+=70;
			delay_us(10);
			
		}
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
}
void breath_mat()//呼吸灯
{
	int temp ;
	for(temp=250;temp<10000;temp=temp+50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}
	}


