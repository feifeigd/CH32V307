#pragma once

/*
 * Led.h
 *
 *  Created on: May 29, 2024
 *      Author: PC
 */
#include <ch32v30x.h>

class Led{
private:
    GPIO_TypeDef*   GPIOx_{};
    uint16_t        GPIO_Pin_{};
    uint32_t        RCC_APB2Periph_{};
public:
    Led(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, uint32_t RCC_APB2Periph);
    void Init();

    void Open();
    void Close();
};

