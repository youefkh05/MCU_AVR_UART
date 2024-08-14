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
volatile temp temperature = 0;

int main(void)
{	
	/*		Initializations		*/
	dc_motor DC_fan1=DC_Motor1;
	DC_Initialize(DC_fan1);
	Initialize_E2PROM_State();
	Initialize_TEMP_SENSOR();
	DIO_SetPinDirection(BOT1_PORT,BOT1_PIN,DIO_INPUT); //push button 
	
	/*
	UART_Init();
	Timer_Init();
	*/
	
	// Read initial state from EEPROM
	currentState = Read_E2PROM_State(EEPROM_State_Add);
	
	/*	Main	Code	*/
    while(1)
    {	
		temperature=Read_TEMP_SENSOR();
		
		handle_event(&temperature,&currentState);
    }
}