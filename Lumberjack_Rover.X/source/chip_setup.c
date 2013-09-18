

#include "../include/chip_setup.h"
#include "../include/globals.h"
#include "../include/uart_config.h"

void Timer_Config(void)
{
    Timer1_Setup();
    Timer2_Setup();
    Timer3_Setup();
    Timer4_Setup();
    Timer5_Setup();

    //Setup for 32-bit timers
    Timer45_Setup();
    Timer23_Setup();
    
    return;   
}

void Chip_Config(void)
{
    UART1_Config();
    Timer_Config();
    Pin_Setup();
    
    return;
}


