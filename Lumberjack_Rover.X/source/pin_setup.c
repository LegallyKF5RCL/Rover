/*
 * File:   pin_setup.c
 * 
 * 
 *
 * 
 */

#include <stdio.h>
#include <pps.h>
#include "../include/globals.h"
#include "../include/chip_setup.h"


inline void INT0_Setup(void)    //Setup External Interrupt 0
{
    _INT0IF = 0;

    //For INT0EP:  0=Positive Edge, 1=Negative Edge
    _INT0EP = 0;
    _INT0IE = 0;                //Turn on INT0 Interrupt

    printf("INT0 Setup\r\n");
    return;
}

inline void INT1_Setup(void)    //Setup External Interrupt 1
{
    _INT1IF = 0;

    //For INT1EP:  0=Positive Edge, 1=Negative Edge
    _INT1EP = 0;

    TRISBbits.TRISB5 = IN;
    PPSInput(PPS_INT1, PPS_RP5);

    _INT1IE = 0;                //Turn on INT1 Interrupt

    printf("INT1 Setup\r\n");
    return;
}

inline void INT2_Setup(void)    //Setup External Interrupt 0
{
    _INT2IF = 0;

    //For INT2EP:  0=Positive Edge, 1=Negative Edge
    _INT2EP = 0;

    TRISBbits.TRISB6 = IN;
    PPSInput(PPS_INT2, PPS_RP6);

    _INT2IE = 0;                //Turn on INT2 Interrupt

    printf("INT2 Setup\r\n");
    return;
}

inline void Pin_Setup(void)
{
//    AD1PCFGLbits.PCFG0 = 1;   //Set AN0 to digital
//    AD1PCFGLbits.PCFG1 = 1;   //Set AN1 to digital
//    AD1PCFGLbits.PCFG2 = 1;   //Set AN2 to digital
//    AD1PCFGLbits.PCFG3 = 1;   //Set AN3 to digital
//    AD1PCFGLbits.PCFG4 = 1;   //Set AN4 to digital
//    AD1PCFGLbits.PCFG5 = 1;   //Set AN5 to digital
//    AD1PCFGLbits.PCFG9 = 1;   //Set AN9 to digital
//    AD1PCFGLbits.PCFG10 = 1;  //Set AN10 to digital
//    AD1PCFGLbits.PCFG11 = 1;  //Set AN11 to digital
//    AD1PCFGLbits.PCFG12 = 1;  //Set AN12 to digital
    /* Bits <15:13> are unimplemented
     * The PIC24HJ128GP202 has 10 A2D channels, AN6-8 are unimplemented
     */
    AD1PCFGL = 0x1E3F;

    //INT0_Setup();     //Set up External Interrupt 0
    //INT1_Setup();     //Set up External Interrupt 1
    //INT2_Setup();     //Set up External Interrupt 2


    TRISB = OUT;
    TRISA = OUT;

    printf("Pins Seup Setup\r\n");
    return;
}

