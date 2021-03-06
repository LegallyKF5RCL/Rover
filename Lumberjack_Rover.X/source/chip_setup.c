
#include    <p24Hxxxx.h>
#include    <stdio.h>
#include    <Generic.h>
#include    <i2c.h>
#include    <pps.h>
#include    <uart.h>
#include    <outcompare.h>

#include    "../include/uart_config.h"
#include    "../include/chip_setup.h"
#include    "../include/globals.h"

void Chip_Config(void)
{
    UART1_Config();
    Setup_TIMERS();
    Setup_GPIO();
    Setup_SPI1();
    Setup_I2C();
    Setup_PWM();
    printf("Chip Seup Finished\r\n");
    return;
}

void Setup_PWM()
{
     OpenOC1((
             OC_IDLE_CON                &
             OC_TIMER2_SRC              &
             OC_PWM_FAULT_PIN_DISABLE   &
             OC_CONTINUE_PULSE

             ),
             0xDEAD,
             0xCAFE
             );

    ConfigIntOC1( OC_INT_OFF & OC_INT_PRIOR_0 );
    
    Timer2_Setup();

    return;
}
void Setup_TIMERS(void)
{
    //Uncomment When Needed
//    Timer1_Setup();
/////////////////    Timer2_Setup();
//    Timer3_Setup();
//    Timer4_Setup();
//    Timer5_Setup();
//
//    //Setup for 32-bit timers
//    Timer45_Setup();
//    Timer23_Setup();

    printf("Timers Setup Finished\r\n");
    return;
}

//Set up UART and pins
//UART Pins are on RPn (remappable)

void UART1_Config(void)
{
    OpenUART1((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART1_ //Baud rate
            ));
    ConfigIntUART1(
                UART_RX_INT_DIS &        //Receive interrupt disabled
                UART_RX_INT_PR1 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );



#ifdef InvertU1RxTxBits
    U1STAbits.UTXINV = 0;
    U1MODEbits.URXINV = 0;
#endif

    //Set the tristate and map pins for Uart
    TRIS_U1TX;
    TRIS_U1RX;
    MAP_U1TX;
    MAP_U1RX;
}

void UART2_Config(void)
{
    OpenUART2((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART2_ //Baud rate
            ));
    ConfigIntUART2(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR2 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR1         //Priority TX interrupt 1
            );

#ifdef InvertU2RxTxBits
    U2STAbits.UTXINV = 0;
    U2MODEbits.URXINV = 0;
#endif

    //Set the tristate and map pins for Uart
    TRIS_U2TX;
    TRIS_U2RX;
    MAP_U2TX;
    MAP_U2RX;
}

void Setup_I2C(void)
{
    OpenI2C1(
            I2C1_ON             &
            I2C1_IDLE_CON       &
            I2C1_CLK_REL        &
            I2C1_IPMI_DIS       &
            I2C1_7BIT_ADD       &
            I2C1_SLW_EN         &
            I2C1_SM_EN          &
            I2C1_SM_DIS         &
            I2C1_GCALL_EN       &
            I2C1_STR_EN         &
            I2C1_ACK            &
            I2C1_ACK_DIS         &
            I2C1_RCV_DIS         &
            I2C1_STOP_DIS        &
            I2C1_RESTART_DIS     &
            I2C1_START_DIS
            ,
            0xFFFF
            );

    ConfigIntI2C1(
            MI2C1_INT_OFF &
            MI2C1_INT_PRI_1 );

    return;
}

