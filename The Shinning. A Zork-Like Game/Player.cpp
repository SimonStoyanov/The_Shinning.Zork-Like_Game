#include <iostream>
#include "p2String.h"
#include "Player.h"

Player::Player(p2String _name, p2String _description, Room *_currentRoom) : name(_name), description(_description), currentRoom(_currentRoom){}

p2String Player::getName(){
	return Player::name;
}

p2String Player::getDescription(){
	return Player::description;
}

Room *Player::getRoom(){
	return Player::currentRoom;
}