//Phone.cpp Group Y
//
#include <iostream>
#include <iomanip>
#include "Phone.h"

using namespace std;

std::istream & operator >> (std::istream & is, Phone& p){
	int a;
	long long int b;
	
	cout << "Area Code  : ";
	is >> a;
	cout << "Local No.  : ";
	is >> b;
	
	Phone tmp(a,b);
	p = tmp;
}

std::istream& operator>>(std::istream& is, IntlPhone& p){
	int a;
	int b;
	long long int c;
	
	cout << "Country    : ";
	is >> a;
	if(a != 0)
		{
			cout << "Area Code  : ";
			is >> b;
			cout << "Local No.  : ";
			is >> c;
	p=IntlPhone(a,b,c);
	//		IntlPhone tmp(a,b,c);
	//		p = tmp;
		}
	else
		{
			IntlPhone tmp;
			p=tmp;
		}

	
	
}
std::ostream& operator<<(std::ostream& os, const Phone& p){
	p.display(os);
}
std::ostream& operator<<(std::ostream& os, const IntlPhone& p){
	p.display(os);
}
//---------------------------------------------------------------------
void IntlPhone::display(std::ostream& os) const{
os << setw(3) << countryCode <<"-";
Phone::display(os);
}

IntlPhone::IntlPhone():Phone(){
	countryCode = 0;
}

IntlPhone::IntlPhone(int a, int b, long long int c) : Phone(b, c){
	if(a>0 && a<999)
		countryCode=a;
	else
		countryCode=0;
}


//---------------------------------------------------------------------

Phone::Phone(){
	areaCode =0;
	locanNumber=0;
}

Phone::Phone(int a, long long int b){
	if(a >= 100 && a <= 999)
		areaCode = a;
	else
		areaCode = 0;
		
	if(b >= 1000000 && b <= 9999999)
		locanNumber = b;
	else
		locanNumber = 0;
		
	//cout << areaCode <<":"<<locanNumber;
}

bool Phone::isValid() const {
	if(areaCode == 0 && locanNumber == 0)
		return false;
	else
		return true;
}

void Phone	::display(std::ostream& os) const {
	os << areaCode << "-" << locanNumber/10000 << "-" << locanNumber%10000;
}
