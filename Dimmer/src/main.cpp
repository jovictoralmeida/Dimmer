#include "headerdimmer.hpp"
#include "mbed.h"
bool state = 0;

int main() {
     bt_press.rise(&button_push);
     bt_press.fall(&switch_operation);
     led[state] = 1;
    
}
void button_push(){
    timebutton.attach(&change_brightness,1);
    bt_press.fall(&switch_operation);
}

void switch_operation(){
    led[state] = 0;
    state = !state;
    led[state] = 1; 
}
    
void change_brightness(){
    if(state==0){
        if(iLED < 1.0){
            iLED = iLED + 0.05;
            led[0].period(1.0f);  // 1 second period
            led[0].write(0.80f);  // 80% cycle on
            timeout.attach(&change_brightness,1);
        }
        else{
            led[0].period(0.2f);  // 0.2 second period
            led[0].write(0.50f);  // 50% cycle on
            timeout.attach(&switch_operation,2);
        }
    }
    else{
        if(iLED > 0){
            iLED = iLED - 0.05;
            led[1].period(1.0f);  // 1 second period
            led[1].write(0.80f);  // 80% cycle on
            timeout.attach(&change_brightness,1);
        }
        else{
            led[1].period(0.2f);  // 0.2 second period
            led[1].write(0.50f);  // 50% cycle on
            timeout.attach(&switch_operation,2);
        }
    }
     
}