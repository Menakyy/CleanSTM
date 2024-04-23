/*
 * Platform.h
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#ifndef STM32LIBS_PLATFORM
#define STM32LIBS_PLATFORM

#include <stdint.h>
#include <stdlib.h>
#include <string.h>


#ifdef PLATFORM_STM32F3
#    include "stm32f3xx_hal.h"
#endif

#ifdef PLATFORM_STM32F4
#    include "stm32f4xx_hal.h"
#endif


#endif /* STM32LIBS_PLATFORM */
