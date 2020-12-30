
#include "cubelet.h"

void setup() {

}

void loop() {
   sense();
}

void sense()
{
    int dist = get_distance();
    int adjusted = dist + (0.1677 * dist + 14.741);
    int constrained = adjusted > 255 ? 255 : adjusted;
    constrained = constrained < 15 ? 0 : constrained;
    block_value = constrained;
}

  