#include "encoder.h"

void setup() { 
	Serial.begin(9600); 
	pcint_setup(); 
}

void loop() { 
	Serial.println(R_count); 
}

void pcint_setup(void){ 
	PCICR |= (1<<2); //PCIE2(PCINT23_14) 
	PCMSK2 |= (1<<5) | (1<<6); //PCINT21, PCINT22 
}

ISR(PCINT2_vect){ 
	encoder_rotary();
}

