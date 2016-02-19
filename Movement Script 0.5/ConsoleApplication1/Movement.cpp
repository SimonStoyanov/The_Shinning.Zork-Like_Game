#include <stdio.h>
#include <stdlib.h>

enum Room
{
	Dinning_Room,
	Kitchen,
	Bathroom,
	Bedroom,
	Pantry
};

void Room(int Room){
	if (Room == Dinning_Room){
		printf("You are at the dinning room.\n  To the north you have the kitchen\n  To the east the bathroom\n  To the south the bedroom");
	}
	if (Room == Kitchen){
		printf("You are at the kitchen.\n  To the east you have the pantry\n  To the south the dinning room");
	}
	if (Room == Bathroom){
		printf("You are at the bathroom.\n  To the west you have the dinning room");
	}
	if (Room == Bedroom){
		printf("You are at the bedroom.\n  To the north you have the dinning room");
	}
	if (Room == Pantry){
		printf("You are at the pantry.\n  To the west you have the kitchen");
	}
	printf("\nWhat direction do you want to move? (type n, s, e, w or q) ");
}

void Movement(){
	char input = ' ';
	int n = 0;
	while (input != 'q'){
		Room(n);
		scanf_s(" %c", &input, 1);
		switch (input)
		{
		case 'n':
		{
					if (n == 0) n = Kitchen;
					else if (n == 3) n = Dinning_Room;
					else if (n == 1 || n == 2 || n == 4) printf("\nThere is a wall\n");
		}
			break;
		case 's':
		{
					if (n == 0) n = Bedroom;
					else if (n == 1) n = Dinning_Room;
					else if (n == 2 || n == 3 || n == 4)printf("\nThere is a wall\n");
		}
			break;
		case 'e':
		{
					if (n == 0) n = Bathroom;
					else if (n == 1) n = Pantry;
					else if (n == 2 || n == 3 || n == 4)printf("\nThere is a wall\n");
		}
			break;
		case 'w':
		{
					if (n == 2) n = Dinning_Room;
					else if (n == 4) n = Kitchen;
					else if (n == 0 || n == 1 || n == 3) printf("\nThere is a wall\n");
		}
			break;
		case 'q':
			break;
		default:
			break;
		}
		printf("\n");
	}
}

int main(){
	Movement();
	
	system("pause");
	return 0;
}