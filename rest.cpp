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

void setValue() {
  for (uint8_t i = 0; i < server.args(); i++) {
    if (server.argName(i) == "target_up") {
      set_target_up(server.arg(i).toInt());
    }
    else if (server.argName(i) == "target_down") {
      set_target_down(server.arg(i).toInt());
    }
    else if (server.argName(i) == "target") {
      set_target(server.arg(i).toInt());
    }
    else if (server.argName(i) == "buffer") {
      int val = server.arg(i).toInt();
      if (val > 0) {
        buffer = val;
        Serial.print("Set buffer to: "); Serial.println(val);
      }
    }
    else if (server.argName(i) == "blur") {
      set_blur(server.arg(i).toInt());
    }
    /*
    else if (server.argName(i) == "stopped") {
      stopped = !stopped;
      Serial.print("Set stopped to: "); Serial.println(stopped);
    }
      if (server.argName(i) == "target_up") {
      target_up = server.arg(i).toInt();
      }
    */
    else {
      server.send(403, "text/plain", "Argument not known");
    }
  }
  server.send(200, "text/plain", getStatusStr());
}

void reset() {
  server.send(200, "text/plain", getStatusStr() + String("\n Resetting... please wait"));
  reset_desk();
}

void init_rest () {
  server.on("/getStatus", getStatus);
  
  server.on("/reset", reset);
  
  server.on("/setValue", setValue);
  server.begin();
}

void run_rest () {
  server.handleClient();
}
