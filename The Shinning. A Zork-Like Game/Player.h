#ifndef Player_h
#define Player_h

#include <iostream>
#include "p2String.h"
#include "Room.h"

using namespace std;

class Player{
	p2String name;
	p2String description;

public:
	Room *currentRoom;
	Player(p2String _name, p2String _description, Room *_currentRoom);

	p2String getName();
	p2String getDescription();
	Room *getRoom();

};

#endif