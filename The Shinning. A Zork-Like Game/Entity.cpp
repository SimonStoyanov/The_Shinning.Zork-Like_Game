#include "Entity.h"
#include "World.h"

// Constructor
Entity::Entity(const char* name, const char* description, Entity* parent) :
name(name), description(description), parent(parent)
{
	type = ENTITY;

	if (parent != NULL)
		parent->entities.push_back(this);
}
Entity::Entity(const char* name, const char* description) :
name(name), description(description)
{
	type = ENTITY;

	if (parent != NULL)
		parent->entities.push_back(this);
}
// Destructor
Entity::~Entity(){};

// Get Entity Name
p2String Entity::getName(){
	return name;
}
p2String Entity::getFirstWord(){
	return name[0];
}
// Get Entity Description
p2String Entity::getDescription(){
	return description;
}
// Get Entity Type
const EntityType Entity::getType(){
	return type;
}

