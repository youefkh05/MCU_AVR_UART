/*
 * EEPROM_Interface.c
 *
 * Created: 12/13/2023 7:38:54 PM
 *  Author: oraga
 */ 

#include "EEPROM_Private.h"
//----------------------------------------------------------------------------------------------------------------------------------------------------

void EEPROM_voidSendDataByte(uint16_t Copy_UINT16LocationAddress, uint8_t Copy_UINT8DataByte)
{
	uint8_t Local_UINT8AddressPacket;

	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS   | (uint8_t)(Copy_UINT16LocationAddress >>8);

	/*if 24C02 :
	 * 	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet*/
	TWI_SendSlaveAddressWithWrite(Local_UINT8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((uint8_t)Copy_UINT16LocationAddress);

	/*Send the data byte to the memory location*/
	TWI_MasterWriteDataByte(Copy_UINT8DataByte);

	/*Send stop condition*/
	TWI_SendStopCondition();

	/*Delay until the write cycle is finished*/
	_delay_ms(10);
}

uint8_t EEPROM_UINT8ReadDataByte(uint16_t Copy_UINT16LocationAddress)
{
	uint8_t Local_UINT8AddressPacket, Local_UINT8Data;

	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS   | (uint8_t)(Copy_UINT16LocationAddress >>8);

	/*if 24C02 :
	 * 	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS | A2_CONNECTION <<2 | A1_CONNECTION <<1 | A0_CONNECTION;
	 */

	/*Send start condition*/
	TWI_SendStartCondition();

	/*Send the address packet with write request*/
	TWI_SendSlaveAddressWithWrite(Local_UINT8AddressPacket);

	/*Send the rest 8bits of the location address*/
	TWI_MasterWriteDataByte((uint8_t)Copy_UINT16LocationAddress);

	/*Send repeated start to change write request into read request*/
	TWI_SendRepeatedStart();

	/*Send the address packet with read request*/
	TWI_SendSlaveAddressWithRead(Local_UINT8AddressPacket);
	
	/*Get the data from memory*/
	TWI_MasterReadDataByte(&Local_UINT8Data);

	/*send the stop condition*/
	TWI_SendStopCondition();

	return Local_UINT8Data;
} 
void EEPROM_voidWriteBlock(uint16_t Copy_UINT16LocationAddress, uint8_t* Copy_pUINT8DataBlock, uint16_t Copy_UINT16BlockSize)
{
	uint8_t Local_UINT8AddressPacket;

	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS | (uint8_t)(Copy_UINT16LocationAddress >> 8);

	/* Send start condition */
	TWI_SendStartCondition();

	/* Send the address packet */
	TWI_SendSlaveAddressWithWrite(Local_UINT8AddressPacket);

	/* Send the rest 8 bits of the location address */
	TWI_MasterWriteDataByte((uint8_t)Copy_UINT16LocationAddress);

	/* Send the data block to the memory location */
	for (uint16_t i = 0; i < Copy_UINT16BlockSize; i++) {
		TWI_MasterWriteDataByte(Copy_pUINT8DataBlock[i]);
		_delay_ms(5); // Delay between consecutive writes
	}

	/* Send stop condition */
	TWI_SendStopCondition();

	/* Delay until the write cycle is finished */
	_delay_ms(10);
}

void EEPROM_voidReadBlock(uint16_t Copy_UINT16LocationAddress, uint8_t* Copy_pUINT8DataBlock, uint16_t Copy_UINT16BlockSize)
{
	uint8_t Local_UINT8AddressPacket;

	Local_UINT8AddressPacket = EEPROM_FIXED_ADDRESS | (uint8_t)(Copy_UINT16LocationAddress >> 8);

	/* Send start condition */
	TWI_SendStartCondition();

	/* Send the address packet with write request */
	TWI_SendSlaveAddressWithWrite(Local_UINT8AddressPacket);

	/* Send the rest 8 bits of the location address */
	TWI_MasterWriteDataByte((uint8_t)Copy_UINT16LocationAddress);

	/* Send repeated start to change write request into read request */
	TWI_SendRepeatedStart();

	/* Send the address packet with read request */
	TWI_SendSlaveAddressWithRead(Local_UINT8AddressPacket);

	/* Get the data block from memory */
	for (uint16_t i = 0; i < Copy_UINT16BlockSize - 1; i++) {
		TWI_MasterReadDataByte(&Copy_pUINT8DataBlock[i]);
		_delay_ms(5); // Delay between consecutive reads
	}

	/* Read the last byte without sending an acknowledgment */
	TWI_MasterReadDataByte(&Copy_pUINT8DataBlock[Copy_UINT16BlockSize - 1]);

	/* Send the stop condition */
	TWI_SendStopCondition();
}