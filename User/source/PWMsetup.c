/*
 * File:   PWMsetup.c
 * Author: kieraneasdale
 *
 * Created on November 1, 2018, 3:34 PM
 */
#include "LAB6_PWMsetup_EX3.h"
#include "xc.h"
#include <math.h>
#define pi 3.1415926
void PWMsetup(void) {  
    PTCONbits. PTEN     = 0;    // switch off PWM time base during configuration
    PTCONbits. PTCKPS   = 2;    // Pre-scaler 0=1:1, 1=1:4, 2=1:16, 3=1:64
    PTPER               = 4000; // Set the PWM period
    PWMCON1bits. PMOD1  = 1;    // Set PWM unit 1 into the independent mode
    PWMCON1bits. PEN1L  = 1;    // Enable PWM 1 low-side driver
    PWMCON1bits. PEN1H  = 1;    // Enable PWM 1 high-side driver
    PTCONbits. PTEN     = 1;    // Finally, switch on the PWM generator  
}

void Dutycycle(int count){
    float DC;
    
   DC = (sin(2*pi * (count)/(100)) + 1)/(2);
   
   PDC1 = DC * 8000;
   
}

