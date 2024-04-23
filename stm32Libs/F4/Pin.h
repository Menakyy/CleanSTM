/*
 * Pin.h
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#ifndef PIN_H_
#define PIN_H_

#include "stm32Libs/Platform.h"

class Pin
{
public:
    enum PinMode
    {
        PIN_OUT_PP,
        PIN_OUT_OD,
        PIN_AF_PP,
        PIN_AF_OD,
        PIN_IN,
        PIN_ANALOG,
    };

    enum PinPull
    {
        PIN_PULL_NONE,
        PIN_PULL_UP,
        PIN_PULL_DOWN,
    };

    Pin(GPIO_TypeDef* gpiox, uint32_t pin, PinMode mode, PinPull pull, uint32_t speed, uint32_t alternate);

    void init();
    void reconfigure(PinMode mode, PinPull pull, uint32_t alternate);

private:
    GPIO_TypeDef* _gpiox;
    uint32_t      _pin;
    uint32_t      _speed;

public:
    bool getValue();
    void setValue(bool);
    void toggleValue();

private:
    PinMode  _mode;
    PinPull  _pull;
    uint32_t _alternate;
};


#endif /* PIN_H_ */
