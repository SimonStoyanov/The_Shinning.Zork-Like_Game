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
	bool door;	//True -> Open //False -> Close
	bool is_connected;
public:
	//Room Construction
	Room(string _name, string _description);
	Room(string _name);

	//Map
	map<string, Room*> exits;

	string getName();
	string getDescription();
	bool getIs_Connected();
	bool getDoor();
	
	void printRoom();
	void link(Room *room, string _direction, bool is_connected, bool _door);
	Room* getLinked(string direction);

	bool Is_Connected(Room* current_room);
	bool Is_Closed(Room* current_room);
};

#endif