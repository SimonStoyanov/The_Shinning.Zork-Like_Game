#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Room.h"
#include "Item.h"

class Player : public Entity{
private:
	Room* currentRoom;
	Item* inventory;
	Item* equiped;
public:
	Player(const char* name, const char* description, Room* parent, Item* inventory);
	~Player();

	Room* getcurrentRoom(){ return currentRoom; }

	void Look(p2Vector<p2String>& commands) const; 
	void Go(p2Vector<p2String>& commands);
	void ChangeDoor(p2Vector<p2String>& commands);
	void Pick(p2Vector<p2String>& commands);
	void Drop(p2Vector<p2String>& commands);
	void Equip(p2Vector<p2String>& commands);
	void Unequip();
};

#endif