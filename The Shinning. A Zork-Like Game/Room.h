#ifndef Room_h
#define Room_h

#include "p2String.h"
#include <iostream>
#include <map>

using namespace std;

class Room{
private:
	p2String name;
	p2String description;
public:
	//Room Construction
	Room(p2String _name, p2String _description);
	Room(p2String _name);

	//Map
	map<p2String, Room*> exits;

	p2String getName();
	p2String getDescription();

	void printRoom();
	void link(Room *room, p2String _direction);
	Room* getLinked(p2String direction);
};

#endif