#include    <p24Hxxxx.h>
#include    <stdio.h>
#include    <spi.h>
#include    <Generic.h>

#include    "../include/globals.h"

#include    <string.h>
/**
 * Single Buffer Blocking SPI1
 * Input
 * Data - The data to send up and the Data back after it was sent
 * Length - Total length of Data
 * Device - The device to send it to [Maybe removed due to lack of devices]
 *
 * Return
 * Void
 */
void Device_Control(eDevices SelDevice,eState State);

typedef enum
{
    FirstRun,
    Waiting,
    TxFinshed,
    Packet_Complete
}eSpi_Status;

typedef struct
{
    BYTE * InOutData;
    int Length;
    eSpi_Status State;
}sSpi_Info;

sSpi_Info Spi_Info;


void Send_SPI(BYTE * Data,int Len,eDevices Device)
{
//TEST DELETE
    char SmallBuff[4],BigBuff[128];
    int i;

    BigBuff[0] = 0;
    for(i = 0; i< Len;i++)
    {
        sprintf(SmallBuff,"%02X",Data[i]);
        strcat(BigBuff,SmallBuff);
    }
    printf("This is to be sent\r\n%s\r\n",BigBuff);
//TEST DELETE    
    Device_Control(Device, ACTIVE);

    Spi_Info.State = FirstRun;
    Spi_Info.InOutData = (BYTE*)&Data[0];
    Spi_Info.Length = Len;

    //Junk = SPI1BUF;
    //Junk = SPI1BUF;

    _SPI1IF = 0;//Clean
    EnableIntSPI1;

    _SPI1IF = 1;
    i=0;
    while(Spi_Info.State != Packet_Complete)//Wait for the last RX to come home
    {
        //Waiting
    }
    
    //THE SPI Interrupt is Off now
    Device_Control(Device, IDLE);//And Reset the State;

//TEST DELETE
    BigBuff[0] = 0;
    for(i = 0; i< Len;i++)
    {
        sprintf(SmallBuff,"%02X",Data[i]);
        strcat(BigBuff,SmallBuff);
    }
    printf("%s\r\nWas Recived\r\n",BigBuff);
//Test DELETE
    return;
}
/**
 * Rough first Round... If there is only One device needs no more work
 * @param SelDevice
 */
void Device_Control(eDevices SelDevice,eState State)
{
    //Device1 = Raise;
    switch(SelDevice)
    {
    case(ACCEL):
        LATBbits.LATB5  = !State;
    }
    return;
}

void __attribute__((interrupt,auto_psv)) _ISR _SPI1Interrupt(void)
{
    static int RxIn,TxOut;
    static BYTE Junk;

    if(Spi_Info.State == FirstRun)//Nothing Has been Sent yet
    {
        Spi_Info.State = Waiting;//Went through the first run
        Junk = SPI1BUF;//JustInCase clean Up.
        RxIn = 0;//Init
        TxOut = 0;//Init
    }

    if(SPI1STATbits.SPIRBF)//Got A Live one here
    {
         _SPI1IF = 0;    //Clear interrupt
        Spi_Info.InOutData[RxIn] = SPI1BUF;//Grab Data
        RxIn++;//Increament Counter
        if(RxIn == Spi_Info.Length)//Check if the data has finished
        {
            DisableIntSPI1;
            Spi_Info.State = Packet_Complete;//Change State
            Spi_Info.InOutData = NULL;//Dump the Pointer
        }
    }
    if(!SPI1STATbits.SPITBF && Spi_Info.State != TxFinshed)//The reg is Empty and ready for a Tx byte && Not finished with the Tx stuff
    {
         _SPI1IF = 0;    //Clear interrupt
        SPI1BUF = Spi_Info.InOutData[TxOut];//Next byte out
        TxOut++;//Increament the Counter
        if(TxOut == Spi_Info.Length)//test if that was the last one to leave
        {
            Spi_Info.State = TxFinshed;//Change State
        }
    }

    return;
}

