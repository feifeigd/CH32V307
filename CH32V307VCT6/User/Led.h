#pragma once

/*
 * Led.h
 *
 *  Created on: May 29, 2024
 *      Author: PC
 */
#include "GpioPin.h"

class Led: public GpioPin{
public:
    Led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    void Init()override;
};
