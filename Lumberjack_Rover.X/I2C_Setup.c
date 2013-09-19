#include <p24HJ128GP202.h>

#include <Generic.h>
#include <i2c.h>

void I2C_Setup(void)
{
OpenI2C1( I2C1_ON &
        I2C1_IDLE_CON &
        /*I2C1_CLK_HLD*/ &
        /*I2C1_IPMI_DIS*/ &
        I2C1_7BIT_ADD &
        /*I2C1_SLW_EN*/ &

        
        ,unsigned int);


}




/*
 * ~~~
 * RESEARCH
 * ~~~
 *
void AckI2C1(void) __attribute__ ((section (".libperi")));
 * //generate acknowledge
void CloseI2C1(void) __attribute__ ((section (".libperi")));
 *
void ConfigIntI2C1(unsigned int) __attribute__ ((section (".libperi")));
 *
char DataRdyI2C1(void) __attribute__ ((section (".libperi")));
 *
unsigned int SlavegetsI2C1(unsigned char *, unsigned int) __attribute__ ((section (".libperi")));
 *
unsigned int MastergetsI2C1(unsigned int length, unsigned char * rdptr, unsigned int i2c_data_wait) __attribute__ ((section (".libperi")));
 *
void IdleI2C1(void) __attribute__ ((section (".libperi")));
 *
void NotAckI2C1(void) __attribute__ ((section (".libperi")));
 *
void OpenI2C1(unsigned int,unsigned int) __attribute__ ((section (".libperi")));
 *
unsigned int MasterputsI2C1(unsigned char *) __attribute__ ((section (".libperi")));
 *
unsigned int SlaveputsI2C1(unsigned char *) __attribute__ ((section (".libperi")));
 *
unsigned char SlaveReadI2C1(void) __attribute__ ((section (".libperi")));
 *
unsigned char MasterReadI2C1(void) __attribute__ ((section (".libperi")));
 *
void SlaveWriteI2C1(unsigned char) __attribute__ ((section (".libperi")));
 *
char MasterWriteI2C1(unsigned char) __attribute__ ((section (".libperi")));
 *
void RestartI2C1(void) __attribute__ ((section (".libperi")));
 *
void StartI2C1(void) __attribute__ ((section (".libperi")));
 *
void StopI2C1(void) __attribute__ ((section (".libperi")));
 *

 */
