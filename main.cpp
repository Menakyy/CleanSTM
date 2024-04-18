/*
 * main.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#include "Helper.h"
#include "Drivers/Core/Inc/gpio.h"

int main(void)
{
	Helper::initHal();
	Helper::SystemClock_Config();
	MX_GPIO_Init();

	while(true)
	{
		HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
		HAL_Delay(500);
	}
}
