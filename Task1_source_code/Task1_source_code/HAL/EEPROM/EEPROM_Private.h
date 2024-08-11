/*
 * EEPROM_Private.h
 *
 * Created: 12/13/2023 7:37:55 PM
 *  Author: oraga
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#include "EEPROM_Configurations.h"
#include "PERIPHERAL_LIBRARY.h"
#include "MODULE_LIBRARY.h"

void EEPROM_voidSendDataByte(uint16_t Copy_UINT16LocationAddress, uint8_t Copy_UINT8DataByte);

uint8_t EEPROM_UINT8ReadDataByte(uint16_t Copy_UINT16LocationAddress);
void EEPROM_voidWriteBlock(uint16_t Copy_UINT16LocationAddress, uint8_t* Copy_pUINT8DataBlock, uint16_t Copy_UINT16BlockSize);
void EEPROM_voidReadBlock(uint16_t Copy_UINT16LocationAddress, uint8_t* Copy_pUINT8DataBlock, uint16_t Copy_UINT16BlockSize);




#endif /* EEPROM_PRIVATE_H_ */