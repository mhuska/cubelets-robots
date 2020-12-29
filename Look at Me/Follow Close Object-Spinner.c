#include "cubelet.h"
#include <stdbool.h>

void setup() {
}

void loop() {
    block_value = 0;
    
    //Get the sensor values
    double sensor_1 = (double) get_block_value(379281);
    double sensor_2 = (double) get_block_value(379288);
    
    //Adjust sensor 1 to make up for miscalibration
    sensor_1 = sensor_1 + (0.1677 * sensor_1 + 14.741);

    //Get the difference between the two sensors
    int diff = (int) sensor_2 - (int) sensor_1;
    int slow = 45;
    int really_slow = 25;
    int fast = 80;
    int lower_range = 30;
    
    if (sensor_1 <= lower_range && sensor_2 <= lower_range) {
      // It sees nothing.
      block_value = fast;
    } else if (diff <= 15 && diff >= -15) {
      // Center
      block_value = 0;
    } else if (diff > 0) {
        //Go Left
      set_drive_direction(BACKWARD);
      block_value = diff < 40 ? really_slow : slow;
    } else {
        // Go Right
        diff = -diff;
        set_drive_direction(FORWARD);
      block_value = diff < 40 ? really_slow : slow;
    }
    set_actuator_value(block_value);

}
