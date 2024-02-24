

#include "EEPROM.h"

void EEPROM_Write (char data, char address)
{

	TWI_Start();

	TWI_Write(0xA8); //slave address is 1010.100 and a 0 in the 8th bit to indicate Writting.

	TWI_Write(address);

	TWI_Write(data);

	TWI_Stop();

}

void EEPROM_Read (char address, char* ptr)
{

	TWI_Start();

	TWI_Write(0xA8);

	TWI_Write(address);

	TWI_Start();

	TWI_Write(0xA9);

	TWI_Read_Nack(ptr);

	TWI_Stop();




}
