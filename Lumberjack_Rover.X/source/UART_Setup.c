/*
 * File:   UART_Setup.c
 * Author: Mike Peters
 * 1000750876
 *
 * Final Lab Project
 */

#include <pps.h>
//#include "../include/pin_setup.h"
#include "../include/uart_config.h"

/*
 * Uncomment InvertBits to invert the bits to Active High
 */
//#define InvertRxTxBits



//Set up UART and pins
//UART Pins are on RPn (remappable)

void UART1_Config(void){

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

void UART2_Config(void){

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