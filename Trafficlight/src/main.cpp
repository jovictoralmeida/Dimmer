#include <mbed.h>

#include "headertraffic.hpp"

int main(){
    lights[state] = 1; // Turning on the first state
    bt_pedestrian.rise(&timer_start); // Defining buttom interrupt behavior and function
    bt_pedestrian.fall(&timer_counter);
    timeout.attach (&transition, times[state]); // Defining state timing interruption
}