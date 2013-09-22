#include <p24HJ128GP202.h>
#include <Generic.h>
#include <i2c.h>

void I2c_Setup(void)
{
    OpenI2C1(
            I2C1_ON &
            I2C1_IDLE_CON &
            I2C1_CLK_REL &
            I2C1_IPMI_DIS &
            I2C1_7BIT_ADD &
            I2C1_SLW_EN &
            I2C1_SM_EN &
            I2C1_SM_DIS &
            I2C1_GCALL_EN &
            I2C1_STR_EN &
            I2C1_ACK &
            I2C1_ACK_EN &
            I2C1_RCV_EN &
            I2C1_STOP_EN &
            I2C1_RESTART_EN &
            I2C1_START_EN
            ,
            0xFFFF
            );

    ConfigIntI2C1(
            MI2C1_INT_ON &
            MI2C1_INT_PRI_1
            );

    return;
}



