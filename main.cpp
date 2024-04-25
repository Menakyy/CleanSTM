/*
 * main.cpp
 *
 *  Created on: Apr 18, 2024
 *      Author: konrad
 */

#include "platform/UsingPcb.h"
#include <stdio.h>

int main(void)
{
    PCB pcb;
    pcb.init();

    while (true)
    {
        if (pcb.getBlueButton()->getValue() == false)
        {
            pcb.getGreenLed()->setValue(false);
        }
        else
        {
            pcb.getGreenLed()->setValue(true);
        }
    }
}
