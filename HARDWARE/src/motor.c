#include "motor.h"

void motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_Out_PP;//�����������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_All;//enable����
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOB,&myStruct);//enable gpioB��
}
