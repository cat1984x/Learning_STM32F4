#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "led.h"
#include "usart.h"

int main(void)
{ 
	u8 len;//�ַ�����
	u16 times=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	uart_init(115200);
	LED_Init();
	//LED0=0;
	while(1)
	{
		if(USART_RX_STA&0x8000)//�Ƿ�������
		{
			len=USART_RX_STA&0x3FFF;
			printf("\n�����͵���ϢΪ:\n");
			for(u8 i=0;i<len;i++)
			{				
				USART_SendData(USART1,USART_RX_BUF[i]);
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
			}
			printf("\n");
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%30==0)
				LED1=!LED1;
			delay_ms(10);		
		}
	}	
}


