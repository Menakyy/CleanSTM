/*
 * Pin.cpp
 *
 *  Created on: Apr 22, 2024
 *      Author: konrad
 */

#include "Pin.h"
Pin::Pin(GPIO_TypeDef* gpiox, uint32_t pin, TFPinMode mode, TFPinPull pull, uint32_t speed, uint32_t alternate)
{
	_gpiox = gpiox;
	_pin = pin;
	_speed = speed;
}

void Pin::init()
{
	uint32_t mode;
	uint32_t pull;


	switch (_mode)
	{
		case TF_PIN_IN:
			mode = GPIO_MODE_INPUT;
		break;
		case TF_PIN_OUT_PP:
			mode = GPIO_MODE_OUTPUT_PP;
		break;
		case TF_PIN_OUT_OD:
			mode = GPIO_MODE_OUTPUT_OD;
		break;
		case TF_PIN_AF_OD:
			mode = GPIO_MODE_AF_OD;
		break;
		case TF_PIN_AF_PP:
			mode = GPIO_MODE_AF_PP;
		break;
		case TF_PIN_ANALOG:
			mode = GPIO_MODE_ANALOG;
		break;
		default:
			mode = GPIO_MODE_OUTPUT_PP;
		break;
	}

	switch (_pull)
	{
		case TF_PIN_PULL_NONE:
			pull = GPIO_NOPULL;
		break;
		case TF_PIN_PULL_DOWN:
			pull = GPIO_PULLDOWN;
		break;
		case TF_PIN_PULL_UP:
			pull = GPIO_PULLUP;
		break;
		default:
			pull = GPIO_NOPULL;
		break;
	}


	GPIO_InitTypeDef g;
	g.Pin = _pin;
	g.Mode = mode;
	g.Pull = pull;
	g.Speed = _speed;
	g.Alternate = _alternate;

	HAL_GPIO_Init(_gpiox, &g);
}


void Pin::reconfigure(TFPinMode mode, TFPinPull pull, uint32_t alternate)
{
	_mode = mode;
	_pull = pull;
	_alternate = alternate;
	init();
}

bool Pin::getValue()
{
	return (_gpiox->IDR & _pin);
}

void Pin::toggleValue()
{
	_gpiox->BSRR = (_gpiox->IDR & _pin) ? _pin << 16 : _pin;
}

void Pin::setValue(bool state)
{
	_gpiox->BSRR = state ? _pin : _pin << 16;
}
