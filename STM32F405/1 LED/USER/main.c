#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"

int main(void)
{
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	delay_init(16);
	LED_Init();
	while(1)
	{
		/*
		//�⺯������
		GPIO_ResetBits(GPIOF,GPIO_Pin_9);
		GPIO_SetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		GPIO_SetBits(GPIOF,GPIO_Pin_9);
		GPIO_ResetBits(GPIOF,GPIO_Pin_10);
		delay_ms(500);
		*/
		
		
		//λ������
		LED0=0;//����
		//LED1=1;
		delay_ms(500);
		LED0=1;
		//LED1=0;
		delay_ms(500);
		
		
		/*
		//�Ĵ�������
		GPIOF->BSRRH= GPIO_Pin_9;//RESET 0
		GPIOF->BSRRL= GPIO_Pin_10;//SET  1
		delay_ms(1000);
		GPIOF->BSRRL= GPIO_Pin_9;
		GPIOF->BSRRH= GPIO_Pin_10;
		delay_ms(1000);
		*/
	}
	
}

