/*
 * Key.cpp
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */

#include "Key.h"

Key::Key(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, Mode mode)
    : GpioPin{GPIOx, GPIO_Pin}
    , mode_{mode}
{

}

void Key::Init(){
    GPIO_InitTypeDef conf = {};
    conf.GPIO_Pin = GPIO_Pin_;

    switch(mode_){
    case Mode::UP:
        conf.GPIO_Mode = GPIO_Mode_IPU; // ��������
        break;
    case Mode::DOWN:
        conf.GPIO_Mode = GPIO_Mode_IPD; // ��������
        break;
    }

    GPIO_Init(GPIOx_, &conf);
}
