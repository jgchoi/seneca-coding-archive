//process.cpp

#include "process.h"
#include "CString.h"


void process(char *str){
	/*w1::CString *tmp = new w1::CString(str);
	std::cout << *tmp;*/
	
	w1::CString tmp(str);
	std::cout << tmp;
	std::cout << std::endl;
}