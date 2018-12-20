#include"AD.h"
#include "stdio.h"
void AD_Init(void)
{
	GPIO_InitTypeDef myDef;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_ADC1,ENABLE);//72MHzʱ��
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//6��Ƶ�����12MHzʱ��
	myDef.GPIO_Mode=GPIO_Mode_AIN;//�����������ģʽ
	myDef.GPIO_Pin=GPIO_Pin_2;//enable����
	myDef.GPIO_Speed=GPIO_Speed_50MHz;//�ٶ�
	GPIO_Init(GPIOA,&myDef);//enable gpioA,2��
	
		
	ADC_InitTypeDef myADC;
	ADC_DeInit(ADC1);
	myADC.ADC_Mode=ADC_Mode_Independent;//�����ڶ���ģʽ��
	myADC.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//�����������
	myADC.ADC_DataAlign=ADC_DataAlign_Right;//�����Ҷ���
	myADC.ADC_NbrOfChannel=2;
	myADC.ADC_ScanConvMode=DISABLE;//�����ڵ���ģʽ��
	
	ADC_Cmd(ADC1,ENABLE);
	
	ADC_ResetCalibration(ADC1);//��λУ׼
	while(ADC_GetResetCalibrationStatus(ADC1)==1);//�ȴ���λУ׼���
	ADC_StartCalibration(ADC1);//adc1У׼
	while(ADC_GetCalibrationStatus(ADC1)==1);//�ȴ�У׼���
	ADC_Init(ADC1,&myADC);

	
}
u16 get_ADC(u8 ch)
{
	u32 adcVal=0;

	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5);//���ò�������
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//��ʼ����
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//�ȴ���������
	adcVal=ADC_GetConversionValue(ADC1);
	return adcVal;
	/*VOUT=(adcVal/4095)*3.3;//ADC_GetConversionValue()adc1��ֵ,VOUT��������Ľ��
	printf("��ѹ��ֵΪ:%lf",VOUT);*/
}
