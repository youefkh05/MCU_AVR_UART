/*
 * main.c
 *
 * Created: 8/14/2024 10:20:44 AM
 *  Author: youefkh05
 */

#include <xc.h>
#include "main.h"


int main(void)
{	
	/*		Initializations		*/
	dc_motor DC_mach1=DC_Motor1;
	DC_Initialize(DC_mach1);
	LED1_Initialize();
	LED2_Initialize();
	LED3_Initialize();
	ADC_Initialize(5, 1024);
	uart_status UART_State= UART_Initialize_WithoutInterrupt(UART_9600,Synchronous, Disable , Bits_8, Bit_1);
	if(UART_State==UART_NOK){
		return 0;
	}
	
	//variables
	uint16_t UART_Rdata;
	volatile E2PROM_State currentState =Normal_state;
	uint16_t speed=0;
	/*
	Timer_Init();
	*/
	
	//Start the machine
	DC_Start(DC_mach1,DC_CW);
	
	/*	Main	Code	*/
    while(1)
    {	
		/* Recieve the message (Temperature)	*/
		UART_State= UART_Receive_Word(&UART_Rdata);
		
		speed=ADC_Read(POT1_PIN);
		
		/* Send the message (Speed)	*/
		UART_Transmit_Speed(speed);
		
		/* Hnadle the message	*/
		handle_Mes(UART_Rdata,DC_mach1,&currentState);
    }
}