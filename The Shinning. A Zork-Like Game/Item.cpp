#include "Item.h"

Item::Item(const char* name, const char* description, bool contain, bool use, Entity* container) :
	Entity(name, description),
	canContain(contain),
	pickable(use),
	container(container)
	{
		type = ITEM;
	}

Item::~Item(){}

//Methods
void Item::SetContainer(Entity* new_container){ 
	container = new_container; 
}
Entity* Item::GetContainer(){ 
	return container; }
bool Item::GetPickable()const{ return pickable;
}
bool Item::GetCanContain()const{ 
	return canContain; 
}
