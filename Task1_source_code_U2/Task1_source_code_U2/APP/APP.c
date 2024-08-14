/*
 * APP.c
 *
 * Created: 8/13/2024 6:51:38 PM
 *  Author: youefkh05
 */ 

#include "APP.h"

void handle_Temp(temp T, E2PROM_State* S){
	
	// off all LED for a 1ms
	LED1_OFF();
	LED2_OFF();
	LED3_OFF();
	
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
		LED1_OFF();
		LED2_OFF();
		LED3_OFF();
	}
	else if (T==Emergency_Mes)
	{
	}
	else {
		LED1_ON();
		*S=Emergency_state;
	}
}