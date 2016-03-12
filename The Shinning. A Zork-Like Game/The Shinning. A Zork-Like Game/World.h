#ifndef World_h
#define World_h

#include "Player.h"
#include "Map.h"

class World{
public:
	World();
	World(Player* player, Map* map);

	Map *Nir; //Name of the country
	Player *Aisu; //Name of the player
};

void Create_World(World *TheShinning);
void Game_Loop(World *TheShinning);
void Clean_World(World *TheShinning);


#endif