//Item.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Item.h"
#include <new>

using namespace std;




Item::~Item(){delete [] desc;}
Item::Item(){num = 0; price = 0;desc = nullptr;}

Item::Item(int n, double p, char * s)
{num = n; price = p;
	desc = new char[strlen(s)+1];
	if(desc != nullptr)
		strcpy(desc,s);
}
bool Item::empty() const{
	if(num == 0 && price == 0)
		return true;
	else
		return false;
}
void Item::operator=(double p){price = p;}
void Item::display(std::ostream & os) const {
	os << setw(8) << left<<num;
	os <<setw(10) << right << fixed <<setprecision (2) << price;
	os << setw(12) << left<< " "<<desc;
}




std::istream & operator >> (std::istream & is, Item & i){
	int a;
	double b;
	char c[1000];
	
	cout<<"Item Number : ";
	is >> a;
	cout <<"price      : ";
	is >> b;
	cout <<"Description: ";
	is.ignore();
	is.getline(c,999);
	
//	i.num = a;
//	i.price = b;
	if(i.desc != nullptr)
		delete [] i.desc;
//	i.desc = new char[strlen(c)+1];
//	strcpy(i.desc,c);
	i = Item(a,b,c);	

}

std::ostream & operator << (std::ostream & os, const Item & i){
	i.display(os);
}

