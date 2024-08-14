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

#define F_CPU 8000000UL
#define BOT1_PORT	PORTD
#define BOT1_PIN	DIO_PIN2

/*	states messages	*/
#define Emergency_Mes 300
#define	Off_Mes		  255	



typedef enum
{
	Normal_state = 0,
	Emergency_state = 1,
	Abnormal_state=2
}E2PROM_State;


/* E2PROM	State	*/
void Initialize_E2PROM_State(void);
uint8_t Read_E2PROM_State (void);
void Write_E2PROM_State( E2PROM_State state);

/*	Event handler	*/
void handle_event(temp T,dc_motor DC_fan, E2PROM_State* S);
void handle_State(temp T,dc_motor DC_fan,E2PROM_State* S);
void check_State(temp T,E2PROM_State* S);

/*	Sender	*/
void UART_Transmit_State(const temp T,uint8_t *bot1f);




#endif /* APP_H_ */