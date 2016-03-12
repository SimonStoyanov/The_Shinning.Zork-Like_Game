#include "Map.h"

Map::Map(){
	YourRoom = NULL;		LivingRoom = NULL;		Galia = NULL;
	Mountains1 = NULL;		Mountains2 = NULL;		Mountains3 = NULL;
	ValSar_entrance = NULL;	ValSar_caves = NULL;	TheGreatSea = NULL;
	Meadow1 = NULL;			Meadow2 = NULL;			Meadow3 = NULL;
	Lake = NULL;			Bay = NULL;				BigRock_Up = NULL;
	BigRock_Down = NULL;	ETower = NULL;			WTower = NULL;
	STower = NULL;			NTower = NULL;			TheUnderground = NULL;
	Maze1 = NULL;			Maze2 = NULL;			Maze3 = NULL;
	End = NULL;
}

void Map::set_YourRoom(Room *room){
	YourRoom = room;
}	
void Map::set_LivingRoom(Room *room){
	LivingRoom =
}	
void Map::set_Galia(Room *room){
	Galia = room;
}
void Map::set_Mountains1(Room *room){
	Mountains1 = room;
}	
void Map::set_Mountains2(Room *room){
	Mountains2 = room;
}	
void Map::set_Mountains3(Room *room){
	Mountains3 = room;
}
void Map::set_ValSar_e(Room *room){
	ValSar_entrance = room;
}	
void Map::set_ValSar_c(Room *room){
	ValSar_caves = room;
}		
void Map::set_TheGreatSea(Room *room){
	TheGreatSea = room;
}
void Map::set_Meadow1(Room *room){
	Meadow1 = room;
}	
void Map::set_Meadow2(Room *room){
	Meadow2 = room;
}		
void Map::set_Meadow3(Room *room){
	Meadow3 = room;
}
void Map::set_Lake(Room *room){
	Lake = room;
}		
void Map::set_Bay(Room *room){
	Bay = room;
}			
void Map::set_BigRock_u(Room *room){
	BigRock_Up = room;
}
void Map::set_BigRock_d(Room *room){
	BigRock_Down = room;
}	
void Map::set_ETower(Room *room){
	ETower = room;
}	
void Map::set_WTower(Room *room){
	WTower = room;
}
void Map::set_STower(Room *room){
	STower = room;
}	
void Map::set_NTower(Room *room){
	NTower = room;
}	
void Map::set_TheUnderground(Room *room){
	TheUnderground = room;
}
void Map::set_Maze1(Room *room){
	Maze1 = room;
}		
void Map::set_Maze2(Room *room){
	Maze2 = room;
}		
void Map::set_Maze3(Room *room){
	Maze3 = room;
}
void Map::set_End(Room *room){
	End = room;
}