#include "Class.h"
#include <iostream>



Data::Data()
{
	//set every value to 0
	header.ID = 0;
	header.Count = 0;
	header.Flag1 = 0;
	header.Flag2 = 0;
	header.Flag3 = 0;
	header.Flag4 = 0;
}

void Data::Display() const
{
	std::cout << "ID: " << (unsigned int)header.ID << std::endl;
	std::cout << "Count: " << (unsigned int)header.Count << std::endl;
	std::cout << "Flags: " << (bool)header.Flag1 << ", ";
	std::cout << (bool)header.Flag2 << ", ";
	std::cout << (bool)header.Flag3 << ", ";
	std::cout << (bool)header.Flag4 << std::endl;
}

void Data::SetID(const char* _ID)
{
	header.ID = atoi(_ID);
}
void Data::SetCount(const char* _Count)
{
	header.Count = atoi(_Count);
}
void Data::SetFlag1(const char * _Flag)
{
	//check starting char to decide true or false
	if (_Flag[0] == 'f')
		header.Flag1 = 0;
	else
		header.Flag1 = 1;
}
void Data::SetFlag2(const char * _Flag)
{
	if (_Flag[0] == 'f')
		header.Flag2 = 0;
	else
		header.Flag2 = 1;
}
void Data::SetFlag3(const char * _Flag)
{
	if (_Flag[0] == 'f')
		header.Flag3 = 0;
	else
		header.Flag3 = 1;
}
void Data::SetFlag4(const char * _Flag)
{
	if (_Flag[0] == 'f')
		header.Flag4 = 0;
	else
		header.Flag4 = 1;
}


//friend funcition
void DisplayHex(Data src)
{
	//assigning address of header as unsigned char 
	unsigned char * buffer = (unsigned char*)&src.header;

	//title
	std::cout << "Hex: ";
	
	//2 bytes
	for (auto i = 0; i < 2; i++)
		std::cout << std::hex << (unsigned int)*(buffer++);

	//end output
	std::cout << std::endl;
}