/*
 * Helper.h
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#ifndef HELPER
#define HELPER

#include "stm32f4xx_hal.h"

class Helper
{
public:
	Helper();
	virtual ~Helper();

	static void initHal();
	static void SystemClock_Config();
	static void Error_Handler();
};

#endif /* HELPER */
