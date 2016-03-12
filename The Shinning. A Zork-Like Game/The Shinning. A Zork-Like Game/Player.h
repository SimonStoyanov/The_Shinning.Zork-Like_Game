#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Player{
	string name;
	string description;

public:
	Room *currentRoom;
	Player(string _name, string _description, Room *_currentRoom);
	
	string getName();
	string getDescription();
	Room *getRoom();

};

#endif