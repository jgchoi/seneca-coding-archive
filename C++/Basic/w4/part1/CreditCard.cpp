//CreditCard.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "CreditCard.h"

void CreditCard::charge(double c){
		bal = bal + c; // add balance
}
	
void CreditCard::pay(double p){
	bal = bal - p; //substract balance
}

long long CreditCard::number() const{
	return cardNum;
}

double CreditCard::balance() const{
	return bal;
}

const char * CreditCard::name() const{
	return cardHolder;
}

CreditCard::CreditCard(){ //constructor with no parameter, set 0 to all
	strcpy(cardHolder,"\0");
	cardNum = 0;
	bal = 0;	
}


CreditCard::CreditCard(long long int num, char * name){
	strcpy(cardHolder, name);

	cardNum = num;

	
	bal = 0;
}