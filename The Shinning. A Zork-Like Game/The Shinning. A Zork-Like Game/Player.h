#ifndef Player_h
#define Player_h

#include <iostream>
#include <string>
#include "Room.h"

using namespace std;

class Player{
private:
	string name;
	string description;
	Room *room;
public:
	Player(Room *room);
	
	string getName();
	string getDescription();
	Room *getRoom();

	list<Player*> Players;
};

#endif