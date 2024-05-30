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

    Led led1(GPIOA, GPIO_Pin_7, RCC_APB2Periph_GPIOA);
    Led led2(GPIOA, GPIO_Pin_8, RCC_APB2Periph_GPIOA);

    led1.Init();
    led2.Init();
	int i = 0;
	while(1)
    {
	    printf("blink i++=%d\n", i++);
	    Delay_Ms(500);

        led1.Open();
        led2.Close();
        Delay_Ms(500);

        led1.Close();
        led2.Open();
        Delay_Ms(500);
	}
}

