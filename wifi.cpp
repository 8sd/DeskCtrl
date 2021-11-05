#include "wifi.h"

uint8_t init_wifi () {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PSW);

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n  Connected to ");
  Serial.println(WIFI_SSID);
  Serial.print("  IP address: ");
  Serial.println(WiFi.localIP());
  return 0;
}
