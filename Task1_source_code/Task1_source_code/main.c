/*
 * main.c
 *
 * Created: 8/11/2024 6:15:39 PM
 *  Author: User
 */ 

#include <xc.h>
#include "main.h"

int main(void)
{	int x=0;
	dc_motor motor1=DC_Motor1;
	DC_Initialize(motor1);
    while(1)
    {	x++;
		DC_Start(motor1, DC_CW);
		_delay_ms(2000);
		DC_Stop(motor1);
		_delay_ms(2000);
		DC_Start(motor1, DC_CCW);
		_delay_ms(2000);
        //TODO:: Please write your application code 
    }
}