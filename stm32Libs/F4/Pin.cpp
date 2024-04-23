/*
 * Pin.cpp
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#include "Pin.h"

Pin::Pin(GPIO_TypeDef* gpiox, uint32_t pin, PinMode mode, PinPull pull, uint32_t speed, uint32_t alternate)
{
    _gpiox = gpiox;
    _pin   = pin;
    _speed = speed;
    _mode  = mode;
    _pull  = pull;
}

void Pin::init()
{
    uint32_t mode;
    uint32_t pull;


    switch (_mode)
    {
        case PIN_IN:
            mode = GPIO_MODE_INPUT;
            break;
        case PIN_OUT_PP:
            mode = GPIO_MODE_OUTPUT_PP;
            break;
        case PIN_OUT_OD:
            mode = GPIO_MODE_OUTPUT_OD;
            break;
        case PIN_AF_OD:
            mode = GPIO_MODE_AF_OD;
            break;
        case PIN_AF_PP:
            mode = GPIO_MODE_AF_PP;
            break;
        case PIN_ANALOG:
            mode = GPIO_MODE_ANALOG;
            break;
        default:
            mode = GPIO_MODE_OUTPUT_PP;
            break;
    }

    switch (_pull)
    {
        case PIN_PULL_NONE:
            pull = GPIO_NOPULL;
            break;
        case PIN_PULL_DOWN:
            pull = GPIO_PULLDOWN;
            break;
        case PIN_PULL_UP:
            pull = GPIO_PULLUP;
            break;
        default:
            pull = GPIO_NOPULL;
            break;
    }


    GPIO_InitTypeDef g;
    g.Pin       = _pin;
    g.Mode      = mode;
    g.Pull      = pull;
    g.Speed     = _speed;
    g.Alternate = _alternate;

    HAL_GPIO_Init(_gpiox, &g);
}

void Pin::reconfigure(PinMode mode, PinPull pull, uint32_t alternate)
{
    _mode      = mode;
    _pull      = pull;
    _alternate = alternate;
    init();
}

bool Pin::getValue()
{
    return HAL_GPIO_ReadPin(_gpiox, _pin);
}

void Pin::toggleValue()
{
    HAL_GPIO_TogglePin(_gpiox, _pin);
}

void Pin::setValue(bool state)
{
    GPIO_PinState halState = state ? GPIO_PIN_SET : GPIO_PIN_RESET;
    HAL_GPIO_WritePin(_gpiox, _pin, halState);
}