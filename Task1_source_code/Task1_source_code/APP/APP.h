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

//Ohm
#define A_MUX_2 DIO_PIN4
#define B_MUX_2 DIO_PIN5


//volt and current
#define A_MUX_3 DIO_PIN6
#define B_MUX_3 DIO_PIN7


typedef enum
{
	Normal_state = 0,
	Emergency_state = 1,
	Abnormal_state=2
}E2PROM_State;

void Initialize_E2PROM_State(void);
E2PROM_State Read_E2PROM_State (const uint8_t *EEPROM_Add); 		
void Write_E2PROM_State(const uint8_t EEPROM_Add, E2PROM_State state);




#endif /* APP_H_ */