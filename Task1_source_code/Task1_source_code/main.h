/*
 * main.h
 *
 * Created: 9/15/2023 10:24:44 AM
 *  Author: oraga
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#include "PERIPHERAL_LIBRARY.h"
#include "MODULE_LIBRARY.h"
#include <stdio.h>
#include <string.h>

#define Max_Users 10
#define Max_Trials 3

typedef struct {
	uint8_t Username[16];
	uint8_t Password[16];
} user;

uint8_t Users_Number = 0;

user Users[Max_Users], Admin = {"12345", "12345"} , User;

uint8_t Login_Trials = 0;

uint8_t Admin_Mode = 0;

uint8_t DoorState = 0;

#endif /* MAIN_H_ */