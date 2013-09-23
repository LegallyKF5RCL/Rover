/* 
 * File:   globals.h
 * Author: Mike
 *
 * Created on July 2, 2013, 1:41 PM
 */

#ifndef GLOBALS_H
#define	GLOBALS_H

#include <Generic.h>
#include <stdint.h>


enum { OFF=0, ON };
enum { OUT=0, IN };
typedef enum { IDLE=0, ACTIVE=1 }eState;
typedef enum 
{
    ACCEL//,
  //  EEPROM,
  //  COMPASS
}eDevices;

//Variables to set Period Registers for 32-bit timers
extern unsigned long PR23;
extern unsigned long PR45;

    extern volatile WORD_VAL Flags;

#define DEF1                    Flags.bits.b0
#define DEF2                    Flags.bits.b1
#define DEF3                    Flags.bits.b2
#define DEF4                    Flags.bits.b3
#define DEF5                    Flags.bits.b4
#define DEF6                    Flags.bits.b5
#define DEF7                    Flags.bits.b6
#define DEF8                    Flags.bits.b7
#define DEF9                    Flags.bits.b8
#define DEF10                   Flags.bits.b9
#define DEF11                   Flags.bits.b10
#define DEF12                   Flags.bits.b11
#define DEF13                   Flags.bits.b12
#define DEF14                   Flags.bits.b13
#define DEF15                   Flags.bits.b14
#define DEF16                   Flags.bits.b15


extern void InitGlobals(void);
extern void Send_SPI(BYTE * Data,int Len,eDevices Device);



#endif	/* GLOBALS_H */

