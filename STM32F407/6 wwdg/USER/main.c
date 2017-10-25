#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "exti.h"
#include "usart.h"
#include "wwdg.h"


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
	LED0=0;
	delay_ms(300);//延时，重启看到灯亮
	
	WWDG_init(0x7F,0x5F,WWDG_Prescaler_8);
	while(1)
	{
		LED0=1;
		printf("OK\r\n");
		delay_ms(1000);
	}	
}




