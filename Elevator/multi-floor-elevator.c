

#include "cubelet.h"
#include <stdint.h>

int loops;
int ischanged;
void setup() {
    loops = 0;
    ischanged = 0;
}

void loop() {

    int speed = 100;
    int threshold = 150;
    
    loops += 1;
        
    //Get the sensor values
    int sensor_top = get_block_value(379281);
    int sensor_lobby = get_block_value(379281);
    int sensor_floor_2 = get_block_value(379288);
   // int sensor_floor_3 = get_blook_value();
      
    //Change direction when at the top
    if (sensor_top > threshold) {
        if (ischanged == 0) {
            ischanged = 1;
            loops = 0;
            toggle_directions();    
        }
    } else if (sensor_lobby > threshold || sensor_floor_2 > threshold) { // || sensor_floor_3 > threshold) {
        if (ischanged == 0) {
            ischanged = 1;
            loops = 0;
            speed =0;
        }
    }
    
    if (loops > 10000) {
        loops = 0;
        ischanged = 0;
        set_actuator_value(speed);  
    }

    if (ischanged == 0) {
        set_actuator_value(speed);  
    }
    
    
        
    
}

    