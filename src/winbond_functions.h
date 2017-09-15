/*
 * file: winbond_functions.h
 *
 * Functions for handling Windond W25Q128 SPI EEPROM.
 */

#ifndef _WINBOND_FUNCTIONS_H_
#define _WINBOND_FUNCTIONS_H_

/* readSR: Read Status Register 1-3
 *
 * Args: reg: Status Register number. 1-3
 * 		 data: Pointer to variable to save data
 * Return: error status. '0' on success.
 */
uint8_t readSR(uint8_t reg, uint8_t *data);


/* writeSR: Write Status Register 1-3
 *
 * Args: reg: Status Register number. 1-3
 * 		 data: Pointer to variable to read data from
 * Return: error status. '0' on success.
 */
uint8_t writeSR(uint8_t reg, uint8_t data);


/* waitSPIAvailable: Wait until SPI device is not busy anymore
 *
 * This function will lock for the busy interval. It wil return when SPI is
 * available again
 */
void waitSPIAvailable(void);


/* writeEnable: Enable write access to the chip
 *
 * This must be called before any write instruction to the device
 * Return: error status. '0' on success.
 */
uint8_t writeEnable(void);

/* readData: Read some bytes of data into data buffer from address
 *	
 * Args: 	data: data buffer to read data into
 * 			num_bytes: number of bytes to read
 * 			address: data address to begin read. Address is 24-bits long
 * Return:	error status. '0' on success.
 *
 * Entire memory (up to address 'MEMORY_SIZE') can be read in single instruction
 * 'data' array must be allocated for full read. 
 */
uint8_t readData(uint8_t *data, uint32_t num_bytes, uint32_t address);

#endif // _WINBOND_FUNCTIONS_H_
