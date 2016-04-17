#include "World.h"
#include "Room.h"
#include "Player.h"
#include "Exit.h"

// Constructor
World::World(){
	//Room Construction
	Room* YourRoom = new Room("Your Room", "You are at your Room. There is a book with some inscription that says\n<Game instructions>,maybe it is from the game you played with your \nfriends yesterday.\nNext to you there is a stair that takes you down to the living Room.");
	Room* LivingRoom = new Room("Living Room", "The room has some interesting things I might take with me...");
	Room* Galia = new Room("Galia", "An injured soldier is yelling desperately at the people; it seems \nhe started a fight with the wrong person. The people is surrounding\nthe soldier in a circle.");
	Room* Mountains1 = new Room("Mountains", "You are surrounded by mountains. You can see at the south the Mountains \nof Madness. To the east and to the west there are more mountains.");
	Room* Mountains2 = new Room("Mountains", "You are surrounded by mountains. At the northeast there is a path to \nGalia. There is a shield next to the path.");
	Room* Mountains3 = new Room("Mountains", "You are surrounded by mountains. At the northwest there is a path to Galia.");
	Room* ValSar_e = new Room("Val'Sar: Entrance", "You are at the entrance to the caves of Val'sar. The view is incredible,\nlooking to the distant north you can see a giant meadow,and next to it \nthere is a large tower. \nTo your left there is a soldier that protects the caves. He sees your \nbadge and enters the cave,leaving a scroll and a lamp.");
	Room* ValSar_c = new Room("Val'Sar Caves", "The cave is narrow and wet. You can see a distant light in front of \nyou,it is probably the only way out. The entrance is behind you.");
	Room* TheGreatSea = new Room("The Great Sea", "You can see how large is the southern sea of Nir.");
	Room* Meadow1 = new Room("Meadow", "You are in a huge meadow that goes in all directions. You can see a lake to the north and a tall tower. ");
	Room* Meadow2 = new Room("Meadow", "You are surrounded by mountains,the only way out is the way you came \nfrom. A graveyard is placed in the center of the field");
	Room* Meadow3 = new Room("Meadow", "You are looking to the north. The tower is even taller from where are \nyou at. To the west there is a small field surrounded by mountains.");
	Room* Lake = new Room("Lake", "You can almost see the tower in front of you. There is a path to the \nnortheast that leads to somewhere. To the south you can see how small \nis the metropolis in comparison with the world");
	Room* Bay = new Room("Bay", "A giant rock is blocking the way to the eastern part of the tower,\nyou could go down the rock,but it does not seems to be climbable");
	Room* BigRock_d = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room* BigRock_u = new Room("Big Rock", "It doesn't seem to be climbable but you could climb it down");
	Room* STower = new Room("South of the tower", "Next to you there is an immense door. You cannot probably open it. \nTo the east it seems to be an opened window. To the west there is \na cottage,maybe there were people living inside");
	Room* ETower = new Room("East of the tower", "Next to you there is a wide window where you culd probably fit in. To \nthe north you can see an entrance to an ominous cave");
	Room* WTower = new Room("West of the tower", "Next to you there is a cottage,the doors are broken and you can see \nthe only Room that survived time. It is all dust");
	Room* NTower = new Room("North of the tower", "To the north the only thing you see is an ominous entrance to a cave \nknown by the inhabitants as The Underground");
	Room* TheUnderground = new Room("The Underground: Entrance", "You fell like this is the end of your adventure... There is a door \nthat you could open if you use all of your strenght...");
	Room* Maze1 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* Maze2 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* Maze3 = new Room("Maze", "You are surrounded by walls and you don't know where the way out is");
	Room* End = new Room("Thank you for playing The Shinning", "Game made by Simon Stoyanov Beltran for college.\nBased on the game Zork.\n\t\thttps://github.com/SimonStoyanov");

	entities.push_back(YourRoom);		entities.push_back(LivingRoom);		entities.push_back(Galia);		entities.push_back(Mountains1);
	entities.push_back(Mountains2);		entities.push_back(Mountains3);		entities.push_back(ValSar_e);	entities.push_back(ValSar_c);
	entities.push_back(TheGreatSea);	entities.push_back(Meadow1);		entities.push_back(Meadow2);	entities.push_back(Meadow3);
	entities.push_back(Lake);			entities.push_back(Bay);			entities.push_back(BigRock_d);	entities.push_back(BigRock_u);
	entities.push_back(STower);			entities.push_back(ETower);			entities.push_back(WTower);		entities.push_back(NTower);
	entities.push_back(TheUnderground);	entities.push_back(Maze1);			entities.push_back(Maze2);		entities.push_back(Maze3);
	entities.push_back(End);

	//Exits
	Exit* YourRoom_LivingRoom = new Exit("down", "stairs", YourRoom, LivingRoom);
	Exit* LivingRoom_YourRoom = new Exit("up", "stairs", LivingRoom, YourRoom);
	Exit* LivingRoom_Galia = new Exit("out", "door", LivingRoom, Galia, true);
	Exit* Galia_LivingRoom = new Exit("in", "door", Galia, LivingRoom);
	Exit* Galia_Meadow1 = new Exit("east", "eastern gate", Galia, Meadow1);
	Exit* Galia_Mountains1 = new Exit("south", "southern gate", Galia, Mountains1);
	
	Exit* Mountains1_Galia = new Exit("north", "southern gate", Mountains1, Galia);
	Exit* Mountains1_Mountains2 = new Exit("west", "hilly trail", Mountains1, Mountains2);
	Exit* Mountains1_ValSarE = new Exit("south", "ValSar Entrance", Mountains1, ValSar_e);
	Exit* Mountains1_Mountains3 = new Exit("east", "hilly trail", Mountains1, Mountains3);
	Exit* Mountains2_Galia = new Exit("northeast", "path to Galia", Mountains2, Galia);
	Exit* Mountains2_Galia_AV = new Exit("north", "path to Galia", Mountains2, Galia);
	Exit* Mountains2_Mountains1 = new Exit("east", "hilly trail", Mountains2, Mountains1);
	Exit* Mountains3_Galia = new Exit("northwest", "pah to Galia", Mountains3, Galia);
	Exit* Mountains3_Galia_AV = new Exit("north", "path to Galia", Mountains3, Galia);
	Exit* Mountains3_Mountains1 = new Exit("west", "hilly trail", Mountains3, Mountains1);
	
	Exit* ValSarE_Mountains1 = new Exit("north", "ValSar Entrance", ValSar_e, Mountains1);
	Exit* ValSarE_ValSarC = new Exit("south", "tight passage", ValSar_e, ValSar_c);
	Exit* ValSarC_ValSarE = new Exit("north", "tight passage", ValSar_c, ValSar_e);
	Exit* ValSarC_TheGreatSea = new Exit("south", "the cave", ValSar_c, TheGreatSea);
	Exit* ValSarC_TheGreatSea_AV = new Exit("southeast", "the cave", ValSar_c, TheGreatSea);
	Exit* ValSarC_TheGreatSea_AV2 = new Exit("southwest", "the cave", ValSar_c, TheGreatSea);
	Exit* TheGreatSea_ValSarC = new Exit("northeast",  "the cave", TheGreatSea, ValSar_c);
	Exit* TheGreatSea_ValSarC_AV = new Exit("northwest", "the cave", TheGreatSea, ValSar_c);
	Exit* TheGreatSea_ValSarC_AV2 = new Exit("north", "the cave", TheGreatSea, ValSar_c);

	Exit* Meadow1_Galia = new Exit("west", "eastern gate", Meadow1, Galia);
	Exit* Meadow1_Meadow2 = new Exit("northwest", "meadow", Meadow1, Meadow2);
	Exit* Meadow1_Meadow3 = new Exit("north", "meadow", Meadow1, Meadow3);
	Exit* Meadow1_Meadow3_AV = new Exit("northeast", "meadow", Meadow1, Meadow3);
	Exit* Meadow2_Meadow1 = new Exit("southeast", "meadow", Meadow2, Meadow1);
	Exit* Meadow2_Meadow3 = new Exit("east", "meadow", Meadow2, Meadow3);
	Exit* Meadow3_Meadow1 = new Exit("south", "meadow", Meadow3, Meadow1);
	Exit* Meadow3_Meadow1_AV = new Exit("southwest", "meadow", Meadow3, Meadow1);
	Exit* Meadow3_Meadow2 = new Exit("west", "meadow", Meadow3, Meadow2);
	Exit* Meadow3_Lake = new Exit("north", "meadow", Meadow3, Lake);

	Exit* Lake_Bay = new Exit("northeast", "Lake", Lake, Bay);
	Exit* Lake_STower = new Exit("north", "hill", Lake, STower);
	Exit* Lake_Meadow3 = new Exit("southeast", "meadow", Lake, Meadow3);
	Exit* Lake_Meadow3_AV = new Exit("south", "meadow", Lake, Meadow3);
	Exit* Bay_Lake = new Exit("southwest", "bay", Bay, Lake);
	Exit* Bay_BigRockD = new Exit("north", "big rock", Bay, BigRock_d);
	Exit* BigRockD_Bay = new Exit("south", "big rock", BigRock_d, Bay);
	Exit* BigRockU_BigRockD = new Exit("down", "big rock", BigRock_u, BigRock_d);
	Exit* BigRockU_ETower = new Exit("north", "big rock", BigRock_u, ETower);

	Exit* STower_ETower = new Exit("east", "", STower, ETower);
	Exit* STower_WTower = new Exit("west", "", STower, WTower);
	Exit* STower_Lake = new Exit("south", "lake", STower, Lake);
	Exit* WTower_NTower = new Exit("north", "", WTower, NTower);
	Exit* WTower_Maze1 = new Exit("northwest", "", WTower, Maze1);
	Exit* WTower_STower = new Exit("south", "", WTower, STower);
	Exit* ETower_NTower = new Exit("north", "", ETower, NTower);
	Exit* ETower_Maze1 = new Exit("northeast", "", ETower, Maze1);
	Exit* ETower_STower = new Exit("south", "", ETower, STower);
	Exit* ETower_BigRockU = new Exit("southwest", "", ETower, BigRock_u);
	Exit* ETower_BigRockU_AV = new Exit("southeast", "", ETower, BigRock_u);
	Exit* NTower_WTower = new Exit("west", "", NTower, WTower);
	Exit* NTower_ETower = new Exit("east", "", NTower, ETower);
	Exit* NTower_TheUnderGround = new Exit("north", "entrance to the Underground", NTower, TheUnderground);
	Exit* TheUnderground_End = new Exit("north", "", TheUnderground, End);

	Exit* Maze1_ETower = new Exit("west", "", Maze1, ETower);
	Exit* Maze1_Maze2 = new Exit("northwest", "", Maze1, Maze2);
	Exit* Maze1_Maze3 = new Exit("north", "", Maze1, Maze3);
	Exit* Maze2_Maze1 = new Exit("north", "", Maze2, Maze1);
	Exit* Maze2_Maze3 = new Exit("northwest", "", Maze2, Maze3);
	Exit* Maze3_Maze1 = new Exit("southeast", "", Maze3, Maze1);
	Exit* Maze3_Maze2 = new Exit("south", "", Maze3, Maze2);

	entities.push_back(YourRoom_LivingRoom);	entities.push_back(LivingRoom_YourRoom);	entities.push_back(LivingRoom_Galia);
	entities.push_back(Galia_LivingRoom);		entities.push_back(Galia_Meadow1);			entities.push_back(Galia_Mountains1);			
	
	entities.push_back(Mountains1_Galia);		entities.push_back(Mountains1_Mountains2);	entities.push_back(Mountains1_ValSarE);
	entities.push_back(Mountains1_Mountains3);	entities.push_back(Mountains2_Galia);		entities.push_back(Mountains2_Galia_AV);	
	entities.push_back(Mountains2_Mountains1);	entities.push_back(Mountains3_Galia);		entities.push_back(Mountains3_Galia_AV);	
	entities.push_back(Mountains3_Mountains1);
			
	entities.push_back(ValSarE_Mountains1);		entities.push_back(ValSarE_ValSarC);		entities.push_back(ValSarC_ValSarE);
	entities.push_back(ValSarC_TheGreatSea);	entities.push_back(ValSarC_TheGreatSea_AV); entities.push_back(ValSarC_TheGreatSea_AV2);
	entities.push_back(TheGreatSea_ValSarC);	entities.push_back(TheGreatSea_ValSarC_AV);	entities.push_back(TheGreatSea_ValSarC_AV2);

	entities.push_back(Meadow1_Galia);			entities.push_back(Meadow1_Meadow2);		entities.push_back(Meadow1_Meadow3);
	entities.push_back(Meadow1_Meadow3_AV); 	entities.push_back(Meadow2_Meadow1);		entities.push_back(Meadow2_Meadow3);
	entities.push_back(Meadow3_Meadow1);		entities.push_back(Meadow3_Meadow1_AV);		entities.push_back(Meadow3_Meadow2);
	entities.push_back(Meadow3_Lake);

	entities.push_back(Lake_Bay);				entities.push_back(Lake_STower);			entities.push_back(Lake_Meadow3);				
	entities.push_back(Lake_Meadow3_AV);		entities.push_back(Bay_Lake);				entities.push_back(Bay_BigRockD);
	entities.push_back(BigRockD_Bay);			entities.push_back(BigRockU_BigRockD);		entities.push_back(BigRockU_ETower);

	entities.push_back(STower_ETower);			entities.push_back(STower_WTower);			entities.push_back(STower_Lake); 
	entities.push_back(WTower_NTower);			entities.push_back(WTower_Maze1);			entities.push_back(WTower_STower); 
	entities.push_back(ETower_NTower);			entities.push_back(ETower_Maze1);			entities.push_back(ETower_STower);
	entities.push_back(ETower_BigRockU);		entities.push_back(ETower_BigRockU_AV);		entities.push_back(NTower_WTower);
	entities.push_back(NTower_ETower);			entities.push_back(NTower_TheUnderGround);	entities.push_back(TheUnderground_End);

	entities.push_back(Maze1_ETower);			entities.push_back(Maze1_Maze2);			entities.push_back(Maze1_Maze3);
	entities.push_back(Maze2_Maze1);			entities.push_back(Maze2_Maze3);			entities.push_back(Maze3_Maze1);
	entities.push_back(Maze3_Maze2);

	// Items
	Item* Backpack = new Item("inventory", "You can put object into it and drop them into the floor... seems legit!");
	Item* Wardrobe = new Item("wardrobe", "maybe it will guide me to a mystical place... or maybe not", true, false, YourRoom);
	Item* Book = new Item("book", "simple book which I didn't read...", false, true, Wardrobe);
	Item* Knife = new Item("knife", "it is a japanese knife", false, true, LivingRoom);
	Item* Apple = new Item("apple", "just an apple", false, true, LivingRoom);
	Item* Shield = new Item("shield", "it seems to be a shield from the militia", false, true, Mountains2);

	entities.push_back(Backpack);
	entities.push_back(Wardrobe);
	entities.push_back(Book);
	entities.push_back(Knife);		
	entities.push_back(Apple);		
	entities.push_back(Shield);

	// Player
	player = new Player("Aisu", "An 18 year old that is looking for the truth", YourRoom, Backpack);

	entities.push_back(player);
}
// Destructor
World::~World(){
	for (int i = 0; i >= entities.size();){
		entities.pop_back();
	}

}
// Methods
void World::Game_Loop(){
	system("color 0A");

	// Init
	p2String player_input;
	char input_aux[25];
	p2Vector<p2String> commands;

	//The Game
	printf("Welcome to The Shinning! Before playing you may consider read the text \nbellow so you can play freely");
	printf("    (all commands should be in lower case and they must be one word)\n\nSimple movement commands:\n   > north, south, east, west, in, out, down & up\n");
	printf("   > n, s, e, w, i, o, d & up (respectively to the upper commands)\n");
	printf("   > open, close\n\n");
	
	if (first_loop){
		commands.push_back("look");
		Command(commands);
		first_loop = false;
	}
	while (1 ){
		p2Vector<p2String> commands;
		printf("> ");
		fgets(input_aux, 25, stdin);
		player_input = input_aux;
	
		player_input.Tokenize(' ', commands);
		
		Command(commands);

		if (commands[0] == "quit" || player->parent->getName() == "Thank you for playing The Shinning"){
			if (commands[0] == "quit"){
				printf("----Thank you for playing The Shinning----\nGame made by Simon Stoyanov Beltran for college.\nBased on the game Zork.\n\t\thttps://github.com/SimonStoyanov\n\n");
			}
			break;
		}
	}

	
}

