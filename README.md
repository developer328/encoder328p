ROTARY ENCODER LIBRARY FOR ATMEGA328P
=====================================

Descripton:
    It is a library for rotary encoder.Of this library purpose 
is detect direction of encoder rotation and increase or decrease 
encoder rotation count. it requiers PCINT ISR for work correctly.

WARNING:
 - if you don't use PCINT ISR it doesn't reads fast rotations, 
especialy WITHOUT PCINT ISR it doesn't works at all if you have 
a big code.

- Also pins and ports only can be changed in 'encoder.c' file by changeing 
values of macros.


#FUNCTIONS:

- void encoder_rotary(void);

- volatile int read_encoder(void);


#VARIABELS:

- volatile static uint8_t A_state = 0;
- volatile static uint8_t B_state = 0;
- volatile int R_count = 0;


#CONFIGURATIONS:

- #define _MIN_ 0
- #define _MAX_ 999
- #define _PIN_A_ 6
- #define _PIN_B_ 5
- #define _PIN_ PIND 


#LIBRARIES:

- #include<avr/io.h>



