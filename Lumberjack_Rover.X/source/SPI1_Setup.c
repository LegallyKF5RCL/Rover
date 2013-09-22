#include <p24Hxxxx.h>
#include <spi.h>
#include <stdio.h>

#include "../include/chip_setup.h"


void Setup_SPI1()
{
     OpenSPI1(
            (
            ENABLE_SCK_PIN
            )
            ,
            (
            FRAME_ENABLE_OFF        &   //NOT USED
            FRAME_SYNC_OUTPUT       &   //NOT USED
            FRAME_POL_ACTIVE_HIGH   &   //NOT USED
            FRAME_SYNC_EDGE_PRECEDE &   //NOT USED
            FIFO_BUFFER_ENABLE      &
            ENABLE_SDO_PIN          &
            SPI_MODE16_OFF          &
            SPI_SMP_OFF             &
            SPI_CKE_ON              &
            SLAVE_ENABLE_OFF        &
            CLK_POL_ACTIVE_HIGH     &
            MASTER_ENABLE_ON        &
            SEC_PRESCAL_4_1         &
            PRI_PRESCAL_4_1
            )
            ,
            (
            SPI_ENABLE          &
            SPI_IDLE_CON        &
            SPI_RX_OVFLOW_CLR   
            )
            );
    ConfigIntSPI1(SPI_INT_DIS & SPI_INT_PRI_5);




    printf("SPI1 Setup\r\n");
    return;
}
