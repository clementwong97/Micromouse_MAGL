/*
 * File:   BaseFunc.c
 * Author: Kieran Easdale
 * Created on October 18, 2018, 2:30 PM
 */
#include "LAB6_header_EX3.h"
#include "LAB6_IOSetup_EX3.h"
#include "xc.h"
void myDelay(unsigned int timeInMilliseconds)
{
    int i, j;
   for(i=0;i<=timeInMilliseconds;i++){
        for(j=0;j<=1958; j++){   
       }
   }  
}
int Debounce(int* stateS3)
{
    int i, sample = 0;
    if((!S3P) && (!*stateS3)) 
    {
        for (i=0; i < 10; i++)
        {
            if(!S3P)
                sample ++;
        myDelay(1);
        }
        *stateS3 =1; 
        }  
    if((S3P) && (*stateS3))
        *stateS3=0;
    
        if(sample == 10)
            return 1;
        else
            return 0;     
}