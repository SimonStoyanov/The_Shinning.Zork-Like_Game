#include <iostream>
#include <string>
#include "Player.h"

Player::Player(Room *_room) : room(_room){}

string Player::getName(){
	return Player::name;
}

string Player::getDescription(){
	return Player::description;
}

Room *Player::getRoom(){
	return Player::room;
}