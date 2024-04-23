#ifndef STM32LIBS_F4_SYSTEM
#define STM32LIBS_F4_SYSTEM

#include "stm32f4xx_hal.h"

class System
{
public:
    System();
    ~System();

    void init();

private:
    void initHal();
    void SystemClock_Config();
    void Error_Handler();
};


#endif /* STM32LIBS_F4_SYSTEM */
