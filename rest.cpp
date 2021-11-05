#include "rest.h"

WebServer server(80);

/***
 * Define all general functions 
 */

String getStatusStr() {
  return  String("Status Desk:\n") +
          String("Current heigth: ") + String(getHeight()) + String("cm\n") +
          String("Measurement quality: ") + String(getSensorQuality()) + String("\n");
}

/***
 * Define all API end points
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
