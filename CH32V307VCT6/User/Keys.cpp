/*
 * Keys.cpp
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */

#include "Keys.h"
#include <debug.h>

Keys::Keys(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
}

void Keys::Init(){
    key0_.Init();
    key1_.Init();
    key_up_.Init();
}

Keys::HitKey Keys::key_scan(uint8_t mode){
    static bool key_up = true; // 按键松开标记
    Keys::HitKey keyval = PRESSED_NONE;

    if(mode)key_up = true; // 支持连按

    // 按键松开标志为1，且有任意一个按键按下了
    bool has_pressed = (0 == key0_.ReadInputBit() || 0 == key1_.ReadInputBit() || 1 == key_up_.ReadInputBit());
    if(key_up && has_pressed){
        Delay_Ms(10); // 去抖动
        key_up = false;

        if(0 == key0_.ReadInputBit())keyval = PRESSED_KEY0;
        if(0 == key1_.ReadInputBit())keyval = PRESSED_KEY1;
        if(1 == key_up_.ReadInputBit())keyval = PRESSED_KEYUP;
    }
    // 没有任何按键按下，标记按键松开
    else if( not has_pressed){
        key_up = true;
    }

    return keyval;
}
