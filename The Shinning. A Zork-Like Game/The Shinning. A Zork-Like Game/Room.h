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
	Room(string, string);
	Room(string);

	//Get Room Name
	string getName(){
		return name;
	}

	//Get Room Description
	string getDescription(){
		return description;
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
	void link(Room *room, string direction)
	{
		exits[direction] = room;
	}

	//Print Linked Rooms
	void printLiked()
	{
		map<string, Room*> ::iterator it;

		cout << endl;

		for (it = exits.begin(); it != exits.end(); ++it)
		{
			cout << "Exit: ";
			cout << it->first << " (" << it->second->getName() << ")" << endl;

		}

		cout << endl;
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