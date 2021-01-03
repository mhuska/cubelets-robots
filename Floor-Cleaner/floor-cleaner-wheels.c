

#include "cubelet.h"
#include <stdint.h>

void setup() {
    
}

void loop() {

    //Get the sensor values
    int sensor_front = get_block_value(379288);
    int sensor_back = get_block_value(1705204);

    //Change direction if we get close to a wall.
    if (sensor_front > 50) {
        set_drive_direction(BACKWARD); 
        set_actuator_value(180);
    } else if (sensor_back > 50) {
        set_drive_direction(FORWARD);
        set_actuator_value(180);
    }

        
    
}
  