#ifndef Commands_h
#define Commands_h

#include <string>
#include <iostream>

using namespace std;

bool Movement_cmd(string command);

bool PickItems_cmd(string command);
bool UsingItems_cmd(string command);
bool Item_cmd(string command);

bool Combat_cmd(string command);

bool Misc_cmd(string command);

#endif