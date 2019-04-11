#ifndef MAIN_HPP
#define MAIN_HPP

#include "mbed.h"

extern int state; // Defining first state as green
extern DigitalOut lights[]; //LED ports definition, associated with the enum
extern float times[]; // States timing definition, associated with the enum
extern InterruptIn bt_pedestrian; // Buttom interrupt object
extern Timeout timeout; // State timer object
extern Timer timer;
extern int TB;
extern int Opmode; //0=standard, 1=blink, 2=off

//***Function prototypes***
void clear_all ();
void transition();
void blink();
void button_state();
void timer_start();
void timer_counter();

#endif