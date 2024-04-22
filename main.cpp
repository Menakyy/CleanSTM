/*
 * main.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#include "Helper.h"
#include "stm32Libs/F3/Pin.h"
#include <stdio.h>

int main(void)
{
	Helper::initHal();
	Helper::SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();

	Pin greenLed(GPIOA, GPIO_PIN_5, Pin::TF_PIN_OUT_PP, Pin::TF_PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0);
	Pin blueButton(GPIOC, GPIO_PIN_13, Pin::TF_PIN_IN, Pin::TF_PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0);

	greenLed.init();
	blueButton.init();

	while (true)
	{
		if (blueButton.getValue())
		{
			greenLed.toggleValue();
			printf("Test");
		}
	}
}
