#ifndef STM32LIBS_F3_INTERFACES_IBOOLVALUE
#define STM32LIBS_F3_INTERFACES_IBOOLVALUE


#include "stm32Libs/F3/interfaces/IInValue.h"

class IBoolValue: public IInValue
{
public:
    virtual void setValue(bool) = 0;
    virtual void toggleValue() {setValue(!getValue());}
};

#endif /* STM32LIBS_F3_INTERFACES_IBOOLVALUE */
