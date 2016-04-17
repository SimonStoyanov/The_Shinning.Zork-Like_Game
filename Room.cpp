#include "Room.h"
#include "Entity.h"
#include "World.h"

Room::Room(const char* title, const char* description) : Entity(title, description, nullptr){
	type = ROOM;
}

Room::~Room(){}

void Room::Look() const{
	this->Look();
}

Exit* Room::GetExit(p2String& direction){
	for (int i = 0; i < myWorld->entities.size(); i++){
		if (myWorld->entities[i]->getType() == EXIT){
			Exit* aux;
			aux = dynamic_cast<Exit*> (myWorld->entities[i]);
			if (aux->parent == this && aux->getName() == direction){
				return aux;
			}
		}
	}
	return nullptr;
}
