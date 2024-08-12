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
	/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/8 */
	TCCR1A = (1<<WGM11)|(1<<COM1A1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS11);
	TCNT1=0;
	ICR1 = 19999; //fPWM=50Hz (Period = 20ms Standard).
}

void ServoMotor_Rotate(servo_angle angle)
{
	OCR1A = (((ICR1*angle)/100)-1);
	_delay_ms(1500);
}
