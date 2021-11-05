#include "distance.h"
#include "wifi.h"

void reboot() {
  Serial.println("Rebooting...");
  delay(5000);
  ESP.restart();
}

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
      reboot();
  }
  Serial.println(" Distance sensor initialized");

  Serial.print(" Connecting Wifi...");
  switch (init_wifi ()) {
    case 0:
      break;
    default:
      Serial.println(" Error initializing wifi");
      reboot();
  }
  Serial.println(" Wifi connected!");
  Serial.println("Booted!");
}

void loop() {
  Serial.print("Distance: "); Serial.print(getHeight()); Serial.print("cm; Qualtiy: "); Serial.println(getSensorQuality());
  delay(1000);
}
