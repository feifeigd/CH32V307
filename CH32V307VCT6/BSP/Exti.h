#pragma once

/*
 * Exti.h
 *
 *  Created on: Jun 3, 2024
 *      Author: PC
 */

#include <ch32v30x.h>

// 中断服务函数
#define KEY0_INT_IRQHandler  EXTI1_IRQHandler
#define KEY1_INT_IRQHandler  EXTI9_5_IRQHandler
#define WKUP_INT_IRQHandler  EXTI0_IRQHandler

// 在main中实现
void KEY0_INT_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void KEY1_INT_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));
void WKUP_INT_IRQHandler() __attribute__((interrupt("WCH-Interrupt-fast")));

// 配置

enum{
    // 中断线配置
    KEY0_INT_EXTI_Line  = EXTI_Line1,
    KEY0_INT_IRQn       = EXTI1_IRQn,

    KEY1_INT_EXTI_Line  = EXTI_Line5,
    KEY1_INT_IRQn       = EXTI9_5_IRQn,

    WKUP_INT_EXTI_Line  = EXTI_Line0,
    WKUP_INT_IRQn       = EXTI0_IRQn,
};

class Exti{

public:
    Exti();
    void Init();
};
