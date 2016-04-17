#ifndef __DYNARRAY_H__
#define __DYNARRAY_H__

#include <string.h>
#include <stdio.h>

#define P2VECTOR_BLOCK_SIZE 16




template <class T>
class p2Vector{
private:
	T* buffer;
	int capacity;
	int num_elements;

public:

	//Constructors

	p2Vector() :
		capacity(P2VECTOR_BLOCK_SIZE),
		num_elements(0)
	{
		buffer = new T[P2VECTOR_BLOCK_SIZE];
	};
	p2Vector(int inum_elements) :
		capacity((P2VECTOR_BLOCK_SIZE)*((inum_elements / P2VECTOR_BLOCK_SIZE) + 1)),
		num_elements(0)

	{
		buffer = new T[capacity];
	}

	p2Vector(const p2Vector& idynarray){
		int iarraysize = idynarray.capacity;
		buffer = new T[iarraysize];
		memcpy(buffer, idynarray.buffer, iarraysize*sizeof(T));
		capacity = idynarray.capacity;
		num_elements = idynarray.num_elements;
	}

	//Destructor

	~p2Vector(){
		delete[] buffer;
	}

	//Methods

	void push_back(const T& element){
		num_elements++;
		if ((int)num_elements > capacity){
			p2Vector<T> temp(*this);
			delete[] buffer;
			capacity = ((P2VECTOR_BLOCK_SIZE)*((num_elements / P2VECTOR_BLOCK_SIZE) + 1));
			buffer = new T[capacity];
			memcpy(buffer, temp.buffer, capacity*sizeof(T));
		}
		buffer[num_elements - 1] = element;

	}

	void push_back(){
		num_elements++;
		if ((int)num_elements > capacity){
			p2Vector<T> temp(*this);
			delete[] buffer;
			capacity = ((P2VECTOR_BLOCK_SIZE)*((num_elements / P2VECTOR_BLOCK_SIZE) + 1));
			buffer = new T[capacity];
			memcpy(buffer, temp.buffer, capacity*sizeof(T));
		}
	}

	int size()const{
		return num_elements;
	}

	T& operator[](int index){
		return buffer[index];
	}

	void pop_back(){
		if (num_elements) delete buffer[--num_elements];
	}
};



#endif //__DYNARRAY_H__