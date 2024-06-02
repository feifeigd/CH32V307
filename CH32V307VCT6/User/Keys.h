#pragma once

/*
 * Keys.h
 *
 *  Created on: Jun 2, 2024
 *      Author: Administrator
 */
#include "Key.h"

// 3个板载按键
class Keys{
private:
    Key key0_{GPIOA, GPIO_Pin_1, Key::UP};
    Key key1_{GPIOC, GPIO_Pin_5, Key::UP};
    Key key_up_{GPIOA, GPIO_Pin_0, Key::DOWN};
public:
    Keys();
    void Init();

    // 哪个按钮按下了
    enum HitKey {
        PRESSED_NONE,
        PRESSED_KEY0,
        PRESSED_KEY1,
        PRESSED_KEYUP,
    };

    // 多个按键同时按下时，响应优先级  key_up_ >  key1_ > key0_
    // @param mode 0：不支持连续按(当按键按下不放时，只有第一次调用会返回按键值0)，必须松开以后，再次按下才会返回其他键值
    // 1: 支持连续按(当按键按下不放时，每次调用该函数都会返回键值)
    HitKey key_scan(uint8_t mode);
};
