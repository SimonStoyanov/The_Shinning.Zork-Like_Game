#include <iostream>
#include <string>
#include <conio.h>
#include <map>
#include <windows.h> 
#include <list>

#include "Room.h"
#include "Commands.h"
#include "World.h"
#include "Player.h"

using namespace std;



void Create_World(World *my_world){
	//Room Construction
	Room *YourRoom = new Room("Your Room", "You are at your Room. There is a book with some inscription that says\n<Game instructions>, maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living Room.");
	Room *LivingRoom = new Room("Living Room", "You can see a newspaper next to the chair. You left an apple at the\ntop of your table, it is from yesterday. Next to it there is a knife. \nThe exit is to the north");
	Room *Galia = new Room("Galia", "An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle.");
	Room *Mountains1 = new Room("Mountains", "You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains.");
	Room *Mountains2 = new Room("Mountains", "You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path.");
	Room *Mountains3 = new Room("Mountains", "You are surrounded by mountains. At the northwest there is a path to Galia.");
	Room *ValSar_entrance = new Room("Val'Sar: Entrance", "You are at the entrance to the caves of Val'sar. The view is incredible, \nlooking to the distant north you can see a giant meadow, and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave, leaving a scroll and a lamp.");
	Room *ValSar_Caves = new Room("Val'Sar Caves", "The cave is narrow and wet. You can see a distant light in front of \nyou, it is probably the only way out. The entrance is behind you.");
	Room *TheGreatSea = new Room("The Great Sea", "You can see how large is the southern sea of Nir.");
	Room *Meadow1 = new Room("Meadow", "You are in a huge meadow that goes in all directions. You can see a lake to the north and a tall tower. ");
	Room *Meadow2 = new Room("Meadow", "You are surrounded by mountains, the only way out is the way you came \nfrom. A graveyard is placed in the center of the field");
	Room *Meadow3 = new Room("Meadow", "You are looking to the north. The tower is even taller from where are \nyou at. To the west there is a small field surrounded by mountains.");
	Room *Lake = new Room("Lake", "You can almost see the tower in front of you. There is a path to the \nnortheast that leads to somewhere. To the south you can see how small \nis the metropolis in comparison with the world");
	Room *Bay = new Room("Bay", "A giant rock is blocking the way to the eastern part of the tower, \nyou could go down the rock, but it does not seems to be climbable");
	Room *BigRock_Down = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room *BigRock_Up = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room *STower = new Room("South of the tower", "Next to you there is an immense door. You cannot probably open it. \nTo the east it seems to be an opened window. To the west there is \na cottage, maybe there were people living inside");
	Room *ETower = new Room("East of the tower", "Next to you there is a wide window where you culd probably fit in. To \nthe north you can see an entrance to an ominous cave");
	Room *WTower = new Room("West of the tower", "Next to you there is a cottage, the doors are broken and you can see \nthe only Room that survived time. It is all dust");
	Room *NTower = new Room("North of the tower", "To the north the only thing you see is an ominous entrance to a cave \nknown by the inhabitants as The Underground");
	Room *TheUnderground = new Room("The Underground: Entrance", "You fell like this is the end of your adventure... There is a door \nthat you could open if you use all of your strenght...");
	Room *Maze1 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room *Maze2 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room *Maze3 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room *End = new Room("Made by Simon Stoyanov Beltran", "The story will continue... or not...");

	//Link Directions
		//Your Room
		YourRoom->link(LivingRoom, "down");
		YourRoom->link(LivingRoom, "d");
		//Living Room
		LivingRoom->link(YourRoom, "up");		LivingRoom->link(Galia, "out");		LivingRoom->link(Galia, "north");
		LivingRoom->link(YourRoom, "u");		LivingRoom->link(Galia, "o");		LivingRoom->link(Galia, "n");
		//Galia
		Galia->link(LivingRoom, "in");	Galia->link(Mountains1, "south");	Galia->link(Meadow1, "east");
		Galia->link(LivingRoom, "i");	Galia->link(Mountains1, "s");		Galia->link(Meadow1, "e");
		//Mountains 1
		Mountains1->link(Galia, "north");	Mountains1->link(Mountains2, "west");	Mountains1->link(Mountains3, "east");	Mountains1->link(ValSar_entrance, "south");
		Mountains1->link(Galia, "n");		Mountains1->link(Mountains2, "w");		Mountains1->link(Mountains3, "e");		Mountains1->link(ValSar_entrance, "s");
		//Mountains 2
		Mountains2->link(Galia, "northeast");	Mountains2->link(Mountains1, "east");
		Mountains2->link(Galia, "ne");			Mountains2->link(Mountains1, "e");
		//Mountains 3
		Mountains3->link(Galia, "northwest");	Mountains3->link(Mountains1, "west");
		Mountains3->link(Galia, "nw");			Mountains3->link(Mountains1, "w");
		//Val'Sar: Entrance
		ValSar_entrance->link(Mountains1, "north");		ValSar_entrance->link(ValSar_Caves, "south");	ValSar_entrance->link(ValSar_Caves, "in");
		ValSar_entrance->link(Mountains1, "n");			ValSar_entrance->link(ValSar_Caves, "s");		ValSar_entrance->link(ValSar_Caves, "i");
		//Val'Sar: Caves
		ValSar_Caves->link(ValSar_entrance, "north");	ValSar_Caves->link(TheGreatSea, "south");	ValSar_Caves->link(TheGreatSea, "southeast");	ValSar_Caves->link(TheGreatSea, "southwest");
		ValSar_Caves->link(ValSar_entrance, "n");		ValSar_Caves->link(TheGreatSea, "s");		ValSar_Caves->link(TheGreatSea, "se");			ValSar_Caves->link(TheGreatSea, "sw");
		//The Great Sea
		TheGreatSea->link(ValSar_Caves, "north");	TheGreatSea->link(ValSar_Caves, "northeast");	TheGreatSea->link(ValSar_Caves, "northwest");
		TheGreatSea->link(ValSar_Caves, "n");		TheGreatSea->link(ValSar_Caves, "ne");			TheGreatSea->link(ValSar_Caves, "nw");
		//Meadow 1
		Meadow1->link(Meadow3, "north");	Meadow1->link(Meadow3, "northeast");		Meadow1->link(Meadow2, "northwest");
		Meadow1->link(Meadow3, "n");		Meadow1->link(Meadow3, "ne");				Meadow1->link(Meadow2, "nw");
		//Meadow 2
		Meadow2->link(Meadow1, "southeast");		Meadow2->link(Meadow3, "east");
		Meadow2->link(Meadow1, "se");				Meadow2->link(Meadow3, "e");
		//Meadow 3
		Meadow3->link(Meadow2, "west");		Meadow3->link(Meadow1, "south");	Meadow3->link(Meadow1, "southwest");		Meadow3->link(Lake, "north");
		Meadow3->link(Meadow2, "w");		Meadow3->link(Meadow2, "s");		Meadow3->link(Meadow2, "sw");				Meadow3->link(Lake, "n");
		//Lake
		Lake->link(Meadow3, "south");	Lake->link(Meadow3, "southeast");	Lake->link(STower, "north");		Lake->link(Bay, "norththeast");
		Lake->link(Meadow3, "s");		Lake->link(Meadow3, "se");			Lake->link(STower, "n");			Lake->link(Bay, "ne");
		//Bay
		Bay->link(Lake, "southwest");	Bay->link(BigRock_Down, "north");
		Bay->link(Lake, "sw");			Bay->link(BigRock_Down, "n");
		//Big Rock: Down
		BigRock_Down->link(Bay, "south");
		BigRock_Down->link(Bay, "s");
		//Big Rock: Up
		BigRock_Up->link(BigRock_Down, "south");	BigRock_Up->link(ETower, "north");	BigRock_Up->link(ETower, "northeast");		BigRock_Up->link(ETower, "northwest");
		BigRock_Up->link(BigRock_Down, "s");		BigRock_Up->link(ETower, "n");		BigRock_Up->link(ETower, "ne");				BigRock_Up->link(ETower, "nw");
		//South Tower
		STower->link(Lake, "south");		STower->link(ETower, "east");	STower->link(WTower, "west");
		STower->link(Lake, "s");			STower->link(ETower, "e");		STower->link(WTower, "w");
		//East Tower
		ETower->link(STower, "south");	ETower->link(NTower, "north");		ETower->link(Maze1, "northeast");	ETower->link(BigRock_Up, "southwest");	ETower->link(BigRock_Up, "southeast");
		ETower->link(STower, "s");		ETower->link(NTower, "n");			ETower->link(Maze1, "ne");			ETower->link(BigRock_Up, "sw");			ETower->link(BigRock_Up, "se");
		//West Tower
		WTower->link(STower, "south");	WTower->link(NTower, "north");	WTower->link(Maze1, "northwest");
		WTower->link(STower, "s");		WTower->link(NTower, "n");		WTower->link(Maze1, "nw");
		//North Tower
		NTower->link(ETower, "east");	NTower->link(WTower, "west");	NTower->link(TheUnderground, "north");
		NTower->link(ETower, "e");		NTower->link(WTower, "w");		NTower->link(TheUnderground, "n");
		//Maze 1
		Maze1->link(Maze2, "north");			Maze1->link(Maze3, "northwest");		Maze1->link(ETower, "west");
		Maze1->link(Maze2, "n");				Maze1->link(Maze3, "nw");				Maze1->link(ETower, "w");
		//Maze 2
		Maze2->link(Maze1, "southeast");		Maze2->link(Maze3, "south");
		Maze2->link(Maze1, "se");				Maze2->link(Maze3, "nw");
		//Maze 3
		Maze3->link(Maze2, "northwest");		Maze3->link(Maze1, "north");
		Maze3->link(Maze2, "nw");				Maze3->link(Maze1, "n");
		//The Underground
		TheUnderground->link(NTower, "south");	TheUnderground->link(End, "north");
		TheUnderground->link(NTower, "s");		TheUnderground->link(End, "n");
}

void Clean_World(World *my_world){

}
	
int main() {
	system("color 0A");
	//Variables
	World my_world;
	string command;
	my_world.World::World();
	Room *currentRoom = Player(Player::getRoom)
	//The Game
	currentRoom->Room::printRoom();
	std::cout << "Welcome to The Shinning! Before playing you may consider read the README.txt \nso that you do not miss anything about how the game works" << endl << endl;
	
	while (command != "quit"){
		
		std::cout << "What should I do ? ";
		cin >> command;

		if (command != "quit" && Movement_cmd(command) && Item_cmd(command) && Combat_cmd(command) && Misc_cmd(command)){
			system("color 0C");
			std::cout << endl << "Hmm... maybe i'll try something different" << endl;
			Sleep(500);
			system("color 0A");
		}
		std::cout << endl;

		if (currentRoom->Room::getLinked(command) == NULL){
			continue;
		}
		else{
			currentRoom = currentRoom->Room::getLinked(command);	
		}
	}

	//Delete all Rooms

	//End

	return 0;
}