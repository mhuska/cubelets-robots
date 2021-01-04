
#include "cubelet.h"
#include <stdint.h>

int loops;

void setup() {
 loops = 0;
}

void loop() {

    loops += 1;
    int bored = loops > 500 ? 1 : 0;
    int redirected = loops > 1000 ? 1 : 0;

    //Get the sensor values
    double sensor_1 = (double) get_block_value(379281);
    double sensor_2 = (double) get_block_value(379288);

    //Calibrate the distance sensor so they read equally at equal distances
    sensor_1 = sensor_1 + (0.1677 * sensor_1 + 14.741);
    
    //Get the difference between the two sensors
    int diff = (int) sensor_2 - (int) sensor_1;
    int avg = (sensor_1 + sensor_2) / 2;

    int fast = 150;
    int slow = 100;
    int really_slow = 40;

    int lower_range = 15;
    
    int value = 0;
    
    if (bored == 0) {
        if (avg > 200) {
            value += (200 - avg) * 2.5;
            loops = 0;
        } else if (avg < 150) {
            value += (255 - avg);
            loops = 0;
        }
        
        if (sensor_1 <= lower_range && sensor_2 <= lower_range) {
          // It sees nothing.
          value = slow;
        } else if (diff <= 25 && diff >= -25) {
          // Center - do nothing
        } else {
        //Go left or right
          value -= diff;
          loops = 0;
        } 
    } else {
        //Move wheel back to change durection
        value = -slow;
        if (redirected == 1) {
            loops = 0;
        }
    }
 
    
    if (value < 0) {
        set_drive_direction(BACKWARD);
        value = -value;      
    } else {
        set_drive_direction(FORWARD); 
    }

    block_value = value;
    set_actuator_value(block_value);
    
}
  