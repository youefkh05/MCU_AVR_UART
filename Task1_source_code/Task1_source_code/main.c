/*
 * main.c
 *
 * Created: 8/11/2024 6:15:39 PM
 *  Author: User
 */ 

#include <xc.h>
#include "main.h"

// Global variables
volatile E2PROM_State currentState =Normal_state;
volatile uint8_t buttonPressed = 0;


int main(void)
{	
	/*		Initializations		*/
	temp temperature=0;
	dc_motor DC_fan1=DC_Motor1;
	DC_Initialize(DC_fan1);
	Initialize_E2PROM_State();
	Initialize_TEMP_SENSOR();
	ADC_Initialize(5,1024);
	DIO_SetPinDirection(BOT1_PORT,BOT1_PIN,DIO_INPUT); //push button 
	uart_status UART_State= UART_Initialize_WithoutInterrupt(UART_9600,Synchronous, Disable , Bits_8, Bit_1);
	if(UART_State==UART_NOK){
		return 0;
	}
	
	External_Interrupt0_Initalize(INT0_RISING);
	/*
	Timer_Init();
	*/
	
	// Read initial state from EEPROM
	uint8_t x= Read_E2PROM_State();
	if (x==0)
	{
		DC_Start(DC_fan1,DC_CW);
	}
	_delay_ms(10);

	/*	Main	Code	*/
    while(1)
    {	
		temperature=Read_TEMP_SENSOR();
		UART_Transmit_State(temperature,&buttonPressed);
		handle_event(temperature,DC_fan1,&currentState);
    }
}

/*	Interrupt Service Routine for INT0 (bot1)	 */
ISR(INT0_vect)
{
	 buttonPressed = 1;		/* Set the flag */
	_delay_ms(50);  	/* Software debouncing control delay */
}