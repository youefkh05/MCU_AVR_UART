/*
 * Servo_Interface.c
 *
 * Created: 10/21/2023 2:08:09 PM
 *  Author: oraga
 */ 

#include "Servo_Private.h"

void ServoMotor_Initialize(void)
{
	DDRD |= (1<<PD5);
	
	TCCR1A |= ((1<<WGM11) | (1<<COM1A1));
	TCCR1A &=~ ((1<<WGM10)| (1<<COM1A0));
	TCCR1B |= ((1<<WGM13) | (1<<WGM12) | (1<<CS12));
	TCCR1B &=~ ((1<<CS11) | (1<<CS10));
	ICR1 = 1249;
}

void ServoMotor_Rotate(servo_angle angle)
{
	OCR1A = (((ICR1*angle)/100)-1);
}
