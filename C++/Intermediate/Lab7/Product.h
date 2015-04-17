#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include "iProduct.h"

	namespace w7{
		class Product :public iProduct {
			std::string product_no;
			double product_price;

		public:
	
			Product(std::string, double);
			double getPrice() const;
			void display(std::ostream &) const;
		};

		class TaxableProduct :public Product{
			enum {HST, PST} tax_type;
			static double tax_rate[2];
		public:
			double getPrice() const;
			TaxableProduct(std::string, double, char);
			void display(std::ostream &) const;
		};
	}
#endif