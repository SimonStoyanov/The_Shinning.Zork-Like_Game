#ifndef p2String_h
#define p2String_h

#include <string.h>
#include <cstring>

class p2String{
private:
	char* string;
	unsigned int max_size;
	void alloc(unsigned int size){
		string = new char[size];
	}
public:
	// Constructor
	p2String(){
		alloc(1);
		max_size = 1;
	}
	p2String(char* _string){
		max_size = strlen(_string) + 1;
		alloc(max_size);
		strcpy_s(this->string, (max_size * sizeof(char)) + 1, _string);

	}
	p2String(p2String& abc){
		max_size = strlen(abc.string) + 1;
		alloc(max_size);
		strcpy_s(this->string, ((max_size)* sizeof(char)) + 1, abc.string);
	}
	// Destructor
	~p2String(){
		delete[] this->string;
		this->string = nullptr;
		max_size = 0;
	}

	// Methods
	// Length
	unsigned int lenght() const{
		return strlen(this->string);
	}
	// Return text
	char* c_str() const {
		return this->string;
	}
	// Assign class(=)
	p2String& operator=(const p2String& str2){
		delete[] string;
		max_size = str2.lenght() + 1;
		alloc(max_size);
		strcpy_s(this->string, max_size, str2.c_str());
		return *this;
	}
	// Comparison ==
	bool operator==(p2String str2){//return 0 if both string are equal
		return strcmp(string, str2.c_str()) == 0;
	}
	// Comparison !=
	bool operator!=(p2String str2){//return something different than zero if both are different
		return strcmp(this->string, str2.c_str()) != 0;
	}
	// Comparison <
	bool operator<(p2String str2){
		return this->lenght() < str2.lenght();
	}
	// Empty
	bool empty() const{
		return this->lenght() == 0;
	}
	// Shrink
	void shrink_to_fit(){
		unsigned int size = this->lenght() + 1;

	}

};



#endif