/*
 * main.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#include "stm32Libs/F3/Pin.h"
#include "stm32Libs/F3/System.h"

#include <stdio.h>

int main(void)
{
    System system;
    system.init();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();

    Pin greenLed(GPIOA, GPIO_PIN_5, Pin::PinMode::PIN_OUT_PP, Pin::PinPull::PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0);
    Pin blueButton(GPIOC, GPIO_PIN_13, Pin::PinMode::PIN_IN, Pin::PinPull::PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0);

    greenLed.init();
    blueButton.init();

    while (true)
    {
        if (blueButton.getValue())
        {
            greenLed.toggleValue();
        }
    }
}
