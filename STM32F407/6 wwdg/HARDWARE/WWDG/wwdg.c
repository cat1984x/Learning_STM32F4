#include "wwdg.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_wwdg.h"
#include "led.h"



u8 WWGD_CNT=0x7F;

void WWDG_init(u8 tr,u8 wr,u32 fprer)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);//WWDGû�ж���ʱ�ӣ���Ҫʹ��ʱ��
	
	WWGD_CNT=tr&WWGD_CNT;//ֻ�е�7λ��Ч
	WWDG_SetPrescaler(fprer);
	WWDG_SetWindowValue(wr);	
	WWDG_SetCounter(WWGD_CNT);
	WWDG_Enable(WWGD_CNT);
	
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn;//�ж�ͨ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3;//��ռ���ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelSubPriority =3;		//�����ȼ�3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;			//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);	
	
	WWDG_ClearFlag();
	WWDG_EnableIT();
}

void WWDG_IRQHandler(void)//�ж��п�������������Ҫ����
{
	WWDG_SetCounter(WWGD_CNT);//�����ι��������0x3f��λ
	WWDG_ClearFlag();
	LED1=!LED1;
}



