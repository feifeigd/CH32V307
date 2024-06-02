
/*
 * GpioPin.cpp
 *
 *  Created on: Jun 1, 2024
 *      Author: Administrator
 */

#include "GpioPin.h"

GpioPin::GpioPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
    : GPIOx_{GPIOx}
    , GPIO_Pin_{GPIO_Pin}
{

}

void GpioPin::Init(){

    GPIO_InitTypeDef conf = {
        .GPIO_Pin   = GPIO_Pin_,
        .GPIO_Speed = GPIO_Speed_50MHz,
        .GPIO_Mode  = GPIO_Mode_Out_PP, // 推挽输出
    };
    GPIO_Init(GPIOx_, &conf);
}

void GpioPin::Set(){
    GPIO_SetBits(GPIOx_, GPIO_Pin_);
}

void GpioPin::Reset(){
    GPIO_ResetBits(GPIOx_, GPIO_Pin_);
}

uint8_t GpioPin::ReadInputBit(){
    return GPIO_ReadInputDataBit(GPIOx_, GPIO_Pin_);
}

void GpioPin::toggle(){
    uint32_t odr = GPIOx_->OUTDR;
    GPIOx_->BSHR = ((odr & GPIO_Pin_) << 16) | (~odr & GPIO_Pin_);
}
