#ifndef __IWDG_H
#define __IWDG_H

#include "stm32f4xx.h"
void IWDG_init(u8 prer,u16 rlr);
void IWDG_Feed(void);

#endif
