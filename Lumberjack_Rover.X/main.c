/*
 * File:   main.c
 * Author: Mike
 *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <p24Hxxxx.h>
#include <Generic.h>
#include "include/chip_setup.h"
#include "include/uart_config.h"
#include "include/globals.h"

/*
 * Words of Power
 */

_FBS(BWRP_WRPROTECT_OFF & BSS_NO_BOOT_CODE & RBS_NO_BOOT_RAM )
_FSS(SWRP_WRPROTECT_OFF &  SSS_NO_SEC_CODE  & RSS_NO_SEC_RAM )
_FGS(GWRP_OFF & GCP_OFF)
_FOSCSEL( FNOSC_FRC & IESO_OFF)
_FOSC(OSCIOFNC_ON & POSCMD_NONE & FCKSM_CSECMD)
_FWDT( WDTPOST_PS8192 & WDTPRE_PR32 & WINDIS_OFF & FWDTEN_OFF)
_FPOR( FPWRT_PWR128)
_FICD( ICS_PGD1 & JTAGEN_OFF)



int main(int argc, char** argv) {
    void Ludacris_Speed(void); //Prototype an inline function
    Ludacris_Speed();

    Chip_Config();

    printf("Run for your life...");

    while (1)
    {
        Nop();
    }
    return (EXIT_SUCCESS);
}

inline void Ludacris_Speed()
{
    //This code from Microchip Family Ref. 39 Oscillator(Part III)
    //Configure PLL prescaler, PLL postscaler, PLL divisor, 80 MHz
    PLLFBD = 41; // M = 43
    CLKDIVbits.PLLPOST = 0; // N2 = 2
    CLKDIVbits.PLLPRE = 0; // N1 = 2
    // Initiate Clock Switch to Internal FRC with PLL (NOSC = 0b001)
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    // Wait for Clock switch to occur
    while (OSCCONbits.COSC != 0b001);
    // Wait for PLL to lock
    while(OSCCONbits.LOCK != 1) {};
    return;
}