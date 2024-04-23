#ifndef STM32LIBS_F3_SYSTEM
#define STM32LIBS_F3_SYSTEM

#include "stm32f3xx_hal.h"

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

#endif /* STM32LIBS_F3_SYSTEM */
