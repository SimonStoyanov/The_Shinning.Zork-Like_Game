#include "Item.h"
#include "World.h"

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
	return container; 
}
bool Item::GetPickable()const{ return pickable;
}
bool Item::GetCanContain()const{ 
	return canContain; 
}
Item* Item::Posess(p2String& item){
	Item* temp;
	for (int i = 0; i < myWorld->entities.size(); i++){
		if (myWorld->entities[i]->getType() == ITEM){
			temp = dynamic_cast<Item*> (myWorld->entities[i]);
			if (temp->GetContainer() == this && temp->getName() == item){
				return temp;
			}
		}
	}
	return nullptr;
}