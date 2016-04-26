#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Room;
class Item;

class Creature : public Entity{
protected:
	Room* currentRoom;
	Item* inventory;
	Item* equiped;
	struct Stats{
		uint attack;
		uint hp;
		uint armor;
		p2String intelligence;
	} Stats;
public:
	Creature(const char* name, const char* description, Room* parent, Item* inventory);
	~Creature(){}

	Room* getcurrentRoom(){ return currentRoom; }

	virtual void Look(p2Vector<p2String>& commands) const{}
	virtual void Go(p2Vector<p2String>& commands){}
	virtual void ChangeDoor(p2Vector<p2String>& commands){}
	virtual void Pick(p2Vector<p2String>& commands){}
	virtual void Drop(p2Vector<p2String>& commands){}
	virtual void Equip(p2Vector<p2String>& commands){}
	virtual void Unequip(){}
	virtual void PrintStats(){}
};

#endif