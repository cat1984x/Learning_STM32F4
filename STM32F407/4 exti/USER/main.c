#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "exti.h"
#define CONTINUE 1
#define NON_CONTINUE 0


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	KEY_Init();
	LED_Init();
	BEEP_Init();
	EXTI_init();
	LED0=0;
	while(1)
	{
	}	
}




