#include "pwm.h"



void TIM14_PWM_Init(u32 arr,u32 psc)
{
	
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;	
	
	RCC_AHB1PeriphClockCmd (RCC_AHB1Periph_GPIOF,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM14 ,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;	
	GPIO_Init(GPIOF, &GPIO_InitStructure);
	
	GPIO_PinAFConfig(GPIOF,GPIO_PinSource9,GPIO_AF_TIM14);	
	
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period=arr;
	TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
	//TIM_TimeBaseInitStructure.TIM_RepetitionCounter 高级定时器用	
	TIM_TimeBaseInit(TIM14, &TIM_TimeBaseInitStructure);	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;	
	TIM_OC1Init(TIM14,&TIM_OCInitStructure);//PWM模式
	
	TIM_OC1PreloadConfig(TIM14,TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM14,ENABLE);//自动重装载使能
	TIM_Cmd(TIM14, ENABLE);
}

