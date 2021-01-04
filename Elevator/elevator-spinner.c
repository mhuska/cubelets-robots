

#include "cubelet.h"
#include <stdint.h>

void setup() {
    
}

void loop() {

    int speed = 50;

    //Get the sensor values
    int sensor_front = get_block_value(1655123);
    int sensor_back = get_block_value(379288);

    //Change direction if we get close to a wall.
    if (sensor_front > 10) {
        set_drive_direction(BACKWARD); 
        set_actuator_value(speed);
    } else if (sensor_back > 10) {
        set_drive_direction(FORWARD);
        set_actuator_value(speed);
    }

        
    
}
  