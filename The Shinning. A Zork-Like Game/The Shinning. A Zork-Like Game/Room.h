#ifndef Room_h
#define Room_h

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Room{
private:
	string name;
	string description;
public:
	//Room Construction
	Room(string _name, string _description);
	Room(string _name);

	//Map
	map<string, Room*> exits;

	string getName();
	string getDescription();
	
	void printRoom();
	void link(Room *room, string _direction);
	Room* getLinked(string direction);
};

#endif