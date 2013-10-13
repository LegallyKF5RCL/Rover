/*
 * File:   uart_config.h
 * Author: Mike Peters
 * 1000750876
 *
 * Lab 6
 */

#ifndef CONFIG_H
#define	CONFIG_H

#ifdef	__cplusplus
extern "C" {
#endif

//#define InvertRxTxBits//To invert the Signals if Needed [Currently NOT needed]
    
#define TRIS_U1TX       (TRISBbits.TRISB14 = 0)
#define TRIS_U1RX       (TRISBbits.TRISB15 = 1)
#define MAP_U1TX        (PPSOutput(OUT_FN_PPS_U1TX, OUT_PIN_PPS_RP14))
#define MAP_U1RX        (PPSInput(PPS_U1RX, PPS_RP15))
    
#define TRIS_U2TX       (TRISBbits.TRISB8 = 0)
#define TRIS_U2RX       (TRISBbits.TRISB10 = 1)
#define MAP_U2TX        (PPSOutput(OUT_FN_PPS_U2TX, OUT_PIN_PPS_RP8))
#define MAP_U2RX        (PPSInput(PPS_U2RX, PPS_RP10))

#define __FOSC_ 80000000
#define __FTCY_ (__FOSC_/2)

extern void UART1_Config(void);

#define __U1BAUD_ 38400 //<--- Desired Baud rate UART1 CHANGE THIS
#define __BAUDUART1_ ((__FTCY_/(16*__U1BAUD_))-1)

#ifdef _U2RXIF

#define __U2BAUD_ 2400L //Desired baud rate UART2 CHANGE THIS
#define __BAUDUART2_ ((__FTCY_/(16*__U2BAUD_))-1)

extern void UART2_Config(void);

#endif

#ifdef _U3RXIF

#define __U3BAUD_ 9600L //Desired baud rate UART3 CHANGE THIS
#define __BAUDUART3_ ((__FTCY_/(16*__U3BAUD_))-1)

extern void UART3_Config(void);

#endif

#ifdef _U4RXIF

#define __U4BAUD_ 9600L //Desired baud rate UART4 CHANGE THIS
#define __BAUDUART4_ ((__FTCY_/(16*__U4BAUD_))-1)

extern void UART4_Config(void);

#endif
//End of Baud Rate


#ifdef	__cplusplus
}
#endif

#endif	/* CONFIG_H */

