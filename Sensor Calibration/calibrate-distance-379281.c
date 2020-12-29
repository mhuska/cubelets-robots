
#include "cubelet.h"

void setup() {

}

void loop() {
   sense();
}

void sense()
{
  if(!block_value_override) {
    block_value = get_distance();
    block_value = block_value + (0.1677 * block_value + 14.741);
  }
}

  