/*
 * LM35_TMP_Sensor_Interface.c
 *
 * Created: 8/12/2024 6:19:25 PM
 *  Author: youefkh05
 */ 

#include "LM35_TMP_Sensor_Private.h"

void AServoMotor_Initialize(void)
{
	DDRD |= (1<<PD5);
	
	TCCR1A |= ((1<<WGM11) | (1<<COM1A1));
	TCCR1A &=~ ((1<<WGM10)| (1<<COM1A0));
	TCCR1B |= ((1<<WGM13) | (1<<WGM12) | (1<<CS12));
	TCCR1B &=~ ((1<<CS11) | (1<<CS10));
	ICR1 = 1249;
}

void AServoMotor_Rotate(int angle)
{
	OCR1A = (((ICR1*angle)/100)-1);
}
