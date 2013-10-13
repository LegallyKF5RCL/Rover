/*
 * File:   timer_setup.c
 * Author: Mike Peters
 */

#include    <p24Hxxxx.h>
#include    <timer.h>
#include    <stdio.h>
#include    <Generic.h>
#include    "../include/globals.h"
#include    "../include/chip_setup.h"

inline void Timer1_Setup(void)
{
    OpenTimer1(
            T1_OFF &
            T1_IDLE_CON &       
            T1_GATE_OFF &
            T1_PS_1_256 &
            T1_SYNC_EXT_OFF &
            T1_SOURCE_INT,
            39063); //for 250 ms.

    ConfigIntTimer1(
            T1_INT_PRIOR_3 &
            T1_INT_OFF
                    );


    printf("Timer 1 setup\r\n");
    return;
}

inline void Timer2_Setup(void)
{
    OpenTimer2(
            T2_OFF &
            T2_IDLE_CON &
            T2_GATE_OFF &
            T2_PS_1_256 &
            T2_32BIT_MODE_OFF &
            T2_SOURCE_INT,
            39063); //for 250 ms.

    ConfigIntTimer2(
            T2_INT_PRIOR_3 &
            T2_INT_OFF
                    );

    printf("Timer 2 setup\r\n");
    return;
}

inline void Timer3_Setup(void)
{
    OpenTimer3(
            T3_OFF &
            T3_IDLE_CON &
            T3_GATE_OFF &
            T3_PS_1_256 &
            T3_SOURCE_INT,
            39063); //for 250 ms.

    ConfigIntTimer3(
            T3_INT_PRIOR_3 &
            T3_INT_OFF
                    );

    printf("Timer 3 setup\r\n");
    return;
}

inline void Timer4_Setup(void)
{
    OpenTimer4(
            T4_OFF &
            T4_IDLE_CON &
            T4_GATE_OFF &
            T4_PS_1_256 &
            T4_32BIT_MODE_OFF &
            T4_SOURCE_INT,
            39063); //for 250 ms.

    ConfigIntTimer4(
            T4_INT_PRIOR_3 &
            T4_INT_OFF
                    );

    printf("Timer 4 setup\r\n");
    return;
}

inline void Timer5_Setup(void)
{
    OpenTimer5(
            T5_OFF &
            T5_IDLE_CON &
            T5_GATE_OFF &
            T5_PS_1_256 &
            T5_SOURCE_INT,
            39063); //for 250 ms.

    ConfigIntTimer5(
            T5_INT_PRIOR_2 &
            T5_INT_OFF
                    );

    printf("Timer 5 setup\r\n");
    return;
}

//OpenTimerXY(config, (32-bit period));

inline void Timer23_Setup(void)
{
    OpenTimer23(
            T2_OFF &
            T2_IDLE_CON &
            T2_GATE_OFF &
            T2_PS_1_256 &
            T2_32BIT_MODE_ON &
            T2_SOURCE_INT,
            PR23);

    ConfigIntTimer23(
            T3_INT_PRIOR_2 &
            T3_INT_OFF
            );

    printf("Timer 23(32 bit) setup\r\n");
    return;
}

inline void Timer45_Setup(void)
{
    OpenTimer45(
            T4_OFF &
            T4_IDLE_CON &
            T4_GATE_OFF &
            T4_PS_1_256 &
            T4_32BIT_MODE_ON &
            T4_SOURCE_INT,
            0xFFFFFFFF);

    ConfigIntTimer45(
            T5_INT_PRIOR_2 &
            T5_INT_OFF
            );

    printf("Timer 45(32 bit) setup\r\n");
    return;
}