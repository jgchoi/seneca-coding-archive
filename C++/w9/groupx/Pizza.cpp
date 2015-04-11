#include <iostream>
#include <cstring>
#include <iomanip>
#include "Pizza.h"

Pizza::Pizza(){
	size = 0;
	portion = 0;
	currentPortion = 0;
}
Pizza::Pizza(double a, int b){
	size = a;
	portion = b;
	currentPortion = b;
}
int Pizza::portions() const{
	return portion;
}

void Pizza::consume(){
	currentPortion -= 1;
}

int Pizza::remaining() const{
	return currentPortion;
}
void Pizza::display() const{
	std::cout << size << "\" " << portion << " slices " << currentPortion << " remaining\n";
}

DeluxePizza::DeluxePizza():Pizza(){
	toppings[0] = '\0';
}

DeluxePizza::DeluxePizza(double a, int b,const char * c):Pizza(a,b){
	std::strcpy(toppings, c);
}

void DeluxePizza::display() const{
	Pizza::display();
	std::cout << "- " << toppings;
}