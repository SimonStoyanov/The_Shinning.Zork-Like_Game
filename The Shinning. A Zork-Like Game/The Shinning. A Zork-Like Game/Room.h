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
	bool door;	//true -> closed		false -> opened
public:
	//Room Construction
	Room(string _name, string _description) : name(_name), description(_description){}
	Room(string _name) : name(_name){}
	//Get Room Name
	string getName(){
		return name;
	}

	//Get Room Description
	string getDescription(){
		return description;
	}

	//Get True/False
	bool getDoor(){
		return door;
	}

	//Print Room
	void Room::printRoom()
	{
		cout << "--" << getName() << "--" << endl;
		cout << getDescription() << endl;
	}

	//Map
	map<string, Room*> exits;

	//Link Function
	void link(Room *room, string direction, bool door)
	{
		exits[direction] = room;
		Room::door = door;
	}

	//Get linked room
	Room* getLinked(string direction)
	{
		map<string, Room*> ::iterator it;

		it = exits.find(direction);

		if (it != exits.end())
		{
			return it->second;
		}
		else
		{
			return NULL;
		}
	}


};



#endif