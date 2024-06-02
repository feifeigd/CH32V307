#pragma once

/*
 * Key.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */
#include "GpioPin.h"

class Key: public GpioPin{
public:
    enum Mode {
        UP,     // 上拉输入
        DOWN,   // 下拉输入
    };
private:
    Mode mode_; //
public:
    Key(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, Mode mode);
    void Init()override;
};
