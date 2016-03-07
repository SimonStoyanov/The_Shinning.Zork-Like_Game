#include <iostream>
#include <string>

using namespace std;

#include "Commands.h"

bool Movement_cmd(string command){
	if (command != "go" && command != "go east" && command != "go e" && command != "east" && command != "e" && command != "go northeast" && command != "go ne" && command != "northeast" && command != "ne" && command != "go north" && command != "go n" && command != "north" && command != "n" && command != "go northwest" && command != "go we" && command != "northwest" && command != "nw" &&  command != "go west" && command != "go w" && command != "west" && command != "w" &&  command != "go southwest" && command != "go sw" && command != "southwest" && command != "sw" && command != "go south" && command != "go s" && command != "south" && command != "s" && command != "go southeast" && command != "go se" && command != "southeast" && command != "se"){
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