#ifndef Desk_Logic_h
#define Desk_Logic_h

#include "Arduino.h"
#include "distance.h"

extern int target_up;
extern int target_down;
extern int target;
int getTarget ();

extern int buffer; /*blur to avoid the desk going up and down missing the exact height*/

#define UP 1
#define DOWN -1
#define NONE 0

int getDirection ();
String getDirectionStr ();

void run_desk();

#endif //Desk_Logic_h
