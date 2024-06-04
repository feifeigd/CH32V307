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

#include <debug.h>
#include <Beep.h>
#include <Keys.h>
#include <Led.h>
#include <Exti.h>

/* Global typedef */

/* Global define */

/* Global Variable */

    Led led_red(GPIOD, GPIO_Pin_12);  // DS0
    Led led_green(GPIOD, GPIO_Pin_13);// DS1
    Keys keys;
	Beep beep{GPIOD, GPIO_Pin_11};

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

	// 开启时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    beep.Init();
    led_red.Init();
    led_green.Init();

    keys.Init();

    // 中断
    Exti exti;
    exti.Init();

	int i = 0;
	while(1)
    {
	    printf("beep i++=%d\n", i++);
	    Delay_Ms(1000);

	    /*switch(keys.key_scan(0)){
	    case Keys::PRESSED_NONE:
	        Delay_Ms(10);
	        break;
	    case Keys::PRESSED_KEY0:
	        led_red.toggle();
	        led_green.toggle();
	        break;
	    case Keys::PRESSED_KEY1:
	        led_green.toggle(); //
	        break;
	    case Keys::PRESSED_KEYUP:
	        beep.toggle();
	        break;
	    }*/
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

// 中断服务函数

void KEY0_INT_IRQHandler(){
    auto exti_line = KEY0_INT_EXTI_Line;
    if(SET == EXTI_GetITStatus(exti_line)){// 是否为中断线x的中断
        Delay_Ms(20); // 消抖
        if(0 == keys.key0_.ReadInputBit()){
            led_red.toggle();
            led_green.toggle();
        }
    }
    EXTI_ClearITPendingBit(exti_line);
}

void KEY1_INT_IRQHandler(){
    auto exti_line = KEY1_INT_EXTI_Line;
    if(SET == EXTI_GetITStatus(exti_line)){// 是否为中断线x的中断
        Delay_Ms(20); // 消抖
        if(0 == keys.key0_.ReadInputBit()){
            led_green.toggle();
        }
    }
    EXTI_ClearITPendingBit(exti_line);
}

void WKUP_INT_IRQHandler(){
    auto exti_line = WKUP_INT_EXTI_Line;
    if(SET == EXTI_GetITStatus(exti_line)){// 是否为中断线x的中断
        Delay_Ms(20); // 消抖
        if(0 == keys.key0_.ReadInputBit()){
            beep.toggle();
        }
    }
    EXTI_ClearITPendingBit(exti_line);
}