bool World::Command(p2Vector<p2String>& commands){
	bool ret = true;

	switch (commands.size()){
	case 1:
	{
		if ((commands[0] == "look") || (commands[0] == "l")){
			player->Look(commands);
		}
		else if ((commands[0] == "north") || (commands[0] == "n")){
			commands[0] = "north";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "south") || (commands[0] == "s")){
			commands[0] = "south";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "east") || (commands[0] == "e")){
			commands[0] = "east";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "west") || (commands[0] == "w")){
			commands[0] = "west";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "northeast") || (commands[0] == "ne")){
			commands[0] = "northeast";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "northwest") || (commands[0] == "nw")){
			commands[0] = "northwest";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "southeast") || (commands[0] == "se")){
			commands[0] = "southeast";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "southwest") || (commands[0] == "sw")){
			commands[0] = "southwest";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "down") || (commands[0] == "d")){
			commands[0] = "down";
			player->Go(commands);
			player->Look(commands);
		}
		else if ((commands[0] == "up") || (commands[0] == "u")){
			commands[0] = "up";
			player->Go(commands);
			player->Look(commands);
		}
		else if (commands[0] == "outside" || commands[0] == "out"){
			commands[0] = "out";
			player->Go(commands);
			player->Look(commands);
		}
		else if(commands[0] == "inside" || commands[0] == "in"){
			commands[0] == "in";
			player->Go(commands);
			player->Look(commands);
		}
		else if (commands[0] == "i" || commands[0] == "inv" ||commands[0] == "inventory"){
			commands[0] = "inventory";
			commands.push_back("");
			player->Look(commands);
		}
		else if (commands[0] == "stats" || commands[0] == "st"){
			player->PrintStats();
		}
		else if (commands[0] == "quit"){
		}
		break;
	}
	case 2:
	{
		if (commands[0] == "look"){
			player->Look(commands);
		}
		else if (commands[0] == "go"){
			if (commands[1] == "north" || commands[1] == "n"){
				commands[1] = "north";
			}
			else if (commands[1] == "south" || commands[1] == "s"){
				commands[1] = "south";
			}
			else if (commands[1] == "east" || commands[1] == "e"){
				commands[1] = "east";
			}
			else if (commands[1] == "west" || commands[1] == "w"){
				commands[1] = "west";
			}
			else if (commands[1] == "northeast" || commands[1] == "ne"){
				commands[1] = "northeast";
			}
			else if (commands[1] == "northwest" || commands[1] == "nw"){
				commands[1] = "northwest";
			}
			else if (commands[1] == "southeast" || commands[1] == "se"){
				commands[1] = "southeast";
			}
			else if (commands[1] == "southwest" || commands[1] == "sw"){
				commands[1] = "southwest";
			}
			else if (commands[1] == "inside" || commands[1] == "in"){
				commands[1] = "in";
			}
			else if (commands[1] == "outside" || commands[1] == "out"){
				commands[1] = "out";
			}
			if (commands[1] == "down" || commands[1] == "d"){
				commands[1] = "down";
			}
			else if (commands[1] == "up" || commands[1] == "u"){
				commands[1] = "up";
			}
			player->Go(commands);
			player->Look(commands);
		}
		else if (commands[0] == "open" || commands[0] == "close"){
			if (commands[1] == "north" || commands[1] == "n"){
				commands[1] = "north";
			}
			else if (commands[1] == "south" || commands[1] == "s"){
				commands[1] = "south";
			}
			else if (commands[1] == "east" || commands[1] == "e"){
				commands[1] = "east";
			}
			else if (commands[1] == "west" || commands[1] == "w"){
				commands[1] = "west";
			}
			else if (commands[1] == "northeast" || commands[1] == "ne"){
				commands[1] = "northeast";
			}
			else if (commands[1] == "northwest" || commands[1] == "nw"){
				commands[1] = "northwest";
			}
			else if (commands[1] == "southeast" || commands[1] == "se"){
				commands[1] = "southeast";
			}
			else if (commands[1] == "southwest" || commands[1] == "sw"){
				commands[1] = "southwest";
			}
			else if (commands[1] == "inside" || commands[1] == "in"){
				commands[1] = "in";
			}
			else if (commands[1] == "outside" || commands[1] == "out"){
				commands[1] = "out";
			}
			if (commands[1] == "down" || commands[1] == "d"){
				commands[1] = "down";
			}
			else if (commands[1] == "up" || commands[1] == "u"){
				commands[1] = "up";
			}
			player->ChangeDoor(commands);
		}
		else if (commands[0] == "take" || commands[0] == "pick" || commands[0] == "get"){
			player->Pick(commands);
		}
		else if (commands[0] == "drop"){
			player->Drop(commands);
		}
		else if (commands[0] == "equip"){
			player->Equip(commands);
		}
		else if (commands[0] == "unequip"){
			player->Unequip();
		}
		break;
	}
	case 4:
		if (commands[0] == "pick" || commands[0] == "get" || commands[0] == "take"){
			player->Pick(commands);
		}
		else if (commands[0] == "drop" || commands[0] == "put" || commands[0] == "leave"){
			player->Drop(commands);
		}
		break;
	default:
		ret = false;
	}

	return ret;
}