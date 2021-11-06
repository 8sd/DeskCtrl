#include "desk_ctrl.h"

/*
  Serial.println(" Configuring Pins...");
  Serial.println(" Pins configured!");
*/
void init_desk_ctrl() {
  pinMode(PIN_UP, OUTPUT);
  digitalWrite(PIN_UP, HIGH);
  pinMode(PIN_DOWN, OUTPUT);
  digitalWrite(PIN_DOWN, HIGH);
}

void moveUp () {
  digitalWrite(PIN_UP, LOW);
  digitalWrite(PIN_DOWN, HIGH);
}

void moveDown () {
  digitalWrite(PIN_UP, HIGH);
  digitalWrite(PIN_DOWN, LOW);
}

void halt () {
  digitalWrite(PIN_UP, HIGH);
  digitalWrite(PIN_DOWN, HIGH);
}
