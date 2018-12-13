#include "keyinterrupt.h"
#include "tiktok.h"
int i=0;
void GPIO_init()
{
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_2;//enable����2
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOC,&myStruct);//enable gpioC��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource2);
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line2;//�ж���2����
	keystru.EXTI_LineCmd=ENABLE;//enable�ж�
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�ģʽ
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&keystru);//ʹ�ܽṹ��
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//�жϷ��飬��һ��
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI2_IRQn;//�ж���
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	keyconfig.NVIC_IRQChannelSubPriority=0;//�����ȼ�0
	NVIC_Init(&keyconfig);
}
void key_intrerr()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_1;//enable����1
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOC,&myStruct);//enable gpioC��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource1);
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line1;//�ж���1����
	keystru.EXTI_LineCmd=ENABLE;//enable�ж�
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�ģʽ
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&keystru);//ʹ�ܽṹ��
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//�жϷ��飬��һ��
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI1_IRQn;//�ж���
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	keyconfig.NVIC_IRQChannelSubPriority=0;//�����ȼ�0
	NVIC_Init(&keyconfig);
}
void keyinter_config() //�����жϿ�����
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_0;//enable����0
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOC,&myStruct);//enable gpioC��
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource0);
	
	EXTI_InitTypeDef keystru;
	keystru.EXTI_Line=EXTI_Line0;//�ж���1����
	keystru.EXTI_LineCmd=ENABLE;//enable�ж�
	keystru.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�ģʽ
	keystru.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	EXTI_Init(&keystru);//ʹ�ܽṹ��
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);//�жϷ��飬��һ��
	NVIC_InitTypeDef keyconfig;
	keyconfig.NVIC_IRQChannel=EXTI0_IRQn;//�ж���
	keyconfig.NVIC_IRQChannelCmd=ENABLE;
	keyconfig.NVIC_IRQChannelPreemptionPriority=0;//��ռ���ȼ�0
	keyconfig.NVIC_IRQChannelSubPriority=0;//�����ȼ�0
	NVIC_Init(&keyconfig);
}

//���ж�ʽ��ʱ����׼ȷ
void safe_delay(int time)
{
	int temp;
	for(temp=0;temp<time;temp++);
}
void walkk()//����ƺ���
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

void EXTI2_IRQHandler(void)//�жϴ�����S3
{
	
	
	if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)==0)
	{
		safe_delay(180000);//����
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_2)==0)
			{
				//TODO:��������Ӵ����Կ��Ƶ��
			TIM_SetCompare2(TIM3,1);
			GPIO_SetBits(GPIOC,GPIO_Pin_4);
		}
		EXTI_ClearITPendingBit(EXTI_Line2);
	}
	
}

void EXTI1_IRQHandler(void)//�жϴ�����S2
{
if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)==0)
	{
		safe_delay(180000);
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_1)==0)
			{
				//TODO:��������Ӵ����Կ��Ƶ��
				TIM_SetCompare2(TIM3,8000);
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
}
void EXTI0_IRQHandler(void)//�жϴ�����S1
{
if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)==0)
	{
		safe_delay(180000);
		if(GPIO_ReadOutputDataBit(GPIOC,GPIO_Pin_0)==0)
			{
				//TODO:��������Ӵ����Կ��Ƶ��
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
void breath_mat()//������
{
	int temp ;
	for(temp=250;temp<10000;temp=temp+50)
		{
			
			TIM_SetCompare2(TIM3,temp);	
			delay_ms(10);
			
		}
	}


