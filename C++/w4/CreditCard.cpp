//CreditCard.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "CreditCard.h"

void CreditCard::charge(double c){
	if(c < 0) //if c is negative 
		{
		cout << "*** amount must be more than 0. Try Again" << endl;
		}
	else
		bal = bal + c;
}
	
void CreditCard::pay(double p){
	if(p < 0)
		{
		cout << "*** amount must be more than 0. Try Again" << endl;
		}
	else
	bal = bal - p;
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

CreditCard::CreditCard(){
	strcpy(cardHolder,"\0");
	cardNum = 0;
	bal = 0;	
}


CreditCard::CreditCard(long long int num, char * name){
	strcpy(cardHolder, name);
	nameValidation(); // validation (if fails set to 0)
	
	cardNum = num;
	numValidation(); // validation (if fails set to 0)
	bal = 0;
}

void CreditCard::numValidation(){
	int digit[16];
	long long num = cardNum;
	int sum=0;
	int i;
	
	for(i=15;i>=0;i--) //num to digit
		{
		digit[i]=num%10;
		num = num/10;
		}
		
	for(i=0;i<15;i=i+2)  // double and -9 if more than 9, 1,3,5,7digits..
		{
		digit[i] = digit[i]*2;
		if(digit[i]>9)
			digit[i] = digit[i]-9;
		sum = sum + digit[i];

		}
	
	for(i=1;i<16;i=i+2) // add least of digits
		{		
		sum = sum + digit[i];

		}
		


	if(sum%10 != 0) // if it is not dividable by 10, it's wrong card number
		{
		cardNum = 0;
		}
}

void CreditCard::nameValidation(){
int i;
	for(i=0 ; i < 22 ; i++ )
	{
		if(cardHolder[i] == '\0') // 
			{
			break; // if \0 found in between 0~20, do nothing
			}
		else if(i == 21 && cardHolder[i] != '\0') //if there was no \0 in 0~20 and when i==21 with char[21] != \0 then
			{
			strcpy(cardHolder,"\0");
			}
	}
}
