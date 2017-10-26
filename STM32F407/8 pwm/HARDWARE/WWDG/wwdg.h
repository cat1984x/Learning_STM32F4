#ifndef __WWDG_H
#define __WWDG_H
#include "stm32f4xx.h"

void WWDG_init(u8 tr,u8 wr,u32 fprer);
void WWDG_IRQHandler(void);


#endif

