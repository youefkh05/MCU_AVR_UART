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

/*	states messages	*/
#define Emergency_Mes 300
#define	Off_Mes		  255

typedef enum
{
	Normal_state = 0,
	Emergency_state = 1,
	Abnormal_state=2
}E2PROM_State;

void handle_Temp(temp T, E2PROM_State* S);


#endif /* APP_H_ */