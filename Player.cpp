#include "Player.h"
#include "Entity.h"
#include "World.h"
#include "Exit.h"

Player::Player(const char* name, const char* description, Room* parent, Item* inventory) : Creature(name, description, parent, inventory),
	currentRoom(parent)
	{
		type = PLAYER;
	}

Player::~Player(){}

void Player::Look(p2Vector<p2String>& commands) const{
	Item* aux;
	Item* aux2;
	int j = 0;
	switch (commands.size()){
	case 1:{
		printf("\n----%s----", parent->getName());
		printf("\n%s\n", parent->getDescription());
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getType() == ITEM){
				aux = dynamic_cast<Item*> (myWorld->entities[i]);
				if (aux->GetContainer() == currentRoom){
					if (j == 0){
						printf("These are the objects I can see: ");
						j++;
					}
					printf("\n\t- %s ", aux->getName());
				}
			}
		}
	}
		   break;
	case 2:{
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getType() == ITEM && myWorld->entities[i]->getName() == commands[1]){
				aux = dynamic_cast<Item*> (myWorld->entities[i]);
				if (aux->GetContainer() == currentRoom || aux->GetContainer() == inventory || aux == inventory){
					printf("%s\n", aux->getDescription());
					if (aux->GetCanContain()){
						printf("The %s contains: ", aux->getName());
						for (int i = 0; i < myWorld->entities.size(); i++){
							if (myWorld->entities[i]->getType() == ITEM){
								aux2 = dynamic_cast<Item*> (myWorld->entities[i]);
								if (aux2->GetContainer() == aux)printf("%s ", aux2->getName());
							}
						}
					}
				}
			}
		}
	}
		   break;
	}

	printf("\n");
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

void Player::Pick(p2Vector<p2String>& commands){
	Item* aux;
	bool picked = false;
	switch (commands.size()){
	case 2:{
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getType() == ITEM){
				aux = dynamic_cast<Item*> (myWorld->entities[i]);
				if (aux->GetContainer() == currentRoom && aux->getName() == commands[1]){
					if (aux->GetPickable()){
						aux->SetContainer(inventory);
						picked = true;
						break;
					}
					else{
						printf("The %s can not be picked.\n", aux->getName());
						return;
					}
				}
			}
		}
	}
		   break;
	case 4:{
		Item* container;
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getName() == commands[3] && myWorld->entities[i]->getType() == ITEM) {
				container = dynamic_cast<Item*>(myWorld->entities[i]);
				if (container->GetContainer() != currentRoom && container->GetContainer() != inventory)
					printf("The %s is not in this room.", container->getName());
				else{
					aux = container->Posess(commands[1]);
					if (aux != nullptr){
						aux->SetContainer(inventory);
						picked = true;
						break;
					}
					else {
						printf("The %s doesn't contain %s.\n", container->getName(), commands[1].c_str());
						return;
					}
				}
			}
		}
	}
		   break;
	default:{
		printf("I don't understand that.\n");
		return;
	}
			break;
	}
	if (picked) printf("The %s is now in your %s.\n", commands[1].c_str(), inventory->getName());
	else printf("The item %s is not there or can not be picked.\n", commands[1].c_str());
}
 
void Player::Drop(p2Vector<p2String>& commands){
	Item* temp;
	bool picked = true;
	if (commands.size() == (uint)2){
		for (int i = 0; i < myWorld->entities.size(); i++){
			if (myWorld->entities[i]->getType() == ITEM){
				temp = dynamic_cast<Item*> (myWorld->entities[i]);
				if (temp->GetContainer() == inventory && temp->getName() == commands[1] && temp->GetPickable()){
					temp->SetContainer(currentRoom);
					picked = false;
					break;
				}
			}
		}
	}
	if (!picked) printf("I've droped the %s.\n", commands[1].c_str());
	else printf("I cannot drop something that I don't have.\n");
}

void Player::Equip(p2Vector<p2String>& commands){
	Item* temp;
	if ((temp = inventory->Posess(commands[1])) != nullptr){
		if (equiped == nullptr)printf("I've equiped the %s.\n", temp->getName());
		else printf("I've swaped %s for %s.\n", equiped->getName(), temp->getName());
		equiped = temp;
		if (equiped->getName() == "book"){
			Stats.intelligence = "Still Average";
		}
		else if (equiped->getName() == "knife"){
			Stats.attack += 4;
		}
		else if (equiped->getName() == "shield"){
			Stats.armor += 5;
		}
	}
	else printf("I cannot equip something I don't have...");
}

void Player::Unequip(){
	if (equiped != nullptr){
		printf("I've unequiped %s.\n", equiped->getName());
		if (equiped->getName() == "book"){
			Stats.intelligence = "Average";
		}
		else if (equiped->getName() == "knife"){
			Stats.attack -= 4;
		}
		else if (equiped->getName() == "shield"){
			Stats.armor -= 5;
		}
		equiped = nullptr;
	}
	else printf("I cannot unequip something I don't have eqiped yet..\n");
}

void Player::PrintStats(){
	printf("\thealth:    %d", Stats.hp);			printf("\tarmor:   %d", Stats.armor);
	printf("\n\tattack:    %d", Stats.attack);		printf("\tintelligence:  %s", Stats.intelligence);

	printf("\n");
}