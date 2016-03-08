#include <iostream>
#include <string>

using namespace std;

#include "Commands.h"

bool Movement_cmd(string command){
	if (command != "east" && command != "e" && command != "northeast" && command != "ne"&& command != "north" && command != "n" && command != "northwest" && command != "nw" &&  command != "west" && command != "w" && command != "southwest" && command != "sw" && command != "south" && command != "s"  && command != "southeast" && command != "se" && command != "up" && command != "u" && command != "down" && command != "d" && command != "in" && command != "i" && command != "out" && command != "o"){
		return true;
	}
	else{
		return false;
	}
}

bool PickItems_cmd(string command){
	if (command != "get" && command != "take" && command != "get all" && command != "take all" && command != "drop" && command != "throw"){
		return true;
	}
	else{
		return false;
	}
}
bool UsingItems_cmd(string command){
	if (command != "read" && command != "turn" && command != "turn on" && command != "turn off" && command != "move" && command != "break" && command != "tie"){
		return true;
	}
	else{
		return false;
	}
}
bool Item_cmd(string command){
	if (PickItems_cmd(command) && UsingItems_cmd(command)){
		return true;
	}
	else{
		return false;
	}
}

bool Combat_cmd(string command){
	if (command != "attack" && command != "kill"){
		return true;
	}
	else{
		return false;
	}
}

bool Misc_cmd(string command){
	if (command != "pray god" && command != "pray god minor clue" && command != "pray god mc" && command != "pray god medium clue" && command != "pray god mdc" && command != "pray god advanced clue" && command != "pray god ac"){
		return true;
	}
	else{
		return false;
	}
}