#ifndef Desk_Logic_h
#define Desk_Logic_h

#include "Arduino.h"
#include "distance.h"

extern int target_up;
extern int target_down;
extern int target;
int get_target ();
void set_target (int t);
void set_target_up (int t);
void set_target_down (int t);

extern int buffer; /*blur to avoid the desk going up and down missing the exact height*/
void set_buffer (int b);

#define UP 1
#define DOWN -1
#define NONE 0

int getDirection ();
String get_direction_str ();

void run_desk();
void reset_desk();

#endif //Desk_Logic_h
