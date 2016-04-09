#ifndef Commands_h
#define Commands_h

#include "p2String.h"
#include <iostream>

using namespace std;

bool Movement_cmd(p2String command);

bool PickItems_cmd(p2String command);
bool UsingItems_cmd(p2String command);
bool Item_cmd(p2String command);

bool Combat_cmd(p2String command);

bool Misc_cmd(p2String command);

#endif