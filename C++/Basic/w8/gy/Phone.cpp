#include <iostream>
#include <iomanip>
#include "Phone.h"

using namespace std;

void IntlPhone::display() const{
cout << setw(3) << countryCode <<"-";
Phone::display();
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
}

bool Phone::isValid() const {
	if(areaCode == 0 && locanNumber == 0)
		return false;
	else
		return true;
}

void Phone	::display() const {
	cout << areaCode << "-" << locanNumber/10000 << "-" << locanNumber%10000;
}