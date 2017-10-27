#include "stm32f4xx.h"
#include "delay.h"
#include "key.h"
#include "beep.h"
#include "led.h"
#include "usart.h"
#include "time.h"
#include "pwm.h"


int main(void)
{
	u16 led0pwmval=0;
	u8 dir=1;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init(168);
	LED_Init();
	TIM14_PWM_Init(500-1,84-1);

	while(1)
	{
		delay_ms(3);
		if(dir)
			led0pwmval++;
		else
			led0pwmval--;
		if(led0pwmval>300)
			dir=0;
		if(led0pwmval==0)
			dir=1;
		TIM_SetCompare1(TIM14,led0pwmval);
		
	}	
}




