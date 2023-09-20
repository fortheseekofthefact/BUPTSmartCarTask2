#include "stm32f10x.h"                  // Device header

void LightSensor_Init (uint16_t GPIO_Pin)
{

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin);
	
}

uint8_t LightSensor_Get (void)
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}
