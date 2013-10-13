/*
 * File:   chip_setup.h
 * Author: Mike Peters
 */

#ifndef CHIP_SETUP_H
#define	CHIP_SETUP_H

#ifdef	__cplusplus
extern "C" {
#endif

#define DEBUG

void Timer1_Setup(void);
void Timer2_Setup(void);
void Timer3_Setup(void);
void Timer4_Setup(void);
void Timer5_Setup(void);
void Timer23_Setup(void);
void Timer45_Setup(void);

extern void Setup_GPIO(void);
void Chip_Config(void);
void Setup_TIMERS(void);

extern void Setup_SPI1(void);
void Setup_I2C(void);
void Setup_PWM(void);

#ifdef	__cplusplus
}
#endif

#endif	/* CHIP_SETUP_H */

