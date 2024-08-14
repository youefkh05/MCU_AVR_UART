/*
 * main.c
 *
 * Created: 8/14/2024 10:20:44 AM
 *  Author: youefkh05
 */

#include <xc.h>
#include "main.h"

// Global variables
volatile uint8_t buttonPressed = 0;


int main(void)
{	
	/*		Initializations		*/
	LED1_Initialize();
	LED2_Initialize();
	LED3_Initialize();
	uart_status UART_State= UART_Initialize_WithoutInterrupt(UART_9600,Synchronous, Disable , Bits_8, Bit_1);
	if(UART_State==UART_NOK){
		return 0;
	}
	

	uint8_t UART_Rdata;
	volatile E2PROM_State currentState =Normal_state;
	/*
	UART_Init();
	Timer_Init();
	*/
	

	
	/*	Main	Code	*/
    while(1)
    {	
	
		UART_State= UART_Receive_Word(&UART_Rdata);
		handle_Temp(UART_Rdata,&currentState);
	
    }
}