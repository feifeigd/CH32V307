#pragma once

#include <ch32v30x.h>

// 对 GPIO的单个管脚进行控制
class GpioPin{
protected:
    GPIO_TypeDef*   GPIOx_{};
    uint16_t        GPIO_Pin_{};
public:
    GpioPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
    virtual void Init();
    
    // 设置为高电平
    void Set();

    // 设置为低电平
    void Reset();
};
