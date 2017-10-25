#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "exti.h"
#include "usart.h"


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	uart_init(115200);
	KEY_Init();
	LED_Init();
	BEEP_Init();
	EXTI_init();
	LED0=0;
	while(1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}	
}




