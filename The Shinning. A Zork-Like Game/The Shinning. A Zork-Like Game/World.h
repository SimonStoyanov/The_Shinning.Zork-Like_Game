#ifndef World_h
#define World_h

#include <string>
#include "Player.h"
#include "Room.h"
#include "Map.h"

class World{
public:
	void Create_World(World *TheShinning);
	void Game_Loop(World *TheShinning);
	void Clean_World(World *TheShinning);

	World();
	World(Player* player, Map* map);

	Map *Nir; //Name of the country
	Player *Aisu; //Name of the player
};

#endif