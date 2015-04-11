//Order.h
//
#include "EAN.h"

class Order {

	EAN book;
	int ordered;
	int delivered;
	
	public:
		Order();
		Order(const EAN & ean);
		EAN & getEAN();
		int outstanding() const;
		bool add(std::istream& is);
		bool add(int n);
		bool receive(std::istream & is);
		void display(std::ostream & os) const;
		friend std::ostream & operator<<(std::ostream & os, const Order & order);

};
