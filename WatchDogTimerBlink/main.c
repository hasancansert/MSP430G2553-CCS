#include <msp430.h> 

#define LED1 BIT0
#define LED2 BIT6


int main(void)
{
       WDTCTL = WDTPW+WDTTMSEL+WDTCNTCL; // 1000 ms delay 1000000
       DCOCTL = CAL_DCO_1MHZ;
       P1DIR |= LED1 | LED2; // p1.0 p1.6 output
       P1OUT |= LED1 | LED2;// initial high
       unsigned int intervals = 0;
       while(1){ // infinite loop
           if(IFG1 & WDTIFG){ // checks if the Whatchdog interrupt flag
               intervals++;
               if(intervals == 15)
               {
                   P1OUT ^= LED1 | LED2; // toggle leds

                   intervals = 0;
               }
               IFG1 &= ~WDTIFG; // set whatchdog interrupt flag cleared
           }
       }


}
