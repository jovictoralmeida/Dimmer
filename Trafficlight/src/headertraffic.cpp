#include "headertraffic.hpp"
#include "mbed.h"

DigitalOut lights[]={(PD_14),(PD_12),(PD_13)};
InterruptIn bt_pedestrian (PA_0);
int Opmode=0, state=0, TB=0;
float times[] = {10.0, 20.0, 4.0};

void clear_all (){
    int j;
    for(j=0;j<3;j++){
         lights [j]=0;
    }
    if (Opmode == 1){
        timeout.attach(&blink, 0.5);
    }
    
 }

void transition(){
       clear_all ();
       if (state != 2){
           state++;
       }
       else {
           state =0;
       }
       lights[state] = 1;
       timeout.attach (&transition, times[state]);
} 
    
void timer_start(){
    timer.start();
}

void timer_counter(){
    timer.stop();
    TB = timer.read();
    timer.reset();
    button_state();
}
    

void button_state(){
    if (state == 1&&TB <=3){
        transition();
    }
    else if(TB>3&&TB<=10){
            if(Opmode==0){
                Opmode=1;
                clear_all();
            }
            else if(Opmode==1){
                Opmode=0;
                transition();
            }
    }
    else if(TB>10){
            if(Opmode==0){
                Opmode=2;
                clear_all();
            }
            else if(Opmode==2){
                Opmode=0;
                transition();
            }
    }
}

void blink(){
           lights[2] = 1;
           timeout.attach(&clear_all,0.5);
               
}                   