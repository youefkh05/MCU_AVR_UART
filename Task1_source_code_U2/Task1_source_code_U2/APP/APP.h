/*
 * APP.h
 *
 * Created: 8/13/2024 6:51:38 PM
 *  Author: youefkh05
 */ 


#ifndef APP_H_
#define APP_H_

#include "PERIPHERAL_LIBRARY.h"
#include "MODULE_LIBRARY.h"
#include "math.h"

//potentiometer1
#define POT1_PORT	PORTA
#define POT1_PIN	DIO_PIN0

//Buzzer1
#define BUZZ1_PORT	PORTB
#define BUZZ1_PIN	DIO_PIN2


/*	states messages	*/
#define Emergency_Mes 300
#define	Off_Mes		  255

typedef enum
{
	Normal_state = 0,
	Emergency_state = 1,
	Abnormal_state=2,
	Off_state=3
}E2PROM_State;

/* handlers	*/
void handle_Mes(temp T,dc_motor DC_MOT, E2PROM_State* S);

/* Sender	*/
void UART_Transmit_Speed(uint16_t speed);

#endif /* APP_H_ */