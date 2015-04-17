//w1.cpp

#include "CString.h"
#include "process.h"



int main(int argc, char *argv[]){
	
	//Command line + user command arguments
	std::cout << "Command Line : ";
	
		for(int i = 0; i<argc; i++){
		std::cout << argv[i]<<" ";
	}
	std::cout << std::endl;
	
	
	//check arg number
	if(argc == 1)
		{
		std::cout << "Insufficient number of arguments (min 1)"<< std::endl;
		return 1;
		}
	
	
	//Show maximum number of char
	std::cout << "Maximum number of characters stored : " << w1::MAX << std::endl;

	
	//use process function
	
	for(int i=1;i<argc;i++){
		process(argv[i]);
	}
	return 0;
}