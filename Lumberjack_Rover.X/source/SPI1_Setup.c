#include    <p24Hxxxx.h>
#include    <spi.h>
#include    <stdio.h>
#include    <pps.h>

#include    "../include/chip_setup.h"

void Setup_SPI1()
{
     OpenSPI1(
            (
            ENABLE_SCK_PIN  &//
       //     FIFO_BUFFER_DISABLE      &
            ENABLE_SDO_PIN          &//
            SPI_MODE16_OFF          &//
            SPI_SMP_ON            &//
            SPI_CKE_ON             &//
            SLAVE_ENABLE_OFF        &//
            CLK_POL_ACTIVE_HIGH     &//
            MASTER_ENABLE_ON        &//
            SEC_PRESCAL_4_1         &//
            PRI_PRESCAL_4_1//
            )
            ,
            (
            FRAME_ENABLE_OFF        &   //NOT USED
            FRAME_SYNC_OUTPUT       &   //NOT USED
            FRAME_POL_ACTIVE_HIGH   &   //NOT USED
            FRAME_SYNC_EDGE_PRECEDE   //NOT USED

            )
            ,
            (
            SPI_ENABLE          &//
            SPI_IDLE_CON        &//
            SPI_RX_OVFLOW_CLR   //
            )
            );

    ConfigIntSPI1(SPI_INT_EN & SPI_INT_PRI_5);

    PPSOutput(OUT_FN_PPS_SCK1, OUT_PIN_PPS_RP8);//CLK
    PPSOutput(OUT_FN_PPS_SDO1, OUT_PIN_PPS_RP7);//MOSI
    PPSInput(PPS_SDI1, PPS_RP6);   //MISO

    TRISBbits.TRISB8 = 0;//Clk
    TRISBbits.TRISB7 = 0;//MOSI
    TRISBbits.TRISB6 = 1;//MISO
    printf("SPI1 Setup\r\n");
    return;
}
