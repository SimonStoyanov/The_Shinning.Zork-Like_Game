#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
#include "Exit.h"

class Room : public Entity{
public:
	Room(const char* name, const char* description);
	~Room();

	void Look() const;
	Exit* GetExit(p2String& direction);
};

#endif