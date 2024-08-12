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
	servo_angle angle;
	ServoMotor_Initialize();
    while(1)
    {	x++;
		angle=angle_P90;
		
		ServoMotor_Rotate(angle);
		_delay_ms(2000);
		angle=angle_0;
		ServoMotor_Rotate(angle);
		_delay_ms(2000);
		angle=angle_N90;
		ServoMotor_Rotate(angle);
		_delay_ms(2000);
		
        //TODO:: Please write your application code 
    }
}