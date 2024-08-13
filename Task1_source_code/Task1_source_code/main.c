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
	LED1_Initialize();
	LED2_Initialize();
	LED3_Initialize();
	ServoMotor_Initialize();
    while(1)
    {	x++;
		LED1_TGL();
		LED2_TGL();
		LED3_TGL();
		ServoMotor_Rotate(angle_P90);
		DC_Start(motor1, DC_CW);
		_delay_ms(2000);
		DC_Stop(motor1);
		ServoMotor_Rotate(angle_0);
		_delay_ms(2000);
		DC_Start(motor1, DC_CCW);
		ServoMotor_Rotate(angle_N90);
		_delay_ms(2000);
        //TODO:: Please write your application code 
    }
}