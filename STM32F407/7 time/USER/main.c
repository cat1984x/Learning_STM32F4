#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "usart.h"
#include "time.h"


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init();
	TIM3_Int_Init(5000-1,8400-1);	//¼ÇÊý5000ÊÇ500ms

	while(1)
	{
		LED0=!LED0;
		delay_ms(200);
	}	
}




