#include <iostream>
#include "World.h"

int main(){

	World *TheShinning = new World();
	
	TheShinning->Create_World(TheShinning);
	TheShinning->Game_Loop(TheShinning);
	TheShinning->Clean_World(TheShinning);

	return 0;
}