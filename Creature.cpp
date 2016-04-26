#include "Creature.h"

Creature::Creature(const char* name, const char* description, Room* parent, Item* inventory) : Entity(name, description, parent),
	currentRoom(currentRoom),
	inventory(inventory){}

