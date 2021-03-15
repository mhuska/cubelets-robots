#include "cubelet.h"
#include <stdbool.h>

uint8_t mathRandomVal(uint8_t min, uint8_t max);




uint8_t prn;
uint8_t mathRandomVal(uint8_t min, uint8_t max) {
   uint8_t feedback_bit= ((prn >> 0) ^ (prn >> 2) ^ (prn >> 3) ^ (prn >> 4)) & 1;
   prn = (prn >> 1) | (feedback_bit << 7);
  return min + prn % (max - min +1);
}


int loops;
int waitloop;
int phase; //1 = straight, 2 = back up, 3 = turn, 4 = random
int speed1;
int speed2;

void decide(void){

    block_value = get_sensor_value();

    loops += 1;

    //Only do something when we've reached our "wait" amount
    if (loops >= waitloop || block_value > 50) {
        //If sensor is reading something, start backup sequence
        if (block_value > 50) {
            phase = 2;
            waitloop =  2;
            loops =  0;
            speed1 = 50;
            speed2 = 50;
        }
        //If going backward, make a turn - wheels opposite
        else if (phase == 2) {
            phase = 3;
            waitloop =  2;
            loops = 0;
            speed1 = 200;
            speed2 = 50;
        }
        //If turning or doing something random, go straight forward
        else if (phase == 3 || phase == 4) {
            phase = 1;
            waitloop =  6;
            loops =  0;
            speed1 = 200;
            speed2 = 200;
        }
        //If going straight, do something random
        else if (phase == 1) {
            phase = 4;
            waitloop =  4;
            loops =  0;
            speed1 = mathRandomVal(0, 255);;
            speed2 = mathRandomVal(0, 255);;
         }
        
    }

    set_block_value(1631361, speed1);
    set_block_value(1634463, speed2);
}

void setup() {

    prn = (MyID0 == 0) ? 1 : MyID0;  //used for random function

    loops = 0;
    waitloop =  4;
    phase = 4;
    speed1 = 0;
    speed2 = 0;

    set_interval(500, decide);

}

void loop() {
}