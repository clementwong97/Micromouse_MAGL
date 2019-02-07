/*
 * File:   UART.c
 * Author: Kieran Easdale & H.Wong
 * Created on 27 Nov
 */
#include "UART.h"
#include "IOsetup.h"
#include "xc.h"
void UART2setup(void) 
{
U1MODEbits. UARTEN  = 0;        // disable UART during config
U2BRG               = 16.361;   //choose appropriate baud rate
U2MODEbits. LPBACK  = 0;        //disable loopback mode
U2MODEbits. WAKE    = 0;        //do not wake-up on serial activity (don?t care)
U2MODEbits. ABAUD   = 0;        // no auto-baud detection
U2MODEbits. PDSEL   = 0;        // 8 databits, no parity
U2MODEbits. STSEL   = 0;        //one stop bit
U2STAbits.  URXISEL = 0;        //receive interrupt when 1 character arrives
IFS1bits.   U2RXIF  = 0;        //clear rx interrupt flag
IPC6bits.   U2RXIP  = 3;        //set receive interrupt priority
IEC1bits.   U2RXIE  = 1;        //enable receive interupts
U2MODEbits. UARTEN  = 1;        //now, enable UART!
U2STAbits.  UTXEN   = 1;        //and enable transmission (order important)
}

void __attribute__((interrupt, no_auto_psv)) _U2RXInterrupt(void)
{
    IFS1bits.   U2RXIF  = 0; 
    LED2L = ~LED2L;    
}

//dev/tty*
//screen /dev/tty.usbserial-AE0168ML 576500


//void __attribute__((interrupt, no_auto_psv)) _U2TXInterrupt(void)
//{
//    IFS1bits.   U2RXIF  = 0;       
//}