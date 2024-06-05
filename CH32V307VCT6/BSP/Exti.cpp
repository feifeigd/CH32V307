/*
 * Exti.cpp
 *
 *  Created on: Jun 3, 2024
 *      Author: PC
 */

#include "Exti.h"

Exti::Exti(){
    // AFIO 时钟使能
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
}

void Exti::Init(){

    // EXTI(外部中断和事件控制器) 驱动

    // 1.配置GPIO引脚为EXTI的外部中断源
    // GPIOA1
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource0); // PA0 key_up_
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource1);  // PA1 key0_
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOC, GPIO_PinSource5);  // PC5 key1_

    // 2.初始化 EXTI
    EXTI_InitTypeDef exti_conf = {};
    exti_conf.EXTI_Mode = EXTI_Mode_Interrupt, // 配置为中断模式

    exti_conf.EXTI_Trigger = EXTI_Trigger_Falling, // 下降沿触发, key0_,key1_
    // key0_
    exti_conf.EXTI_Line = KEY0_INT_EXTI_Line;   // 开启外部中断线x
    EXTI_Init(&exti_conf);
    // key1_
    exti_conf.EXTI_Line = KEY1_INT_EXTI_Line;   // 开启外部中断线x
    EXTI_Init(&exti_conf);
    // key_up_
    exti_conf.EXTI_Trigger  = EXTI_Trigger_Falling, // 上升沿触发, key_up_
    exti_conf.EXTI_Line     = WKUP_INT_EXTI_Line;   // 开启外部中断线x
    EXTI_Init(&exti_conf);


    // PFIC(可编程快速中断控制器) 驱动
    // 1. 初始化PFIC
    NVIC_InitTypeDef nvic_conf = {};
    nvic_conf.NVIC_IRQChannelPreemptionPriority = 0x02, // 抢占优先级2
    nvic_conf.NVIC_IRQChannelCmd = ENABLE, // 使能中断

    nvic_conf.NVIC_IRQChannel = WKUP_INT_IRQn, // 外部中断线1
    nvic_conf.NVIC_IRQChannelSubPriority = 0x03, // 响应优先级3
    NVIC_Init(&nvic_conf);

    nvic_conf.NVIC_IRQChannel = KEY0_INT_IRQn, // 外部中断线1
    nvic_conf.NVIC_IRQChannelSubPriority = 0x01, // 响应优先级1
    NVIC_Init(&nvic_conf);

    nvic_conf.NVIC_IRQChannel = KEY1_INT_IRQn, // 外部中断线1
    nvic_conf.NVIC_IRQChannelSubPriority = 0x02, // 响应优先级2
    NVIC_Init(&nvic_conf);
    // 2. 中断服务函数

}

