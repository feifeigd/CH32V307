﻿/********************************** (C) COPYRIGHT *******************************
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); // 中断优先级分组2
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);	
	printf("SystemClk:%lu\r\n",SystemCoreClock);
	printf( "ChipID:%08lx\r\n", DBGMCU_GetCHIPID() );
	printf("This is printf example\r\n");
	int i = 0;
	while(1)
    {
	    printf("This is printf example i=%d\r\n", i++);

	}
}

// C++工程添加下面两个函数，才能链接。
// 不然汇编中调用__libc_init_array和__libc_fini_array 找不到下面两个函数
extern "C" void _init(void) {;}

/* Make sure you have C linkage when defining in c++ file */
extern "C"
void _fini()
{
    /* Either leave empty, or infinite loop here */
    while (true)
        __asm volatile ("NOP");
}



