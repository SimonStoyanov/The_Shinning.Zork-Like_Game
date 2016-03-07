#include <iostream>
#include <string>
#include <conio.h>
#include <map>
#include <windows.h> 

#include "Room.h"
#include "Commands.h"

using namespace std;

int main(){
	system("color 0E");
	//Variables
	string command;

	//Rooms
	Room *YourRoom = new Room("Your Room", "You are at your Room. There is a book with some inscription that says\n<Game instructions>, maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living Room.");
	Room *LivingRoom = new Room("Living Room", "You can see a newspaper next to the chair. You left an apple at the\ntop of your table, it is from yesterday. Next to it there is a knife.");
	Room *Galia = new Room("Galia", "An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle.");
	Room *Mountains1 = new Room("Mounatins", "You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains.");
	Room *Mountains2 = new Room("Mountains", "You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path.");
	Room *Mountains3 = new Room("Mountains", "You are surrounded by mountains. At the northwest there is a path to Galia.");
	Room *ValSar_entrance = new Room("Val'Sar", "You are at the entrance to the caves of Val'sar. The view is incredible, \nlooking to the distant north you can see a giant meadow, and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave, leaving a scroll and a lamp.");
	Room *ValSar_Caves = new Room("Val'Sar Caves", "The cave is narrow and wet. You can see a distant light in front of \nyou, it is probably the only way out. The entrance is behind you.");
	Room *Meadow1 = new Room("Meadow", "You are in a huge meadow that goes in all directions. You can see a lake to the north and a tall tower. ");
	Room *Meadow2 = new Room("Meadow", "You are surrounded by mountains, the only way out is the way you came \nfrom. A graveyard is placed in the center of the field");
	Room *Meadow3 = new Room("Meadow", "You are looking to the north. The tower is even taller from where are \nyou at. To the west there is a small field surrounded by mountains.");
	Room *Lake = new Room("Lake", "You can almost see the tower in front of you. There is a path to the \nnortheast that leads to somewhere. To the south you can see how small \nis the metropolis in comparison with the world");
	Room *Bay = new Room("Bay", "A giant rock is blocking the way to the eastern part of the tower, \nyou could go down the rock, but it does not seems to be climbable");
	Room *STower = new Room("South of the tower", "Next to you there is an immense door. You cannot probably open it. \nTo the east it seems to be an opened window. To the west there is \na cottage, maybe there were people living inside");
	Room *ETower = new Room("East of the tower", "Next to you there is a wide window where you culd probably fit in. To \nthe north you can see an entrance to an ominous cave");
	Room *WTower = new Room("West of the tower", "Next to you there is a cottage, the doors are broken and you can see \nthe only Room that survived time. It is all dust");
	Room *NTower = new Room("North of the tower", "To the north the only thing you see is an ominous entrance to a cave \nknown by the inhabitants as The Underground");
	Room *Maze1 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room *Maze2 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room *Maze3 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");

	//Link Directions

	//The Game
	std::cout << "Welcome to The Shinning! Before plying you may consider read the README.txt \nso that you do not miss anything about how the game works" << endl << endl;
	Room *currentRoom = YourRoom;
	while (command != "quit"){
		currentRoom->Room::printRoom();
		std::cout << "What should I do ? ";
		cin >> command;
		if (command != "quit" && Movement_cmd(command) && Item_cmd(command) && Combat_cmd(command) && Misc_cmd(command)){
			system("color 0C");
			std::cout << endl << "Hmm... maybe i'll try something different" << endl << endl;
			Sleep(500);
			system("color 0E");
		}
	}


	//Delete all Rooms
	delete YourRoom; delete LivingRoom; delete Galia;
	delete Mountains1; delete Mountains2; delete Mountains3;
	delete ValSar_entrance; delete ValSar_Caves;
	delete Meadow1; delete Meadow2; delete Meadow3;
	delete Lake; delete Bay;
	delete STower; delete ETower; delete WTower; delete NTower;
	delete Maze1; delete Maze2; delete Maze3;

	//End
	system("pause");
	return 0;
}