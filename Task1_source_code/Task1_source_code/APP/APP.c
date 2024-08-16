/*
 * APP.c
 *
 * Created: 8/13/2024 6:51:38 PM
 *  Author: youefkh05
 */ 

#include "APP.h"

uint8_t EEPROM_State_Add=0b01000000;	//any place

void Initialize_E2PROM_State(void){
	
	/* It should have a normal state first	*/
	eeprom_update_byte (&EEPROM_State_Add, (uint8_t)Normal_state);	
	eeprom_update_byte (&EEPROM_State_Add, (uint8_t)Normal_state);	
}

uint8_t Read_E2PROM_State (void){
	
	/*	read the state	*/
	uint8_t x= eeprom_read_byte (&EEPROM_State_Add); 		
	return x;
}

void Write_E2PROM_State( E2PROM_State state){
	
	/*	write the state	*/
	eeprom_write_byte (&EEPROM_State_Add, (uint8_t)state); 
}


void handle_event(temp T,dc_motor DC_fan,uint8_t Speed, E2PROM_State* S){
	
	/*	check the state	*/
	check_State(T,S);
	handle_State(T,DC_fan,Speed,S);
}

void check_State(temp T,E2PROM_State* S){
	
	/*	check if the state is changed	*/
	if(T<50.0 && *S!=Normal_state){
		*S=Normal_state;
		eeprom_write_byte (&EEPROM_State_Add, *S);
		//stop timer
	}
	else if(T>=50.0 && *S!=Emergency_state){
		*S=Emergency_state;
		eeprom_write_byte (&EEPROM_State_Add, *S);
		//start timer
	}
	
}

void handle_State(temp T,dc_motor DC_fan,uint8_t Speed,E2PROM_State* S){
	switch (*S){
		case Normal_state:
			if(T<=20.0){
				DC_Stop(DC_fan);
			}
			else if (T>20.0 && T<=40.0){
				//increase fan speed
				DC_Start(DC_fan,DC_CW);
				DC_Change_Speed(DC_fan,(temp)T*4*(Speed/250));
			}
			else if (T>40 &&T<=50) {
				//max speed
				DC_Start(DC_fan,DC_CW);
				DC_Change_Speed(DC_fan,40*4);
			}
			else{
				//emergency
			}
		break;
		case Emergency_state:
			//strat counting down
			//max fan speed
			//Sen LED Red 
		break;
		case Abnormal_state:
		break;
	}
	//stop fan	
}

void UART_Transmit_State(const temp T,uint8_t *bot1f){
	if (T>=50)
	{
		/* Reset the flag	*/
		*bot1f=0;
		//send the emergency signal
		uart_status x=UART_Transmit_Word(Emergency_Mes);
	}
	else if (T>40 && T<=50 && *bot1f==1)
	{	
		//send the off signal
		uart_status x=UART_Transmit_Word(Off_Mes);
	}
	else{
		/* Reset the flag	*/
		*bot1f=0;
		uart_status x=UART_Transmit_Word(T);
	}
}

void UART_Receive_Speed(uint8_t* Speed){
	uint8_t temp_Speed;
	uart_status s	=	UART_Receive_Character(&temp_Speed); 
	if (s==UART_OK)
	{
		*Speed=temp_Speed;
	}
}