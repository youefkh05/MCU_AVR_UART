/*
 * APP.c
 *
 * Created: 8/13/2024 6:51:38 PM
 *  Author: youefkh05
 */ 

#include "APP.h"



void Initialize_E2PROM_State(void){
	
	/* It should have a normal state first	*/
	eeprom_write_byte ((uint8_t)EEPROM_State_Add, (uint8_t)Normal_state);	
}

E2PROM_State Read_E2PROM_State (const uint8_t *EEPROM_Add){
	
	/*	read the state	*/
	E2PROM_State x= eeprom_read_byte (EEPROM_Add); 		
	return x;
}

void Write_E2PROM_State(const uint8_t EEPROM_Add, E2PROM_State state){
	
	/*	write the state	*/
	eeprom_write_byte (EEPROM_Add, state);
}


void handle_event(temp* T, E2PROM_State* S){
	
	/*	check the state	*/
	check_State(T,S);
	handle_State(T,S);
}

void check_State(temp *T,E2PROM_State* S){
	
	/*	check if the state is changed	*/
	if(*T<50.0 && *S!=Normal_state){
		*S=Normal_state;
		eeprom_write_byte ((uint8_t)EEPROM_State_Add, *S);
		//stop timer
	}
	else if(*T>=50.0 && *S!=Emergency_state){
		*S=Emergency_state;
		eeprom_write_byte ((uint8_t)EEPROM_State_Add, *S);
		//start timer
	}
	
}

void handle_State(temp *T,E2PROM_State* S){
	switch (*S){
		case Normal_state:
			if(*T<=20.0){
				//Stop fan 
				//Send LED green
			}
			else if (*T>20.0 && *T<=40.0){
				//increase fan speed
				//Send LED yellow
			}
			else {
				//nothing
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