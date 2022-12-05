#include <msp430.h> 
#define LED1 BIT0
#define LED2 BIT6


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	TA0CTL = TACLR | MC_3 | TASSEL_2 | ID_3 ; // setting timer_A control register to 100kHz and sMSCLK up to down at CCR0 mode
	TACCR0 = 50000; // in the 100kHz mode up/down 50.000 = 1 second

	P1DIR |= LED1 | LED2; // setting as outputs
	P1OUT |= LED1 | LED2; // setting outputs initial high
	
	while(1){
	    while((TACTL & TAIFG) != TAIFG); // counting until Interrupt flag = 0
	    P1OUT ^= LED1 | LED2;               //Blinking On/Off the LEDs
	    TA0CTL &=~ TAIFG;                   //Reset TAIFG

	}

}
