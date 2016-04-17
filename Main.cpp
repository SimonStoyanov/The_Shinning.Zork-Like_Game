#include <iostream>
#include "World.h"
#include "Entity.h"

World* myWorld = nullptr;

int main(){

	myWorld = new World;
	myWorld->Game_Loop();

	system("pause");
	return 0;
}