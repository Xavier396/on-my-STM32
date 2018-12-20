#include"AD.h"
#include "stdio.h"
void AD_Init(void)
{
	GPIO_InitTypeDef myDef;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_ADC1,ENABLE);//72MHz时钟
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);//6分频，获得12MHz时钟
	myDef.GPIO_Mode=GPIO_Mode_AIN;//启用推挽输出模式
	myDef.GPIO_Pin=GPIO_Pin_2;//enable引脚
	myDef.GPIO_Speed=GPIO_Speed_50MHz;//速度
	GPIO_Init(GPIOA,&myDef);//enable gpioA,2口
	
		
	ADC_InitTypeDef myADC;
	ADC_DeInit(ADC1);
	myADC.ADC_Mode=ADC_Mode_Independent;//工作在独立模式下
	myADC.ADC_ExternalTrigConv=ADC_ExternalTrigConv_None;//软件触发启动
	myADC.ADC_DataAlign=ADC_DataAlign_Right;//数据右对齐
	myADC.ADC_NbrOfChannel=2;
	myADC.ADC_ScanConvMode=DISABLE;//工作在单次模式下
	
	ADC_Cmd(ADC1,ENABLE);
	
	ADC_ResetCalibration(ADC1);//复位校准
	while(ADC_GetResetCalibrationStatus(ADC1)==1);//等待复位校准完成
	ADC_StartCalibration(ADC1);//adc1校准
	while(ADC_GetCalibrationStatus(ADC1)==1);//等待校准完成
	ADC_Init(ADC1,&myADC);

	
}
u16 get_ADC(u8 ch)
{
	u32 adcVal=0;

	ADC_RegularChannelConfig(ADC1,ch,1,ADC_SampleTime_239Cycles5);//设置采样规则
	ADC_SoftwareStartConvCmd(ADC1,ENABLE);//开始采样
	while(!ADC_GetFlagStatus(ADC1,ADC_FLAG_EOC));//等待采样结束
	adcVal=ADC_GetConversionValue(ADC1);
	return adcVal;
	/*VOUT=(adcVal/4095)*3.3;//ADC_GetConversionValue()adc1的值,VOUT就是输出的结果
	printf("电压的值为:%lf",VOUT);*/
}
