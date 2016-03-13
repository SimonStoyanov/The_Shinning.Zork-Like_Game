#include <iostream>
#include <string>
#include "Player.h"

Player::Player(string _name, string _description, Room *_currentRoom) : name(_name), description(_description), currentRoom(_currentRoom){}

string Player::getName(){
	return Player::name;
}

string Player::getDescription(){
	return Player::description;
}

Room *Player::getRoom(){
	return Player::currentRoom;
}