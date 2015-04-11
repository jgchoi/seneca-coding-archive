#include <iostream>
#include <cstring>
#include <iomanip>
#include "Chocolate.h"

	DeluxeChocolate::DeluxeChocolate(DeluxeChocolate & src):Chocolate(src){
		strcpy(toppings, src.toppings);

	}
	Chocolate::Chocolate(Chocolate & src){
			portion = src.portion;
		currentPortion = src.currentPortion;
	}

Chocolate::Chocolate(){
	
	portion = 0;
	currentPortion = 0;
}
Chocolate::Chocolate(int b){

	portion = b;
	currentPortion = b;
}
int Chocolate::portions() const{
	return portion;
}

void Chocolate::consume(){
	currentPortion -= 1;
}

int Chocolate::remaining() const{
	return currentPortion;
}
void Chocolate::display() const{
	std::cout << portion << " squares " << currentPortion << " remaining\n";
}

DeluxeChocolate::DeluxeChocolate():Chocolate(){
	toppings[0] = '\0';
}

DeluxeChocolate::DeluxeChocolate(int b,const char * c):Chocolate(b){
	std::strcpy(toppings, c);
}

void DeluxeChocolate::display() const{
	Chocolate::display();
	std::cout << "- " << toppings;
}