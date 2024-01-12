#include<avr/io.h> 
#include<avr/interrupts.h>

#include "encoder.h"

int main(void){ 
	pcint_setup();

	while(1){
		//use "R_count" varible for read encoder count

	}

return 0;
}

void pcint_setup(void){ 
	PCICR |= (1<<2); //PCIE2(PCINT23_14) 
	PCMSK2 |= (1<<5) | (1<<6); //PCINT21, PCINT22 
}
