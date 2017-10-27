#include "wwdg.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_wwdg.h"
#include "led.h"



u8 WWGD_CNT=0x7F;

void WWDG_init(u8 tr,u8 wr,u32 fprer)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);//WWDG没有独立时钟，需要使能时钟
	
	WWGD_CNT=tr&WWGD_CNT;//只有低7位有效
	WWDG_SetPrescaler(fprer);
	WWDG_SetWindowValue(wr);	
	WWDG_SetCounter(WWGD_CNT);
	WWDG_Enable(WWGD_CNT);
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;//中断通道
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//抢占优先级3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//子优先级3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);	
	
	WWDG_ClearFlag();
	WWDG_EnableIT();
}

void WWDG_IRQHandler(void)//中断中可以用来保存重要数据
{
	WWDG_SetCounter(WWGD_CNT);//如果不喂狗，将在0x3f复位
	WWDG_ClearFlag();
	LED1=!LED1;
}



