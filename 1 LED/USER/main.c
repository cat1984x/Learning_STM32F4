#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

int main(void)
{

	delay_init(168);
	LED_Init();
	while(1)
	{
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
	}
	
}

