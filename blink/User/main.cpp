/********************************** (C) COPYRIGHT *******************************
* File Name          : main.c
* Author             : WCH
* Version            : V1.0.0
* Date               : 2021/06/06
* Description        : Main program body.
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/*
 *@Note
 USART Print debugging routine:
 USART1_Tx(PA9).
 This example demonstrates using USART1(PA9) as a print debug port output.

*/

#include "debug.h"
#include <Led.h>

/* Global typedef */

/* Global define */

/* Global Variable */


/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
extern "C" int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);	
	printf("SystemClk:%d\r\n",SystemCoreClock);
	printf( "ChipID:%08x\r\n", DBGMCU_GetCHIPID() );
	printf("This is printf example\r\n");

    Led led_red(GPIOD, GPIO_Pin_12, RCC_APB2Periph_GPIOD);  // DS0
    Led led_green(GPIOD, GPIO_Pin_13, RCC_APB2Periph_GPIOD);    // DS1

	int i = 0;
	while(1)
    {
	    printf("blink i++=%d\n", i++);
	    Delay_Ms(500);

	    led_red.Set(); // �ߵ�ƽ������
	    led_green.Reset(); // �͵�ƽ������
        Delay_Ms(500);

        led_red.Reset();
        led_green.Set();
        Delay_Ms(500);
	}
}


// C++����������������������������ӡ�
// ��Ȼ����е���__libc_init_array��__libc_fini_array �Ҳ���������������
extern "C" void _init(void) {;}

/* Make sure you have C linkage when defining in c++ file */
extern "C"
void _fini()
{
    /* Either leave empty, or infinite loop here */
    while (true)
        __asm volatile ("NOP");
}
