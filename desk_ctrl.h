#ifndef Desk_Ctrl_h
#define Desk_Ctrl_h

#include "Arduino.h"

#define PIN_UP 18
#define PIN_DOWN 19

void init_desk_ctrl();

void moveUp ();

void moveDown ();

void halt ();

#endif //Desk_Ctrl_h
