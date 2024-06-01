/*
 * Beep.cpp
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */

#include "Beep.h"

Beep::Beep(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
    : GpioPin{GPIOx, GPIO_Pin}
{
//    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
}
