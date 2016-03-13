#ifndef Map_h
#define Map_h

#include "Room.h"
#include <iostream>

class Map{
public:
	Room *YourRoom;			Room *LivingRoom;		Room *Galia;
	Room *Mountains1;		Room *Mountains2;		Room *Mountains3;
	Room *ValSar_entrance;	Room *ValSar_caves;		Room *TheGreatSea;
	Room *Meadow1;			Room *Meadow2;			Room *Meadow3;
	Room *Lake;				Room *Bay;				Room *BigRock_Up;
	Room *BigRock_Down;		Room *ETower;			Room *WTower;
	Room *STower;			Room *NTower;			Room *TheUnderground;
	Room *Maze1;			Room *Maze2;			Room *Maze3;
	Room *End;

	Map();

	void set_YourRoom(Room *room);	void set_LivingRoom(Room *room);	void set_Galia(Room *room);
	void set_Mountains1(Room *room);void set_Mountains2(Room *room);	void set_Mountains3(Room *room);
	void set_ValSar_e(Room *room);	void set_ValSar_c(Room *room);		void set_TheGreatSea(Room *room);
	void set_Meadow1(Room *room);	void set_Meadow2(Room *room);		void set_Meadow3(Room *room);
	void set_Lake(Room *room);		void set_Bay(Room *room);			void set_BigRock_u(Room *room);
	void set_BigRock_d(Room *room);	void set_ETower(Room *room);		void set_WTower(Room *room);
	void set_STower(Room *room);	void set_NTower(Room *room);		void set_TheUnderground(Room *room);
	void set_Maze1(Room *room);		void set_Maze2(Room *room);			void set_Maze3(Room *room);
	void set_End(Room *room);

	void Clean_Rooms(){
		delete YourRoom;		delete LivingRoom;		delete Galia;
		delete Mountains1;		delete Mountains2;		delete Mountains3;
		delete ValSar_entrance;	delete ValSar_caves;	delete TheGreatSea;
		delete Meadow1;			delete Meadow2;			delete Meadow3;
		delete Lake;			delete Bay;				delete BigRock_Up;
		delete BigRock_Down;	delete ETower;			delete WTower;
		delete STower;			delete NTower;			delete TheUnderground;
		delete Maze1;			delete Maze2;			delete Maze3;
		delete End;
	}
};

#endif
