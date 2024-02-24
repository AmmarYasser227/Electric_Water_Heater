

#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_

#include <avr/io.h>

#define get_bit(reg,bitnum) ((reg & (1<<bitnum))>>bitnum) // get bit macro used to get the value of a certain bit.



#include <util/delay.h>

void TWI_Init (void);

void TWI_Start (void);

void TWI_Stop (void);

void TWI_Write (char data);

void TWI_Read_Nack (char* ptr);






#endif /* I2C_DRIVER_H_ */


//#include <stdint.h>
//#include <avr/io.h>
//#include <math.h>


//void I2C_Init();
//void I2C_Start(char write_address);
//void I2C_Repeated_Start(char read_address);
//void I2C_Stop();
//void I2C_Write(char data);
//char I2C_Read_Ack();
//char I2C_Read_Nack();
