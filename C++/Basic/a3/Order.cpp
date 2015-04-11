//Order.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

#include "GS1Prefix.h"
#include "Order.h"

using namespace std;

std::ostream & operator<<(std::ostream & os, const Order & order){
	order.display(os);
}

void Order::display(std::ostream & os) const {
	os << setw(17) << right << book << setw(9) << ordered << setw(11) << delivered;
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
