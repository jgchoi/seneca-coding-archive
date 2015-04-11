#include "Class.h"
#include <iostream>

protocol::protocol(int size_arg)
{
	//setting header
	header_str.ID = 1;
	header_str.Count = 1;
	header_str.flag1 = 1;
	header_str.flag2 = 1;
	header_str.flag3 = 1;
	header_str.flag4 = 1;

	//D.A.
	size = size_arg;
	data = new int[size];

	//default value
	for (int i = 0; i < size; i++)
		data[i] = 0;

}
protocol::~protocol()
{
	delete[] data;
}
void protocol::display_header() const
{
	unsigned char *Buffer = (unsigned char *)&header_str;
	std::cout << "Here is the header info (in hex): ";
	for (int i = 0; i < 2; i++)
		std::cout << std::hex << (int)*(Buffer++);
	std::cout << std::endl;
}

void set_data_items(protocol & protocoal_obj)
{
	int user_input;
	for (int i = 0; i < protocoal_obj.size; i++)
	{
		std::cout << "What is the value of the 0th element: ";
		std::cin >> user_input;
		protocoal_obj.data[i] = user_input;
	}
}

void display_data_items(protocol & protocoal_obj)
{
	std::cout << "Your data elements are: ";
	for (int i = 0; i < protocoal_obj.size; i++)
	{
		std::cout << protocoal_obj.data[i] << " ";
	}
	std::cout << std::endl;
}

