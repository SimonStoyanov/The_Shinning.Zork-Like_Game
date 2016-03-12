#ifndef World_h
#define World_h

#include <string>
#include "Player.h"
#include "Room.h"

class World{
public:
	World();
	~World();

	void Game_Loop();
	list<Room*> Rooms;
	list<Player*> Players;

};

#endif