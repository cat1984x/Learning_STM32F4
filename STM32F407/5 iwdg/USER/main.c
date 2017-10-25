#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "exti.h"
#include "usart.h"
#include "iwdg.h"


int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	uart_init(115200);
	KEY_Init();
	LED_Init();
	BEEP_Init();
	EXTI_init();
	printf("BOOTING\r\n");
	delay_ms(100);//延时，重启key看到灯闪烁
	LED0=0;
	IWDG_init(4,500);
	while(1)
	{
		printf("OK\r\n");
		delay_ms(1000);
	}	
}




