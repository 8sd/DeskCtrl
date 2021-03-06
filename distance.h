#ifndef Distance_h
#define Distance_h

#include "Arduino.h"
#include <Wire.h>
#include <VL53L0X.h>

extern VL53L0X sensor;

uint8_t init_distance ();
uint8_t init_distance (bool long_range, bool high_speed, bool high_accuracy, uint8_t blur);

int get_height();
float get_sensor_quality();
uint8_t get_blur();
void set_blur(uint8_t b);

#endif //Distance_h
