
#include "cubelet.h"

void setup() {

}

void loop() {
    //Get the sensor values
    double sensor_1 = (double) get_block_value(379281);
    double sensor_2 = (double) get_block_value(379288);
    
    //Adjust sensor 1 to make up for miscalibration
    sensor_1 = sensor_1 + (0.1677 * sensor_1 + 14.741);
    
    //Get the difference between the two sensors
    int diff = (int) sensor_2 - (int) sensor_1;
    int avg = (sensor_1 + sensor_2) / 2;
    int slow = 100;
    int really_slow = 50;
    int fast = 150;
    int lower_range = 10;
    
    int value = 0;
    
    if (avg > 200) {
          value += (200 - avg) * 2;
    } else if (avg < 150) {
          value += (150 - avg);
    }
    
    if (sensor_1 <= lower_range && sensor_2 <= lower_range) {
      // It sees nothing.
      value = 0;
    } else if (diff <= 25 && diff >= -25) {
      // Center - do nothing
    } else {
    //Go left or right
      value += diff;
    } 
    
    if (value < 0) {
        set_drive_direction(BACKWARD);
        block_value = -value;
    } else {
        set_drive_direction(FORWARD); 
        block_value = value;
    }
    
    set_actuator_value(block_value);
    
}
  