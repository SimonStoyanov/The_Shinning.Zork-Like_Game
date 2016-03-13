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

//Get connection
bool Room::getIs_Connected(){
	return is_connected;
}

//Get Door
bool Room::getDoor(){
	return door;
}

//Print Room
void Room::printRoom(){
	cout << "--" << getName() << "--" << endl;
	cout << getDescription() << endl;
}

//Link Function
void Room::link(Room *room, string _direction, bool _is_connected, bool _door){
	exits[_direction] = room;
	is_connected = _is_connected;
	door = _door;
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

//Bools
bool Room::Is_Connected(Room* current_room){
	return current_room->getIs_Connected();
}
bool Room::Is_Closed(Room* current_room){
	return current_room->getDoor();
}