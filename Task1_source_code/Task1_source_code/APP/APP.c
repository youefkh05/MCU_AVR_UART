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