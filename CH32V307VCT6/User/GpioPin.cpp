
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

void GpioPin::Set(){
    GPIO_SetBits(GPIOx_, GPIO_Pin_);
}

void GpioPin::Reset(){
    GPIO_ResetBits(GPIOx_, GPIO_Pin_);
}
