#include "cubelet.h"
#include <stdbool.h>



void something(void){
  if (weighted_average() > 50) {
    toggle_directions();
    set_actuator_value(150);
  } else {
    set_actuator_value(0);
  }

}


void setup() {

  set_interval(200, something);

}

void loop() {

}