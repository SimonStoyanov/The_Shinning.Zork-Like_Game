#include <iostream>
#include <string>
#include <map>
#include "Room.h"

//Room Construction
Room::Room(string _name, string _description) : name(_name), description(_description){}

Room::Room(string _name) : name(_name){}

//Get Room Name
string Room::getName(){
	return name;
}

//Get Room Description
string Room::getDescription(){
	return description;
}

//Print Room
void Room::printRoom(){
	cout << "--" << getName() << "--" << endl;
	cout << getDescription() << endl;
}

//Link Function
void Room::link(Room *room, string _direction){
	exits[_direction] = room;
}

//Get linked room
Room* Room::getLinked(string direction){
	map<string, Room*> ::iterator it;

	it = exits.find(direction);
	
	if (it != exits.end()){
		return it->second;
	}
	else{
		return NULL;
	}
}