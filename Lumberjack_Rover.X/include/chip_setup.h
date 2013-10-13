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

extern void Timer1_Setup(void);
extern void Timer2_Setup(void);
extern void Timer3_Setup(void);
extern void Timer4_Setup(void);
extern void Timer5_Setup(void);
extern void Timer23_Setup(void);
extern void Timer45_Setup(void);

extern void Pin_Setup(void);
extern void Chip_Config(void);

extern void Setup_SPI1(void);
        


#ifdef	__cplusplus
}
#endif

#endif	/* CHIP_SETUP_H */

