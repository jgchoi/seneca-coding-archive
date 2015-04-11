//Order.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

#include "GS1Prefix.h"
#include "Order.h"

using namespace std;

SpecialOrder::~SpecialOrder(){
	if(instruction != nullptr)
		delete [] instruction;
}

SpecialOrder& SpecialOrder::operator=(const SpecialOrder& source){
	if(this != &source)
		{
			Order & order = *this;
			order = source;
			
			if(instruction != nullptr)
				delete [] instruction;
			instruction = new char [strlen(source.instruction)+1];
			strcpy(instruction,source.instruction);
		}
		
	return *this;
}
SpecialOrder::SpecialOrder(const SpecialOrder & source):Order(source){
	if(instruction != nullptr)
		delete [] instruction;
		
	instruction = new char[strlen(source.instruction)+1];
	strcpy(instruction, source.instruction);
}

SpecialOrder::SpecialOrder():Order(){
	instruction = nullptr;
}

SpecialOrder::SpecialOrder(const EAN & isbn, const char * instr):Order(isbn){
	instruction = new char[strlen(instr)+1];
	
	if(instruction != nullptr)
		strcpy(instruction,instr);
}

std::ostream & operator<<(std::ostream & os, const iOrder & order){
	order.display(os);
}





void SpecialOrder::display(std::ostream & os) const{
	Order::display(os);
	os << "  "<<instruction;
}

bool SpecialOrder::add(std::istream & is){
	int keepAsking = 0;
	int tmp;
	bool result;
	char tmpp[61];
	
	//quantity input
	do{
		cout << "Enter quantity : ";
		is >> tmp;
		
		//validation
		if(tmp<0)
			cout << "Quantity must be positive number\n";
		else
		if(tmp == 0)
			{
				cout << "No data entered\n";
				return false;
			}
		else
			keepAsking = 1;
	}while(keepAsking == 0);
	result = Order::add(tmp);
	
	
	//special instruction part
	keepAsking=0;
	do{
	cout << "Enter Special Instruction : ";
	is.ignore(2000, '\n');
	is.getline(tmpp, 60);
	
	if(is.fail())
		{
			is.clear();
			is.ignore(2000, '\n');
			cout << "Invalid input. Try again \n";
		}
	else
	if(tmpp[0] == '\n')
		{
			cout << "Empty instruction, No data accepted. \n";
			return false;
		}
	else
		keepAsking = 1;
		}while(keepAsking==0);
	//at this point, only valid input are accepted.
	strcpy(instruction,tmpp);
	return true;
}




void Order::display(std::ostream & os) const {
	os << setw(17) << right << book << setw(9) << ordered << setw(11) << delivered;
}

Order::Order(const Order & source){
	
	book = source.book;
	ordered = source.ordered;
	delivered = source.delivered;
	}
	
bool Order::receive(std::istream & is){
	int add;
	int keepAsking = 0;
		
	do
		{
			cout << "Quantity (0 to quit) : " ;
			is >> add;
			if(add > ordered)
				{
					cout << add << " not on order.  Only " << ordered << " are on order. Try again." << endl;
				}
			else if( add < 0)
				{
					cout <<"Enter a positive number.  Try again." << endl;
				}
			else if( add == 0)
				{
					cout << "**No delivery recorded!" << endl;
					return false;
				}
			else
				{
					delivered = add;
					return true;
				}
		}
	while(keepAsking == 0);
	
	return false;
}


bool Order::add(int n){
	if( n <= 0 || book.empty() == true)
		cout << "Enter a positive number.  Try again." << endl;
	else
		{
			ordered = ordered + n;
			return true;
		}
		
	return false;
}

bool Order::add(std::istream & is){
	int x = 0;
	int keepAsking = 0;

	do
		{	
			cout << "Quantity (0 to quit) : " ;
			is >> x;
			if(x < 0)
				{
					cout << "Enter a positive number.  Try again." << endl;
				}
			else if( x == 0)
				{	
					cout << "**No ordered recorded!" << endl;
					return false;
				}
			else
				{	
					ordered = ordered + x;
					return true;
				}
		}
	while(keepAsking == 0);
	
	return false;	
}

Order::Order(){
	ordered = 0;
	delivered = 0;
}

Order::Order(const EAN & ean){
	book = ean;
	ordered = 0;
	delivered = 0;
}

EAN & Order::getEAN(){
	return book;
}

int Order::outstanding() const{
	return ordered;
}	
