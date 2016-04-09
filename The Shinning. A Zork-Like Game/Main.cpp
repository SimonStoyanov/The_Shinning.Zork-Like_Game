#include <iostream>
#include "World.h"
#include "MemLeaks.h"

int main(){

	ReportMemoryLeaks();

	World *TheShinning = new World();

	Create_World(TheShinning);
	Game_Loop(TheShinning);
	Clean_Game();

	return 0;
}