#include "pcCommunication.h"
#include "usbd_cdc_if.h"
#include "usbBuffers.h"
#include "measurement.h"

extern HorizontalMeasurement mesurement[horizontalSteps];
extern uint8_t UserRxBufferHS[APP_RX_DATA_SIZE];
extern int8_t angle;
/** Data to send over USB CDC are stored in this buffer   */
extern uint8_t UserTxBufferHS[APP_TX_DATA_SIZE];

 
uint8_t MeasurementStartFlag=0;


void sendDataToPc()
{
    
        for(int j=0;j<horizontalSteps;j++)
        {
           UserTxBufferHS[7*j]= angle;
           UserTxBufferHS[7*j+1]= mesurement[j].Angle>>8;
           UserTxBufferHS[7*j+2]= mesurement[j].Angle;
           UserTxBufferHS[7*j+3]= mesurement[j].Distance>>24;
           UserTxBufferHS[7*j+4]= mesurement[j].Distance>>16;
           UserTxBufferHS[7*j+5]= mesurement[j].Distance>>8;
           UserTxBufferHS[7*j+6]= mesurement[j].Distance;
        }
     CDC_Transmit_HS(UserTxBufferHS, APP_TX_DATA_SIZE);

}

void readRequest()
{
    uint32_t bufferLength=1;
    CDC_Receive_HS(UserRxBufferHS,&bufferLength);
    for(int i=0;i<bufferLength;i++)
    {
        if(UserRxBufferHS[i]=='a')
        {
            UserRxBufferHS[i]=0;
            MeasurementStartFlag=1;
            CDC_Transmit_HS("ok",2);
        }
    }
}