/*
 * main.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#include "Helper.h"
#include "stm32Libs/F4/Pin.h"

int main(void)
{
	Helper::initHal();
	Helper::SystemClock_Config();

	__HAL_RCC_GPIOA_CLK_ENABLE();
	Pin testPin(GPIOA, GPIO_PIN_5,  Pin::TF_PIN_OUT_PP, Pin::TF_PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0);
	testPin.init();

	while(true)
	{
		testPin.toggleValue();
		HAL_Delay(1000);
	}
}
