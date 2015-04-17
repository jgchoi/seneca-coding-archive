#include "Product.h"
#include <iomanip>
#include <string>
namespace w7{
	//static class variable
	double TaxableProduct::tax_rate[2]={1.13, 1.08};

	std::ostream & operator<<(std::ostream& os, const iProduct& p){
		p.display(os);
		os << std::endl;
		return os;
	}

	iProduct* readProduct(std::ifstream& fin){
		//variables
		std::string product_no;
		std::string tmp = "";
		double product_price;
		char tax_type;
		std::string buffer;
		iProduct * product;
		
		//Read one line
		std::getline(fin, buffer, '\n');
		
		//Gathering string information
		int length = buffer.length();
		int pos_first_space = buffer.find_first_of(" ");
		int pos_second_space = buffer.find_last_of(" ");
		
		//Check if it has tax type
		if (pos_first_space != pos_second_space)	{
			product_no = buffer.substr(0, pos_first_space);
			product_price = std::stof(buffer.substr(pos_first_space + 1, pos_second_space - pos_first_space));
			tax_type = buffer.substr(pos_second_space + 1)[0];
		}
		else {
			//No tax type exist
			product_no = buffer.substr(0, pos_first_space);
			product_price = std::stof(buffer.substr(pos_first_space + 1));
		}

		try {
			if (pos_first_space != pos_second_space)
				product = new w7::TaxableProduct(product_no, product_price, tax_type);
			else
				product = new w7::Product(product_no, product_price);

			return product;
		}
		catch (const char tax_type) {
			//if type is not one of H/P
			std::cout << "\"" << tax_type << "\" : Wrong tax type found!" << std::endl;
			//terminate the program with error code 2
			exit(2);
		}
	}
	
	Product::Product(std::string n, double p){
		product_no = n;
		product_price = p;
	}

	double Product::getPrice() const{
		return product_price;
	}
	
	double TaxableProduct::getPrice() const{
		double total;
		if (tax_type == HST)
			total = Product::getPrice()*tax_rate[HST];
		else if (tax_type == PST)
			total = Product::getPrice()*tax_rate[PST];
		return total;
	}

	void Product::display(std::ostream & os) const{
			std::string out;
			os << std::setw(10) << product_no.c_str() << std::setw(10) << product_price;
	}



	TaxableProduct::TaxableProduct(std::string n, double p, char t) :Product(n, p){
		
		if (t != 'H' && t != 'P'){
			throw t;
		}
		else{
			if(t=='H')
			tax_type = HST;
			if(t=='P')
			tax_type = PST;
		}		
	}

	void TaxableProduct::display(std::ostream & os) const{
		Product::display(os);
		if (tax_type == HST)
			os << " HST";
		else if (tax_type == PST)
			os << " PST";
	}

}