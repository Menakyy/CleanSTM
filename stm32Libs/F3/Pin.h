/*
 * Pin.h
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#ifndef STM32LIBS_F3_PIN
#define STM32LIBS_F3_PIN

#include "stm32Libs/Platform.h"
#include "stm32Libs/F3/interfaces/IBoolValue.h"

class Pin
{
    public:
    enum TFPinMode
    {
        TF_PIN_OUT_PP,
        TF_PIN_OUT_OD,
        TF_PIN_AF_PP,
        TF_PIN_AF_OD,
        TF_PIN_IN,
        TF_PIN_ANALOG,
        TF_PIN_IT_RISING,
        TF_PIN_MODE_IT_FALLING,
        TF_PIN_MODE_IT_RISING_FALLING,
        
    };

    enum TFPinPull
    {
        TF_PIN_PULL_NONE,
        TF_PIN_PULL_UP,
        TF_PIN_PULL_DOWN,
    };

	Pin(GPIO_TypeDef* gpiox, uint32_t pin, TFPinMode mode, TFPinPull pull, uint32_t speed, uint32_t alternate);

	void init();
	void reconfigure(TFPinMode mode, TFPinPull pull, uint32_t alternate);

private:
	GPIO_TypeDef* _gpiox;
	uint32_t _pin;
	uint32_t _speed;


public:
	bool getValue();
	void setValue(bool);
	void toggleValue();

private:
    TFPinMode _mode;
    TFPinPull _pull;
    uint32_t _alternate;
};


#endif /* STM32LIBS_F3_PIN */
