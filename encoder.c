#include <avr/io.h>
#include "encoder.h"

#define _MIN_ 0
#define _MAX_ 999
#define _PIN_A_ 6
#define _PIN_B_ 5
#define _PIN_ PIND 
	
volatile static uint8_t A_state = 0;
volatile static uint8_t B_state = 0;
volatile int R_count = 0;	
	
void encoder_rotary(void)
{
	if (!(_PIN_ & (1<<_PIN_B_)) && (_PIN_ & (1<<_PIN_A_)) && !B_state) {  // detect direction
		B_state = 0;
		A_state = 1;
	}

	if (!(_PIN_ & (1<<_PIN_A_)) && (_PIN_ & (1<<_PIN_B_)) && !A_state) {  // detect direction
		A_state = 0;
		B_state = 1;
	}

	if ((_PIN_ & (1<<_PIN_B_)) && (_PIN_ & (1<<_PIN_A_))) {  //both are zero = reset
		A_state = 0;
		B_state = 0;
	}


	if (!(_PIN_ & (1<<_PIN_B_)) && !(_PIN_ & (1<<_PIN_A_))) {  //check if encoder movment continues
		
		if (A_state) {
			if (R_count < _MAX_)
			{
				R_count++;
			}
			A_state = 0;  //reset
		}

		if (B_state) {
			if (R_count > _MIN_)
			{
				R_count--;			  
			}
			B_state = 0;  // reset
		}
	}
}

volatile int read_encoder(void){
	return R_count;
}

