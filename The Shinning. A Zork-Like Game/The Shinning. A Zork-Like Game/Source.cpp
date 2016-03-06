#include <iostream>
#include <string>
#include <conio.h>
#include <map>

#include "Room.h"

using namespace std;

int main(){
	//Variables
	string command;
	
	//Rooms
	Room *YourRoom = new Room("Your Room", "You are at your room. There is a book with some inscription that says\n<Game instructions>, maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living room.");
	Room *LivingRoom = new Room("Living Room", "You can see a newspaper next to the chair. You left an apple at the\ntop of your table, it is from yesterday. Next to it there is a knife.");
	Room *Galia = new Room("Galia", "An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle.");
	Room *Mountains1 = new Room("Mounatins", "You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains.");
	Room *Mountains2 = new Room("Mountains", "You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path.");
	Room *Mountains3 = new Room("Mountains", "You are surrounded by mountains. At the northwest there is a path to Galia.");
	Room *ValSar_entrance = new Room("Val'Sar", "You are at the entrance to the caves of Val'sar. The view is incredible, \nlooking to the distant north you can see a giant meadow, and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave, leaving a scroll and a lamp.");


	//The Game
	std::cout << "Welcome to The Shinning!" << endl;
	
	YourRoom->printRoom();
	ValSar_entrance->printRoom();

	system("pause");
	return 0;
}