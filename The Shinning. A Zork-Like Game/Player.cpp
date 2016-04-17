#include "Player.h"
#include "Entity.h"
#include "World.h"
#include "Exit.h"

Player::Player(const char* name, const char* description, Room* parent) : Entity(name, description, parent),
	currentRoom(parent)
	{
		type = PLAYER;
	}

Player::~Player(){}

void Player::Look(p2Vector<p2String>& commands) const{
	printf("----%s----", parent->getName());
	printf("\n%s\n", parent->getDescription());
}

void Player::Go(p2Vector<p2String>& commands){
	if (commands.size() > (uint)1){
		Exit* aux = currentRoom->GetExit(commands[1]);
		if (aux != nullptr && aux->getName() == commands[1]){
			if (!aux->get_Close()){
				parent = aux->get_Destination();
				currentRoom = aux->get_Destination();
			}
			else {
				printf("Door is closed\n");
			}
		}
		else printf("There is no room in direction %s.\n", commands[1].c_str());
	}
	else {
		Exit* aux = currentRoom->GetExit(commands[0]);
		if (aux != nullptr && aux->getName() == commands[0]){
			if (!aux->get_Close()){
				parent = aux->get_Destination();
				currentRoom = aux->get_Destination();
			}
			else {
				printf("Door is closed\n");
			}
		}
		else printf("There is no room in direction %s.\n", commands[0].c_str());
	}
}

void Player::ChangeDoor(p2Vector<p2String>& commands){
	Exit* departure;
	Exit* ret = nullptr;

	departure = currentRoom->GetExit(commands[1]);
	if (departure != nullptr){
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getType() == EXIT){
				ret = dynamic_cast<Exit*>(myWorld->entities[i]);
				if (ret->get_Origin() == departure->get_Destination() && ret->get_Destination() == departure->get_Origin()) break;
				else ret = nullptr;
			}
		}
		if (ret != nullptr){
			if (commands[0] == "close"){
				if (departure->get_Close()){
					departure->CloseDoor();
					ret->CloseDoor();
					printf("The door is closed now.\n");
				}
			}
			else if (commands[0] == "open"){
				departure->OpenDoor();
				ret->OpenDoor();
				printf("The door is open now.\n");
			}
		}
	}
	else printf("I cant find a door in %s direction.\n", commands[1]);

}
