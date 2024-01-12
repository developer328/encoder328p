ROTARY ENCODER LIBRARY ATMEGA328P
=================================

Descripton:
    It is simple and customizable library for rotary encoder, 
that library purpose is detect direction of rotation and add 
or subtract 1 to encoder rotation count. it requiers PCINT 
ISR for work correctly.
    WARNING:if you don't use PCINT it doesn't reads fast rotations, 
also WITHOUT PCINT it doesn't works at all if you have big code.

--------------------------
C example:

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

ISR(PCINT2_vect){
    encoder_rotary();
}
---------------------------


---------------------------
ARDUINO example:

    At first you need to download that library directory "Rotary_encoder"
in arduino libraries direcory

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

----------------------------

