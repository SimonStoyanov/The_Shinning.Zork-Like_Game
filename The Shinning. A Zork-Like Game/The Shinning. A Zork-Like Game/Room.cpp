#include <iostream>
#include <string>
#include <map>

using namespace std;

#include "Room.h"

//Constructor with Name and Description
Room::Room(string _name, string _description)
{
	name = _name;
	description = _description;
}


//Constructor with Name
Room::Room(string _name)
{
	name = _name;
}