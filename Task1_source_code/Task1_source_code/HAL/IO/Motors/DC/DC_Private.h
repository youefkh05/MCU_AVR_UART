/*
 * DC_Private.h
 *
 * Created: 10/21/2023 11:27:29 AM
 *  Author: oraga
 */ 


#ifndef DC_PRIVATE_H_
#define DC_PRIVATE_H_

#include "DC_Configurations.h"

void DC_Initialize(dc_motor motor);
void DC_Start(dc_motor motor, dc_motor_direction direction);
void DC_Stop(dc_motor motor);




#endif /* DC_PRIVATE_H_ */