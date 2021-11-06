#include "rest.h"

WebServer server(80);

/***
   Define all general functions
*/

String getStatusStr() {
  return  String("Status Desk:\n") +
          String("Current heigth: ") + String(get_height()) + String("cm\n") +
          String("Measurement quality: ") + String(get_sensor_quality()) + String("\n") +
          String("Target: ") + String(target) + String("cm\n") +
          String("Target up: ") + String(target_up) + String("cm\n") +
          String("Target down: ") + String(target_down) + String("cm\n") +
          String("Target Blur: ") + String(buffer) + String("cm\n") +
          String("Sensor Blur: ") + String(get_blur()) + String("mm\n");
}

/***
   Define all API end points
*/
void getStatus() {
  server.send(200, "text/plain", getStatusStr());
}

void init_rest () {
  server.on("/getStatus", getStatus);
  server.begin();
}

void run_rest () {
  server.handleClient();
}
