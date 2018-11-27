/******************************************************************************
* file: Main.c
* Project: LAB3
* Device/Target: dsPIC30F4011 Located on Firecracker Board
* Author: K.Easdale
* Functionality: Toggling LED2 at a rate of 50Hz using Timer1
* 2018-11-3    : Program completed
 *****************************************************************************/
#include "LAB6_Timer1Functions_EX3.h" 
#include "LAB6_header_EX3.h"
#include "LAB6_IOSetup_EX3.h" 
#include "xc.h"
#include <p30F4011.h> 
#pragma config FPR = XT_PLL8            // Primary Oscillator Mode (XT w/PLL 8x)
#pragma config FOS = PRI                // Oscillator Source (Primary Oscillator)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BOREN = PBOR_OFF         // PBOR Enable (Enabled)
#pragma config LPOL = PWMxL_ACT_HI      // Low-side PWM Output Polarity (Active High)
#pragma config HPOL = PWMxH_ACT_LO      // High-side PWM Output Polarity (Active High)
#pragma config PWMPIN = RST_IOPIN       // PWM Output Pin Reset (Control with PORT/TRIS regs)
#pragma config MCLRE = MCLR_DIS         // Master Clear Enable (Disabled)
int main(void){
                //Initialise all necessary modules
  IOSetup();    //configures I/O
  PWMsetup();   //configures the PWM generator
  timer1();     //Configure and start timer1
  UART2setup();
  while(1);
  return 0;     //we should never really return
}
    