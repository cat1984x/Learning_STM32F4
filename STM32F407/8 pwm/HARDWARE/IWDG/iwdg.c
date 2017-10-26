#include "iwdg.h"
#include "stm32f4xx_iwdg.h"

void IWDG_init(u8 prer,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prer);//IWDG_Prescaler
	IWDG_SetReload(rlr);//Reload
	IWDG_ReloadCounter();
	IWDG_Enable();
}

void IWDG_Feed(void)
{
	IWDG_ReloadCounter();
}
