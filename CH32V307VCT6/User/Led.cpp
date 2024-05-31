/*
 * Led.cpp
 *
 *  Created on: May 29, 2024
 *      Author: PC
 */

#include "Led.h"

Led::Led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t RCC_APB2Periph)
    : GPIOx_{GPIOx}
    , GPIO_Pin_{GPIO_Pin}
{
    // 先调用 RCC_APB2PeriphClockCmd，再调用 GPIO_Init，否则不生效
    RCC_APB2PeriphClockCmd(RCC_APB2Periph, ENABLE);
    Init();
}

void Led::Init(){

    GPIO_InitTypeDef conf = {
        .GPIO_Pin   = GPIO_Pin_,
        .GPIO_Speed = GPIO_Speed_50MHz,
        .GPIO_Mode  = GPIO_Mode_Out_PP,
    };
    GPIO_Init(GPIOx_, &conf);
}

void Led::Set(){
    GPIO_SetBits(GPIOx_, GPIO_Pin_);
}

void Led::Reset(){
    GPIO_ResetBits(GPIOx_, GPIO_Pin_);
}
