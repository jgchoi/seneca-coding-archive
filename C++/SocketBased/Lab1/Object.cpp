#include "Object.h"
#include <iostream>

Object::Object(int _bufferSize){
	//Setting Status Information
	status.bufferSize = _bufferSize;
	status.currentIndex = 0;

	//Initialize array
	buffer = new int[_bufferSize];
}

Object::~Object(){
	//delete dyanmic array
	delete[] buffer;
}

void Object::display() const{
	std::cout << "Buffer: ";
	for (int i = 0; i < status.bufferSize; i++){
		std::cout << buffer[i] << ", ";
	}
	std::cout << std::endl;
}

Object & Object::operator+=(int _buffer){
	buffer[status.currentIndex++] = _buffer;
	return *this;
}
