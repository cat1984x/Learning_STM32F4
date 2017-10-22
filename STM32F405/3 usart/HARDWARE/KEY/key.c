#include "key.h"
#include "delay.h"

void KEY_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB|RCC_AHB1Periph_GPIOC,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);//��ʼ��PC7��8
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��PB8

}


u8 KEY_Scan(u8 mode)
{
	static u8 key_up=1;//�����ɿ�����
	if(mode)key_up=1;//modeΪ1���������������
	if(key_up&&(KEY0==0||KEY1==0||START==1))
	{
		delay_ms(10);//ȥ����
		key_up=0;
		if(KEY0==0) return 1;
		else if(KEY1==0) return 2;
		else if(START==1) return 3;	
	}
	else if(KEY0==1&&KEY1==1&&START==0) 
		key_up=1;
	return 0;//�ް���

}
