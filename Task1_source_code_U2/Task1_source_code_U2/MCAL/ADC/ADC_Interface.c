/*
 * ADC_Interface.c
 *
 * Created: 10/7/2023 12:10:21 PM
 *  Author: oraga
 */ 

#include "ADC_Private.h"

void ADC_Initialize(adc_vref voltage , adc_prescaler prescaler)
{
	ADMUX |= 0x40;
	ADCSRA |= 0xA7;
	
	ADCSRA |= (1 << ADIE);
}
uint16_t ADC_Read(adc_channel channel)
{
	uint16_t val = 0;
	switch(channel)
	{
		case ADC_0 :
		ADMUX |= 0x00;
		break;
		case ADC_1 :
		ADMUX |= 0x01;
		break;
		case ADC_2 :
		ADMUX |= 0x02;
		break;
		case ADC_3 :
		ADMUX |= 0x03;
		break;
		case ADC_4 :
		ADMUX |= 0x04;
		break;
		case ADC_5 :
		ADMUX |= 0x05;
		break;
		case ADC_6 :
		ADMUX |= 0x06;
		break;
		case ADC_7 :
		ADMUX |= 0x07;
		break;
	}
	ADCSRA |= 0x40;

}
