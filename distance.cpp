#include "Arduino.h"
#include "distance.h"

VL53L0X sensor;
uint8_t _blur;
uint16_t old_height;

uint8_t init_distance () {
  return init_distance(/*long_range*/ true, /*high_speed*/ false, /*high_accuracy*/ true, 15);
}

uint8_t init_distance (bool long_range, bool high_speed, bool high_accuracy, uint8_t blur) {
  _blur = blur;
  
  if (high_speed && high_accuracy)
    return 2; /* invalid parameter combination */

  Wire.begin();

  sensor.setTimeout(500);
  if (!sensor.init())
  {
    Serial.println("Failed to detect and initialize sensor!");
    return 1; // sensor not found
  }

  if (long_range) {
    // lower the return signal rate limit (default is 0.25 MCPS)
    sensor.setSignalRateLimit(0.1);
    // increase laser pulse periods (defaults are 14 and 10 PCLKs)
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  }

  if (high_speed) {
    // reduce timing budget to 20 ms (default is about 33 ms)
    sensor.setMeasurementTimingBudget(20000);
  } else if (high_accuracy) {
    // increase timing budget to 200 ms
    sensor.setMeasurementTimingBudget(200000);
  }
  return 0;
}

int getHeight() {
  int measured_height = sensor.readRangeSingleMillimeters();

  if (sensor.timeoutOccurred() || measured_height > 8190) { // here an invalid value should be returned
    measured_height = old_height;
    Serial.print(" invalid measurement");
  }
  
  if (abs(measured_height - old_height) < _blur) {
    measured_height = old_height;
  }

  return (int) measured_height / 10;
}
