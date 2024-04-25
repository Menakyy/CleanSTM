#ifndef PLATFORM_PCB_F303RE
#define PLATFORM_PCB_F303RE

#include "stm32Libs/F3/Pin.h"
#include "stm32Libs/F3/System.h"

class PCB_F303RE
{
public:
    PCB_F303RE();
    ~PCB_F303RE();

    void init();
    void startPeripheralClocks();
    void initPins();
    void initSystem();
    
    Pin* getGreenLed() { return &greenLed; }
    Pin* getBlueButton() { return &blueButton; }

private:
    System system;
    Pin greenLed;
    Pin blueButton;
};

#endif /* PLATFORM_PCB_F303RE */
