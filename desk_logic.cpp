#include "desk_logic.h"

int target_up = 115;
int target_down = 74;
int target = target_up;

bool stopped = true;

int get_target () {
  return target;
}

int convert_to_target_value (int t) {
  if (t > 122)
    return 122;
  else if (t < 60)
    return 60;
  else
    return t;
}

void set_target (int t) {
  target = convert_to_target_value(t);

  bool stopped = false;
}

void set_target_up (int t) {
  target_up = convert_to_target_value(t);
}

void set_target_down (int t) {
  target_down = convert_to_target_value(t);
}

int buffer = 2;
void set_buffer (int b) {
  if (b < 0) {
    buffer = 0;
  } else {
    buffer = b;
  }
}

int getDirection () {
  int height = get_height();
  
  if (stopped)
    return NONE;
    
  if (height - buffer > target)
    return DOWN;
  else if (height + buffer < target)
    return UP;
  else {
    stopped = true;
    return NONE;
  }
}

String get_direction_str () {
  switch (getDirection ()) {
    case UP:
      return String("up");
    case DOWN:
      return String("down");
    case NONE:
      return String("none");
    default:
      return String("unknown");
  }
}

void run_desk() {
  switch (getDirection ()) {
    case UP:
      Serial.println("up");
      break;
    case DOWN:
      Serial.println("down");
      break;
    case NONE:
      Serial.println("none");
      break;
    default:
      Serial.println("unknown");
      break;
  }
}

void reset_desk () {
  
  //moveDown();

  for (int i = 0; i < 120; i++) { //Maximal 60 sec runter fahren
    int h = get_height();

    if (h < 65) { // Tisch ist fast unten
      delay(5000);
      break;
    }
    delay (500);
  }

  //moveUp();
  delay (1000);
  //halt();
  stopped = true;
}
