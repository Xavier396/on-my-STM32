#include "key.h"
void key_Init(void)
{
RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//RCCʱ�ӿ���
	GPIO_InitTypeDef myStruct;//��ʼ��io
	myStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;//���ø�������ģʽ
	myStruct.GPIO_Pin=GPIO_Pin_3;//enable����3
	myStruct.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOC,&myStruct);//enable gpioC��
}
