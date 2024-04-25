#include "PCB_F303RE.h"

PCB_F303RE::PCB_F303RE() : 
    system(),
    greenLed(GPIOA, GPIO_PIN_5, Pin::PinMode::PIN_OUT_PP, Pin::PinPull::PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0),
    blueButton(GPIOC, GPIO_PIN_13, Pin::PinMode::PIN_IN, Pin::PinPull::PIN_PULL_NONE, GPIO_SPEED_FREQ_LOW, 0)
{
}

PCB_F303RE::~PCB_F303RE()
{
}

void PCB_F303RE::init()
{
    startPeripheralClocks();
    initPins();
    initSystem();
}

void PCB_F303RE::startPeripheralClocks()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
}

void PCB_F303RE::initPins()
{
    greenLed.init();
    blueButton.init();
}

void PCB_F303RE::initSystem()
{
    system.init();
}
