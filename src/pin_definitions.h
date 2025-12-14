#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H

//Inputs
#define LED_DOOR 5  // P102
#define LED_MUTE 4 //P103
#define LED_SIREN 3 //P104

//Outputs
#define BUZZER_PWM 6 //P106
#define INPUT_DOOR 15 //P000
#define INPUT_MUTE 16 //P001
#define INPUT_SIREN 17 //P002

//Spare GPIOs (if your doorbell needs extra functionality ... ?)

//Breakout Header J4
#define P109 11 //pwm capable
#define P110 12 
#define P111 13 
#define P112 10 //pwm capable

//Breakout Header J5
#define P301 0
#define P302 1
#define P303 9 //pwm capable
#define P304 8

#endif // PIN_DEFINITIONS_H