/*
 * APP.c
 *
 * Created: 8/13/2024 6:51:38 PM
 *  Author: youefkh05
 */ 

#include "APP.h"

void handle_Mes(temp T,dc_motor DC_MOT, E2PROM_State* S){
	
	// off all LED and Buzzer
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	BUZZER_OFF();
	
	if(T<=20.0){
		LED3_ON();
		*S=Normal_state;
	}
	else if (T>20.0 && T<=40.0){
		LED2_ON();
		*S=Normal_state;
	}
	else if (T>40.0 && T<=50.0){
		LED1_ON();
	}
	else if (T==Off_Mes)
	{
		*S=Off_state;
		LED1_ON();
		DC_Stop(DC_MOT);
	}
	else if (T==Emergency_Mes)
	{
		*S=Emergency_state;
		LED1_ON();
		BUZZER_ON();
	}
	else {
		LED1_ON();
		LED2_ON();
		LED3_ON();
		*S=Emergency_state;
	}
}

void UART_Transmit_Speed(uint16_t speed){
	// the scale is from 0-250
	uint8_t x= 250*speed/1023;
	UART_Transmit_Character(x);
}