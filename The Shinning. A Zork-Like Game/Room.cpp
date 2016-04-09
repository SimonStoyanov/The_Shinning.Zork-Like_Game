#include <iostream>
#include "p2String.h"
#include <map>
#include "Room.h"

//Room Construction
Room::Room(p2String _name, p2String _description) : name(_name), description(_description){}

Room::Room(p2String _name) : name(_name){}

//Get Room Name
p2String Room::getName(){
	return name;
}

//Get Room Description
p2String Room::getDescription(){
	return description;
}

//Print Room
void Room::printRoom(){
	printf("--%s--\n", getName());
	printf("%s", getDescription());
}

//Link Function
void Room::link(Room *room, p2String _direction){
	exits[_direction] = room;
}

//Get linked room
Room* Room::getLinked(p2String direction){
	map<p2String, Room*> ::iterator it;

	it = exits.find(direction);

	if (it != exits.end()){
		return it->second;
	}
	else{
		return NULL;
	}
}