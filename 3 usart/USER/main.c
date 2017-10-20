#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#define CONTINUE 1
#define NON_CONTINUE 0


int main(void)
{
	u8 key;
	delay_init(168);
	KEY_Init();
	LED_Init();
	BEEP_Init();
	LED0=0;
	while(1)
	{
		key=KEY_Scan(NON_CONTINUE);
		if(key)
		{
			switch(key)
			{
				case KEY0_PRES:
					LED0=!LED0;
					LED1=!LED1;
					break;				
				case KEY1_PRES:
					LED1=!LED1;
					break;
				case KEY2_PRES:
					LED0=!LED0;
					break;
				case WK_UP_PRES:					
					BEEP=!BEEP;
					break;			
			}		
		}
		else
				delay_ms(10);
	}	
}




