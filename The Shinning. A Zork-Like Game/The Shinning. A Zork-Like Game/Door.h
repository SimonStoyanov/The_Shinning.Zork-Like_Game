#ifndef Door_h
#define Door_h

#include <string>
#include <iostream>
#include "Room.h"

using namespace std;

class Door : public Room{
private:
	bool door; //True -> Closed //False -> closed
public:

	//Set doors
	

	//Get True||False
	bool getDoor(){
		return door;
	}

};


#endif