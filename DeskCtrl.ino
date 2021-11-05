#include "distance.h"

void setup() {
  Serial.begin(115200);
  delay (100);
  Serial.println();
  Serial.println();
  Serial.flush();
  Serial.println("Booting...");
  Serial.println(" Initializing distance sensor");
  switch (init_distance()) {
    case 0:
      break;
    default:
      Serial.println(" Error initializing distance sensor");
      while (1){}
  }
  Serial.println(" Distance sensor initialized");
  Serial.println("Booted!");
}

void loop() {
  Serial.print("Distance: ");Serial.print(getHeight());Serial.print("cm; Qualtiy: ");Serial.println(getSensorQuality());
  delay(1000);
}
