/* 
 * File    : IOsetup.h
 * Author  : K.Easdale & H.Wong
 * Created : 27 November 2018
 */
#include "xc.h"
#ifndef IOSETUP_H
#define	IOSETUP_H
//LED2 
#define LED2L   LATDbits.LATD1
#define LED2P   PORTDbits.RD1 
#define LED2T   TRISDbits.TRISD1 
//LED3
#define LED3L   LATDbits.LATD3
#define LED3P   PORTDbits.RD3
#define LED3T   TRISDbits.TRISD3
//LED4
#define LED4L   LATEbits.LATE0
#define LED4P   PORTEbits.RE0
#define LED4T   TRISEbits.TRISE0
//SWITCH3
#define S3L LATDbits.LATD2
#define S3P PORTDbits.RD2
#define S3T TRISDbits.TRISD2
void IOSetup(void);
#endif	/*IOSETUP_H*/

