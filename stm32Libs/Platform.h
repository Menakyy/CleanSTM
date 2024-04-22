/*
 * Platform.h
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#ifndef STM32LIBS_PLATFORM
#define STM32LIBS_PLATFORM

#include <string.h>
#include <stdlib.h>
#include <stdint.h>


#ifdef PLATFORM_STM32F3
    #include "stm32f3xx_hal.h"
#endif

#ifdef PLATFORM_STM32F4
    #include "stm32f4xx_hal.h"
#endif



#endif /* STM32LIBS_PLATFORM */
