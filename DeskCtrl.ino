#include "desk_logic.h"
#include "distance.h"
#include "OTA.h"
#include "rest.h"
#include "wifi.h"

void run_serial () {
  Serial.print("Distance: "); Serial.print(get_height()); Serial.print("cm; Direction: "); Serial.print(get_direction_str()); Serial.print("; Target: "); Serial.print(get_target()); Serial.print("cm; Qualtiy: "); Serial.println(get_sensor_quality());
}

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

  Serial.println(" Initializing OTA");
  init_ota();
  Serial.println(" OTA initialized");

  Serial.println(" Initializing rest");
  init_rest();
  Serial.println(" rest initialized");
  /*TODO: Multi Threading*/

  Serial.println("Booted!");
}

void loop() {
  run_desk();
  run_serial();
  run_ota();
  run_rest();
  delay(100);
}
