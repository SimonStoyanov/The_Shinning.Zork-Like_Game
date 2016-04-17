#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"

class Room;

class Exit : public Entity{
private:
	bool closed;
	bool locked;
	Room* origin;
	Room* destination;
	Entity* key;
public:
	// Constructor and Destructor
	Exit(const char* name, const char* description, Room* origin, Room* destination, bool closed = false);
	~Exit();
	// Methods
	bool get_Close(){ return closed; }
	bool get_Locked(){ return locked; }
	Room* get_Destination(){ return destination; }
	Room* get_Origin(){ return origin; }
	Entity* get_Key(){ return key; }

	void CloseDoor(){ closed = true; }
	void OpenDoor(){ closed = false; }
};


#endif