// Workshop 7 - STL Containers
// w7.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "Product.h"

int main(int argc, char** argv) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	// open a product file - name is the first command line argument 
	std::ifstream fin;     
	fin.open(argv[1]); 

	if (!fin.is_open()) {
		std::cerr << "File is not open" << std::endl;
		exit(4); //Randomly created error code
	}


	// declare an STL container to hold the entries on file
	std::vector<w7::iProduct*> products;

	// read each record and move it to the container - catch any exception
	while (fin.good())
		products.push_back(w7::readProduct(fin));
	

	// total the product prices including any taxes
	double total = 0.0;
	auto p = products.begin();
	while (p < products.end()) 
		total += (*p++)->getPrice();
	

	std::cout << "\nProduct No     Price Taxable\n";
	std::cout << std::fixed << std::setprecision(2);
	
	// retrieve the price for each product in turn
	p = products.begin();
	while (p < products.end()) 
		std::cout << **p++;
	

	// display total
	std::cout << "     Total";
	std::cout << std::setw(10) << total << std::endl;

	std::cout << "\nPress any key to continue ... ";
	std::cin.get();
}