/*
 * File:   main.c
 * Author: How Jin
 *
 * Created on November 12, 2018, 6:03 PM
 */

// TEST ON

#include "xc.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <p30Fxxxx.h>
#include "IOSetup.h"

int main(void) 
{
    //initialise all necessary modules
    gpIOSetup();
    random();

    //Timer1_Setup();

    // void __attribute__((interrupt, auto_psv)) _T1Interrupt(void);
    //Timer1_ISR();

    //infinite loop
    while(1); //remain here forever, never end the main function.
    return 0; //we should never really return
}

//test branch on master
