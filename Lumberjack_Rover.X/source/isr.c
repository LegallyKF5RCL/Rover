#include <p24Hxxxx.h>

void __attribute__((interrupt,auto_psv)) _ISR _T1Interrupt(void)
{
    _T1IF = 0;
    
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T2Interrupt(void)
{
    _T2IF = 0;

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T3Interrupt(void)
{
    _T3IF = 0;

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T4Interrupt(void)
{
    _T4IF = 0;

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _T5Interrupt(void)
{
    _T5IF = 0;

    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _U2RXInterrupt(void)
{
    //char received;
    _U2RXIF = 0;
    
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _U1RXInterrupt(void)
{
    //char received;
    _U1RXIF = 0;

    
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _INT0Interrupt(void)
{
    _INT0IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _INT1Interrupt(void)
{
    _INT1IF = 0;


    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _INT2Interrupt(void)
{
    _INT2IF = 0;


    return;
}