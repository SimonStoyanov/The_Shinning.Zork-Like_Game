#include <iostream>
#include <string>
#include <conio.h>
#include <map>
#include <windows.h> 

#include "Room.h"
#include "Commands.h"
#include "World.h"
#include "Player.h"
#include "Map.h"

using namespace std;

World::World(){
	Aisu = NULL;
	Nir = NULL;
}

World::World(Player* player, Map* map) : Aisu(player), Nir(map){}

void Create_World(World *TheShinning){
	
	TheShinning->Nir = new Map;
	
	//Room Construction
	TheShinning->Nir->set_YourRoom(new Room("Your Room","You are at your Room. There is a book with some inscription that says\n<Game instructions>,maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living Room."));
	TheShinning->Nir->set_LivingRoom(new Room("Living Room","You can see a newspaper next to the chair. You left an apple at the\ntop of your table,it is from yesterday. Next to it there is a knife. \nThe exit is to the north"));
	TheShinning->Nir->set_Galia(new Room("Galia","An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle."));
	TheShinning->Nir->set_Mountains1(new Room("Mountains","You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains."));
	TheShinning->Nir->set_Mountains2(new Room("Mountains","You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path."));
	TheShinning->Nir->set_Mountains3(new Room("Mountains","You are surrounded by mountains. At the northwest there is a path to Galia."));
	TheShinning->Nir->set_ValSar_e(new Room("Val'Sar: Entrance","You are at the entrance to the caves of Val'sar. The view is incredible,\nlooking to the distant north you can see a giant meadow,and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave,leaving a scroll and a lamp."));
	TheShinning->Nir->set_ValSar_c(new Room("Val'Sar Caves","The cave is narrow and wet. You can see a distant light in front of \nyou,it is probably the only way out. The entrance is behind you."));
	TheShinning->Nir->set_TheGreatSea(new Room("The Great Sea","You can see how large is the southern sea of Nir."));
	TheShinning->Nir->set_Meadow1(new Room("Meadow","You are in a huge meadow that goes in all directions. You can see a lake to the north and a tall tower. "));
	TheShinning->Nir->set_Meadow2(new Room("Meadow","You are surrounded by mountains,the only way out is the way you came \nfrom. A graveyard is placed in the center of the field"));
	TheShinning->Nir->set_Meadow3(new Room("Meadow","You are looking to the north. The tower is even taller from where are \nyou at. To the west there is a small field surrounded by mountains."));
	TheShinning->Nir->set_Lake(new Room("Lake","You can almost see the tower in front of you. There is a path to the \nnortheast that leads to somewhere. To the south you can see how small \nis the metropolis in comparison with the world"));
	TheShinning->Nir->set_Bay(new Room("Bay","A giant rock is blocking the way to the eastern part of the tower,\nyou could go down the rock,but it does not seems to be climbable"));
	TheShinning->Nir->set_BigRock_d(new Room("Big Rock","It doesn't seem to be climbable but you could climb it down"));
	TheShinning->Nir->set_BigRock_u(new Room("Big Rock","It doesn't seem to be climbable but you could climb it down"));
	TheShinning->Nir->set_STower(new Room("South of the tower","Next to you there is an immense door. You cannot probably open it. \nTo the east it seems to be an opened window. To the west there is \na cottage,maybe there were people living inside"));
	TheShinning->Nir->set_ETower(new Room("East of the tower","Next to you there is a wide window where you culd probably fit in. To \nthe north you can see an entrance to an ominous cave"));
	TheShinning->Nir->set_WTower(new Room("West of the tower","Next to you there is a cottage,the doors are broken and you can see \nthe only Room that survived time. It is all dust"));
	TheShinning->Nir->set_NTower(new Room("North of the tower","To the north the only thing you see is an ominous entrance to a cave \nknown by the inhabitants as The Underground"));
	TheShinning->Nir->set_TheUnderground(new Room("The Underground: Entrance","You fell like this is the end of your adventure... There is a door \nthat you could open if you use all of your strenght..."));
	TheShinning->Nir->set_Maze1(new Room("Maze","You are surrounded by walls and you don't know where the way out is"));
	TheShinning->Nir->set_Maze2(new Room("Maze","You are surrounded by walls and you don't know where the way out is"));
	TheShinning->Nir->set_Maze3(new Room("Maze","You are surrounded by walls and you don't know where the way out is"));
	TheShinning->Nir->set_End(new Room("Thank you for playing The Shinning","Game made by Simon Stoyanov Beltran for college.\nBased on the game Zork.\n\t\thttps://github.com/SimonStoyanov"));

	//Link Directions
		//Your Room
		TheShinning->Nir->YourRoom->link(TheShinning->Nir->LivingRoom, "down", true, true);
		TheShinning->Nir->YourRoom->link(TheShinning->Nir->LivingRoom, "d", true, true);
		//Living Room
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->YourRoom, "up", true, true);		
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->Galia, "out", true, false);		
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->Galia, "north", true, false);
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->YourRoom, "u", true, true);		
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->Galia, "o", true, false);
		TheShinning->Nir->LivingRoom->link(TheShinning->Nir->Galia, "n", true, false);
		//Galia
		TheShinning->Nir->Galia->link(TheShinning->Nir->LivingRoom, "in", true, false);
		TheShinning->Nir->Galia->link(TheShinning->Nir->Mountains1, "south", true, true);	
		TheShinning->Nir->Galia->link(TheShinning->Nir->Meadow1, "east", true, true);
		TheShinning->Nir->Galia->link(TheShinning->Nir->LivingRoom, "i", true, false);
		TheShinning->Nir->Galia->link(TheShinning->Nir->Mountains1, "s", true, true);	
		TheShinning->Nir->Galia->link(TheShinning->Nir->Meadow1, "e", true, true);
		//Mountains 1
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Galia, "north", true, true);	
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Mountains2, "west", true, true);	
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Mountains3, "east", true, true);	
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->ValSar_entrance, "south", true, true);
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Galia, "n", true, true);		
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Mountains2, "w", true, true);		
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->Mountains3, "e", true, true);		
		TheShinning->Nir->Mountains1->link(TheShinning->Nir->ValSar_entrance, "s", true, true);
		//Mountains 2
		TheShinning->Nir->Mountains2->link(TheShinning->Nir->Galia, "northeast", true, true);		
		TheShinning->Nir->Mountains2->link(TheShinning->Nir->Mountains1, "east", true, true);
		TheShinning->Nir->Mountains2->link(TheShinning->Nir->Galia, "ne", true, true);			
		TheShinning->Nir->Mountains2->link(TheShinning->Nir->Mountains1, "e", true, true);
		//Mountains 3
		TheShinning->Nir->Mountains3->link(TheShinning->Nir->Galia, "northwest", true, true);
		TheShinning->Nir->Mountains3->link(TheShinning->Nir->Mountains1, "west", true, true);
		TheShinning->Nir->Mountains3->link(TheShinning->Nir->Galia, "nw", true, true);			
		TheShinning->Nir->Mountains3->link(TheShinning->Nir->Mountains1, "w", true, true);
		//Val'Sar: Entrance
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->Mountains1, "north", true, true);		
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->ValSar_caves, "south", true, true);	
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->ValSar_caves, "in", true, true);
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->Mountains1, "n", true, true);			
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->ValSar_caves, "s", true, true);		
		TheShinning->Nir->ValSar_entrance->link(TheShinning->Nir->ValSar_caves, "i", true, true);
		//Val'Sar: Caves
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->ValSar_entrance, "north", true, true);	
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "south", true, true);	
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "southeast", true, true);	
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "southwest", true, true);
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->ValSar_entrance, "n", true, true);		
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "s", true, true);		
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "se", true, true);		
		TheShinning->Nir->ValSar_caves->link(TheShinning->Nir->TheGreatSea, "sw", true, true);
		//The Great Sea
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "north", true, true);	
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "northeast", true, true);	
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "northwest", true, true);
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "n", true, true);		
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "ne", true, true);		
		TheShinning->Nir->TheGreatSea->link(TheShinning->Nir->ValSar_caves, "nw", true, true);
		//Meadow 1
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow3, "north", true, true);
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow3, "northeast", true, true);	
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow2, "northwest", true, true);
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow3, "n", true, true);	
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow3, "ne", true, true);			
		TheShinning->Nir->Meadow1->link(TheShinning->Nir->Meadow2, "nw", true, true);
		//Meadow 2
		TheShinning->Nir->Meadow2->link(TheShinning->Nir->Meadow1, "southeast", true, true);		
		TheShinning->Nir->Meadow2->link(TheShinning->Nir->Meadow3, "east", true, true);
		TheShinning->Nir->Meadow2->link(TheShinning->Nir->Meadow1, "se", true, true);				
		TheShinning->Nir->Meadow2->link(TheShinning->Nir->Meadow3, "e", true, true);
		//Meadow 3
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow2, "west", true, true);	
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow1, "south", true, true);	
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow1, "southwest", true, true);	
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Lake, "north", true, true);
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow2, "w", true, true);		
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow2, "s", true, true);		
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Meadow2, "sw", true, true);			
		TheShinning->Nir->Meadow3->link(TheShinning->Nir->Lake, "n", true, true);
		//Lake
		TheShinning->Nir->Lake->link(TheShinning->Nir->Meadow3, "south", true, true);	
		TheShinning->Nir->Lake->link(TheShinning->Nir->Meadow3, "southeast", true, true);	
		TheShinning->Nir->Lake->link(TheShinning->Nir->STower, "north", true, true);	
		TheShinning->Nir->Lake->link(TheShinning->Nir->Bay, "norththeast", true, true);
		TheShinning->Nir->Lake->link(TheShinning->Nir->Meadow3, "s", true, true);		
		TheShinning->Nir->Lake->link(TheShinning->Nir->Meadow3, "se", true, true);		
		TheShinning->Nir->Lake->link(TheShinning->Nir->STower, "n", true, true);		
		TheShinning->Nir->Lake->link(TheShinning->Nir->Bay, "ne", true, true);
		//Bay
		TheShinning->Nir->Bay->link(TheShinning->Nir->Lake, "southwest", true, true);	
		TheShinning->Nir->Bay->link(TheShinning->Nir->BigRock_Down, "north", true, true);
		TheShinning->Nir->Bay->link(TheShinning->Nir->Lake, "sw", true, true);			
		TheShinning->Nir->Bay->link(TheShinning->Nir->BigRock_Down, "n", true, true);
		//Big Rock: Down
		TheShinning->Nir->BigRock_Down->link(TheShinning->Nir->Bay, "south", true, true);
		TheShinning->Nir->BigRock_Down->link(TheShinning->Nir->Bay, "s", true, true);
		//Big Rock: Up
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->BigRock_Down, "south", true, true);	
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "north", true, true);	
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "northeast", true, true);	
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "northwest", true, true);
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->BigRock_Down, "s", true, true);	
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "n", true, true);		
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "ne", true, true);			
		TheShinning->Nir->BigRock_Up->link(TheShinning->Nir->ETower, "nw", true, true);
		//South Tower
		TheShinning->Nir->STower->link(TheShinning->Nir->Lake, "south", true, true);		
		TheShinning->Nir->STower->link(TheShinning->Nir->ETower, "east", true, true);		
		TheShinning->Nir->STower->link(TheShinning->Nir->WTower, "west", true, true);
		TheShinning->Nir->STower->link(TheShinning->Nir->Lake, "s", true, true);			
		TheShinning->Nir->STower->link(TheShinning->Nir->ETower, "e", true, true);		
		TheShinning->Nir->STower->link(TheShinning->Nir->WTower, "w", true, true);
		//East Tower
		TheShinning->Nir->ETower->link(TheShinning->Nir->STower, "south", true, true);	
		TheShinning->Nir->ETower->link(TheShinning->Nir->NTower, "north", true, true);		
		TheShinning->Nir->ETower->link(TheShinning->Nir->Maze1, "northeast", true, true);	
		TheShinning->Nir->ETower->link(TheShinning->Nir->BigRock_Up, "southwest", true, true);	
		TheShinning->Nir->ETower->link(TheShinning->Nir->BigRock_Up, "southeast", true, true);
		TheShinning->Nir->ETower->link(TheShinning->Nir->STower, "s", true, true);		
		TheShinning->Nir->ETower->link(TheShinning->Nir->NTower, "n", true, true);		
		TheShinning->Nir->ETower->link(TheShinning->Nir->Maze1, "ne", true, true);			
		TheShinning->Nir->ETower->link(TheShinning->Nir->BigRock_Up, "sw", true, true);		
		TheShinning->Nir->ETower->link(TheShinning->Nir->BigRock_Up, "se", true, true);
		//West Tower
		TheShinning->Nir->WTower->link(TheShinning->Nir->STower, "south", true, true);	
		TheShinning->Nir->WTower->link(TheShinning->Nir->NTower, "north", true, true);	
		TheShinning->Nir->WTower->link(TheShinning->Nir->Maze1, "northwest", true, true);
		TheShinning->Nir->WTower->link(TheShinning->Nir->STower, "s", true, true);		
		TheShinning->Nir->WTower->link(TheShinning->Nir->NTower, "n", true, true);		
		TheShinning->Nir->WTower->link(TheShinning->Nir->Maze1, "nw", true, true);
		//North Tower
		TheShinning->Nir->NTower->link(TheShinning->Nir->ETower, "east", true, true);		
		TheShinning->Nir->NTower->link(TheShinning->Nir->WTower, "west", true, true);	
		TheShinning->Nir->NTower->link(TheShinning->Nir->TheUnderground, "north", true, true);
		TheShinning->Nir->NTower->link(TheShinning->Nir->ETower, "e", true, true);		
		TheShinning->Nir->NTower->link(TheShinning->Nir->WTower, "w", true, true);		
		TheShinning->Nir->NTower->link(TheShinning->Nir->TheUnderground, "n", true, true);
		//Maze 1
		TheShinning->Nir->Maze1->link(TheShinning->Nir->Maze2, "north", true, true);			
		TheShinning->Nir->Maze1->link(TheShinning->Nir->Maze3, "northwest", true, true);		
		TheShinning->Nir->Maze1->link(TheShinning->Nir->ETower, "west", true, true);
		TheShinning->Nir->Maze1->link(TheShinning->Nir->Maze2, "n", true, true);				
		TheShinning->Nir->Maze1->link(TheShinning->Nir->Maze3, "nw", true, true);				
		TheShinning->Nir->Maze1->link(TheShinning->Nir->ETower, "w", true, true);
		//Maze 2
		TheShinning->Nir->Maze2->link(TheShinning->Nir->Maze1, "southeast", true, true);		
		TheShinning->Nir->Maze2->link(TheShinning->Nir->Maze3, "south", true, true);
		TheShinning->Nir->Maze2->link(TheShinning->Nir->Maze1, "se", true, true);				
		TheShinning->Nir->Maze2->link(TheShinning->Nir->Maze3, "nw", true, true);
		//Maze 3
		TheShinning->Nir->Maze3->link(TheShinning->Nir->Maze2, "northwest", true, true);		
		TheShinning->Nir->Maze3->link(TheShinning->Nir->Maze1, "north", true, true);
		TheShinning->Nir->Maze3->link(TheShinning->Nir->Maze2, "nw", true, true);				
		TheShinning->Nir->Maze3->link(TheShinning->Nir->Maze1, "n", true, true);
		//The Underground
		TheShinning->Nir->TheUnderground->link(TheShinning->Nir->NTower, "south", true, true);	
		TheShinning->Nir->TheUnderground->link(TheShinning->Nir->End, "north", true, true);
		TheShinning->Nir->TheUnderground->link(TheShinning->Nir->NTower, "s", true, true);		
		TheShinning->Nir->TheUnderground->link(TheShinning->Nir->End, "n", true, true);

	//Creating the player
	TheShinning->Aisu = new Player("Aisu", "the one that will know the truth", TheShinning->Nir->YourRoom);
}

