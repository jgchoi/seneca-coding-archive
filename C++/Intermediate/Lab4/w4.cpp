// Workshop 4 - Templates
// w4.cpp

#include <iostream>
#include <iomanip>
#include <string>
#include "Pair.h"
#include "List.h"


int main(int argc, char** argv) {
	const int N = 5;
	int width;
	bool keepreading;
	std::cout << std::fixed << std::setprecision(2);

	std::cout << "\nInventory\n=========\n";
	List <Pair<std::string, double>, N> inventory;
	std::string str;
	double price;

	keepreading = true;
	do {
		std::cout << "Product : ";
		getline(std::cin, str);
		if (str.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "Price : ";
			std::cin >> price;
			std::cin.ignore();
			Pair <std::string, double> pair(str, price);
			inventory += pair;
		}
	} while (keepreading);

	std::cout << "\nPrice List\n-----------\n";
	width = inventory.width() + 1;
	for (int i = 0; i < inventory.size(); i++)
		std::cout << std::setw(width) << inventory[i].first()
		<< " : " << inventory[i].second() << std::endl;

	std::cout << "\nGlossary\n========\n";
	List <Pair<std::string, std::string>, N> glossary;
	std::string key, definition;

	keepreading = true;
	do {
		std::cout << "Key : ";
		getline(std::cin, key);
		if (key.compare("quit") == 0) {
			keepreading = false;
		}
		else {
			std::cout << "Definition : ";
			getline(std::cin, definition);
			Pair <std::string, std::string> pair(key, definition);
			glossary += pair;
		}
	} while (keepreading);

	std::cout << "\nEntries\n-------\n";
	width = glossary.width() + 1;
	for (int i = 0; i < glossary.size(); i++)
		std::cout << std::setw(width) << glossary[i].first()
		<< " : " << glossary[i].second() << std::endl;
}