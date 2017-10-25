#include "key.h"
#include "led.h"
#include "exti.h"
#include "delay.h"
#include "beep.h"
#include "stm32f4xx_exti.h"

void EXTI_init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;	
	NVIC_InitTypeDef NVIC_InitStructure;
	
	KEY_Init();//按键对应IO初始化
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG,ENABLE); //使能SYSCFG
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOA,EXTI_PinSource0);//连接中断线
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource3);
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource4);
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Rising;	
	EXTI_Init(&EXTI_InitStructure);	
	
	EXTI_InitStructure.EXTI_Line=EXTI_Line2 | EXTI_Line3 | EXTI_Line4;
	EXTI_InitStructure.EXTI_LineCmd=ENABLE;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;	
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI2_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	

}
void EXTI0_IRQHandler(void)
{
		delay_ms(10);//去抖动
		if(WK_UP==1) 
			BEEP=!BEEP;
		EXTI_ClearITPendingBit(EXTI_Line0);
}
void EXTI2_IRQHandler(void)
{
		delay_ms(10);//去抖动
		if(KEY2==0) 
			LED0=!LED0;
		EXTI_ClearITPendingBit(EXTI_Line2);
}

void EXTI3_IRQHandler(void)
{
		delay_ms(10);//去抖动
		if(KEY1==0) 
			LED1=!LED1;
		EXTI_ClearITPendingBit(EXTI_Line3);
}
void EXTI4_IRQHandler(void)
{
		delay_ms(10);//去抖动
		if(KEY0==0) 
		{
			LED0=!LED0;
			LED1=!LED1;
		}
		EXTI_ClearITPendingBit(EXTI_Line4);
}
