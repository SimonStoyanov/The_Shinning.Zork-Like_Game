#ifndef WORLD_H
#define WORLD_H

#include "p2String.h"
#include "p2Vector.h"

#include "Entity.h"
#include "Player.h"

class Entity;
class Player;

class World : public Entity{
private:
	Player* player;
public:
	p2Vector<Entity*> entities;
	World();
	~World();

	void Game_Loop();

	bool Command(p2Vector<p2String>& commands);

};


#endif