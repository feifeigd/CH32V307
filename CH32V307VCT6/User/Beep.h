#pragma once

/*
 * Beep.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */
#include "GpioPin.h"


class Beep: public GpioPin{
public:
    Beep(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
};
