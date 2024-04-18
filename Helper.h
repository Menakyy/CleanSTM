/*
 * Helper.h
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#ifndef HELPER_H_
#define HELPER_H_

#include "stm32f3xx_hal.h"

class Helper
{
public:
	Helper();
	virtual ~Helper();

	static void initHal();
	static void SystemClock_Config();
	static void Error_Handler();
};

#endif /* HELPER_H_ */
