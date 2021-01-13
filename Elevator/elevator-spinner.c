

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
    
    loops += 1;
        
    //Get the sensor values
    int sensor = get_block_value(379281);

    set_actuator_value(speed);   
        
    //Change direction if we get close to a wall.
    if (sensor > 150) {
        if (ischanged == 0) {
            ischanged = 1;
            loops = 0;
            toggle_directions();    
        }
    }
    
    if (loops > 10000) {
        loops = 0;
        ischanged = 0;
    }

        
    
}

    