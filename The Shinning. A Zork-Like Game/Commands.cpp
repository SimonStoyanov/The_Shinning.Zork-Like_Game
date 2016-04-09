#include <iostream>
#include "p2String.h"

using namespace std;

#include "Commands.h"
#include "Room.h"

bool Movement_cmd(p2String command){
	if (command != "east" && command != "e" && command != "northeast" && command != "ne"&& command != "north" && command != "n" && command != "northwest" && command != "nw" &&  command != "west" && command != "w" && command != "southwest" && command != "sw" && command != "south" && command != "s"  && command != "southeast" && command != "se" && command != "up" && command != "u" && command != "down" && command != "d" && command != "in" && command != "i" && command != "out" && command != "o"){
		return true;
	}
	else{
		return false;
	}
}

bool PickItems_cmd(p2String command){
	if (command != "get" && command != "take" && command != "get all" && command != "take all" && command != "drop" && command != "throw"){
		return true;
	}
	else{
		return false;
	}
}
bool UsingItems_cmd(p2String command){
	if (command != "read" && command != "turn" && command != "turn on" && command != "turn off" && command != "move" && command != "break" && command != "tie"){
		return true;
	}
	else{
		return false;
	}
}
bool Item_cmd(p2String command){
	if (PickItems_cmd(command) && UsingItems_cmd(command)){
		return true;
	}
	else{
		return false;
	}
}

bool Combat_cmd(p2String command){
	if (command != "attack" && command != "kill"){
		return true;
	}
	else{
		return false;
	}
}

bool Misc_cmd(p2String command){
	if (command != "open door" && command != "close door" && command != "pray"){
		return true;
	}
	else{
		return false;
	}
}