void Clean_Game(){
	&World::Clean_Player;
	&Map::Clean_Rooms;
	&World::Clean_Map;
	&World::Clean_World;
}
	
void Game_Loop(World *TheShinning) {
	system("color 0A");

	//Init
	string command;

	//The Game
	std::cout << "Welcome to The Shinning! Before playing you may consider read the text \nbellow so you can play freely" << endl;
	std::cout << endl << "\t\t(all commands should be in lower case, true)" << endl << "Simple movement commands:" << endl << "   > north, south, east, west, in, out, down & up" << endl;
	std::cout << "   > n, s, e, w, i, o, d & up (respectively to the upper commands)" << endl << endl;
	
	while (command != "quit"){
		TheShinning->Aisu->currentRoom->Room::printRoom();
		std::cout << "What should I do ? ";
		cin >> command;

		if (command != "quit" && Movement_cmd(command) && Item_cmd(command) && Combat_cmd(command) && Misc_cmd(command)){
			system("color 0C");
			std::cout << endl << "Hmm... maybe i'll try something different" << endl;
			Sleep(500);
			system("color 0A");
		}
		std::cout << endl;
		if (TheShinning->Aisu->currentRoom->Is_Connected(TheShinning->Aisu->currentRoom)){
			if (TheShinning->Aisu->currentRoom->Is_Closed(TheShinning->Aisu->currentRoom)){
				if (TheShinning->Aisu->currentRoom->Room::getLinked(command) == NULL){
				}
				else{
					TheShinning->Aisu->currentRoom = TheShinning->Aisu->currentRoom->Room::getLinked(command);
					if (TheShinning->Aisu->currentRoom == TheShinning->Nir->End){
						command = "quit";
						continue;
					}
				}
			}
			else{
				std::cout << "The door is closed" << endl << endl;
			}
		}
	}

	TheShinning->Nir->End->Room::printRoom();
	std::cout << endl;
	system("pause");
}