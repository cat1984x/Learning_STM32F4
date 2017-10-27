#ifndef __TIME_H
#define __TIME_H
#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"
#include "led.h"

void TIM3_Int_Init(u16 arr,u16 psc);
void TIM3_IRQHandler (void);

#endif
