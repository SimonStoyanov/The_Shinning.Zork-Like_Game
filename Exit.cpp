#include "Exit.h"

Exit::Exit(const char* name, const char* description, Room* origin, Room* _destination, bool closed) :
	Entity(name, description, (Entity*)origin),
	origin(origin),
	closed(closed),
	destination(_destination),
	locked(false),
	key(NULL)
	{
		type = EXIT;
	}

Exit::~Exit(){}


