#ifndef MAIN_HPP
#define MAIN_HPP

#include "mbed.h"
PwmOut led[]={(PD_15),(PD_13)};
PwmOut iLED(PD_12);
//bool state = 0;
InterruptIn bt_press (PA_0);
Timeout timebutton;
Timeout timeout;

void button_push();
void switch_operation();
void change_brightness();

#endif