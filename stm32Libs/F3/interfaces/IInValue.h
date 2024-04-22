#ifndef STM32LIBS_F3_INTERFACES_IINVALUE
#define STM32LIBS_F3_INTERFACES_IINVALUE


class IInValue
{
public:
    virtual ~IInValue(){}
    virtual bool getValue() = 0;
};

#endif /* STM32LIBS_F3_INTERFACES_IINVALUE */
