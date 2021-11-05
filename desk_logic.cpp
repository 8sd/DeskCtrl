#include "desk_logic.h"

int target_up = 115;
int target_down = 74;
int target = target_up;

int getTarget () {
  return target;
}

int buffer = 2;

int getDirection () {
  int height = getHeight();
  if (height - buffer > target)
    return DOWN;
  else if (height + buffer < target)
    return UP;
  else
    return NONE;
}

String getDirectionStr () {
  switch(getDirection ()) {
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
  switch(getDirection ()) {
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
