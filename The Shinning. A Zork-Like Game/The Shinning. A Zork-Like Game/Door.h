#ifndef Door_h
#define Door_h

#include <string>
#include <iostream>

using namespace std;

class Door{
private:
	bool open();
	bool close();
public:
	bool sda(){
		return door;
	}

};


#endif