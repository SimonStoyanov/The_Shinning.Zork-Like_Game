#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"


class Item :public Entity{
private:
	Entity* container;
	bool canContain;
	bool pickable;

public:

	// Constructor and Destructor
	Item(const char* name, const char* description, bool contain = true, bool use = false, Entity* the_container = nullptr);
	~Item();

	// Methods
	void SetContainer(Entity* new_container);
	Entity* GetContainer();
	bool GetPickable()const;
	bool GetCanContain()const;


};

#endif