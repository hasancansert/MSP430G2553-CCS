#include <msp430.h> 

#define LED BIT0
/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	TA0CTL = TACLR | MC_3 | TASSEL_2 | ID_3 ; // setting timer_A control register to 100kHz and sMSCLK up to down at CCR0 mode

	P1DIR |= LED;
	P1OUT |= LED;

	int delay1 = 25000; //short delay 0.5 sec
	int delay2 = 50000; // long delay 1 sec
	unsigned int CCR[] = {delay1, delay1, delay2, delay2}; // Array of Forbidden Land!
	unsigned int i = 0; // loop variable

	while(1){
	    for(i=0;i<4;i++){ // a loop to call delay1-2 variables.

	        TACCR0 = CCR[i]; // using array's capture compare register value has been changed
	        while((TACTL & TAIFG) != TAIFG); // basically, counting :D
	        TA0CTL &= ~TAIFG; //clear Interrupt flah
	        P1OUT ^= LED; //TOGGLE TOGGLE TOGGLE TOGGLE TOGGLE

	        }
	}



	

}
