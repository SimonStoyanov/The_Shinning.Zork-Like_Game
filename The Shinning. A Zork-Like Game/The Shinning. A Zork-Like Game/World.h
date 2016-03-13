#ifndef World_h
#define World_h

#include "Player.h"
#include "Map.h"


class Map;

class World{
public:
	World();
	World(Player* player, Map* map);

	Map *Nir; //Name of the country
	Player *Aisu; //Name of the player
	World *TheShinning;

	void Clean_Map(){
		delete Nir;
	}
	void Clean_Player(){
		delete Aisu;
	}
	void Clean_World(){
		delete TheShinning;
	}
	
};

void Create_World(World *TheShinning);
void Game_Loop(World *TheShinning);
void Clean_Game();


#endif