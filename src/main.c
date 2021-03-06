#include <stdint.h>
#include <stdio.h>
#include "app_functions.h"
#include "error.h"

// Global error variable
uint8_t errvar = ERROR_NO_ERROR;

int main(){
	uint8_t err;
	
	err = eepromDump();
	
	if (err){
		printError();
		return 1;
	}
	else{
		printf("All done!\n");
		printf("Exiting..\n");
		return 0;
	}
}
