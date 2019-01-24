/*
 * File:   timer_functions.c
 * Author: Kieran Easdale & H.Wong
 * Created on 27 Nov
 */
#include "LAB6_timerfunctions.h"
#include "IOsetup.h"
#include "PWMsetup.h"
#include "xc.h"

void timer1(void) {
    T1CONbits. TON = 0;          //switches the timer off during setup (good practice)
    T1CON = 0;
    TMR1 = 0;
    T1CONbits. TCKPS = 2;        //Pre-scaler 0=1:1, 1=1:8, 2=1:64, 3=1:256
    PR1 = 2500;                   //choose an appropriate value for the period register
    T1CONbits. TCS =0;           //chooses internal clock
    T1CONbits. TSIDL = 1;        //stop timer in idle mode
    T1CONbits. TGATE = 0;        // do not gate the timer
    IFS0bits.  T1IF = 0;         //clear the interrupt flag CLEAR T1IF
    IPC0bits.  T1IP = 3;         //choose interrupt priority
    IEC0bits.  T1IE = 1;         // enable Timer1 interrupt
    T1CONbits. TON = 1;          //switches the Timer 1 on!      
}
//ISR
void __attribute__((interrupt, auto_psv)) _T1Interrupt(void)
{
    static int count = 0;
    LED2L = ~LED2L;
    IFS0bits.T1IF=0; ///reset the timer 1 interrupt flag
    count ++;
    
    if(count == 99){
        LED3L = ~LED3L;
        count = 0;
    }
    
    Dutycycle(count);
}