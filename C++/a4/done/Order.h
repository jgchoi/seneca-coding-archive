//Order.h
//
#include "EAN.h"

class iOrder{
	public:
		virtual EAN & getEAN()=0;
		virtual bool add(int)=0;
		virtual bool add(std::istream &)=0;
		virtual bool receive(std::istream& is)=0;
		virtual int outstanding() const=0;
		virtual void display(std::ostream&) const=0;
};

class Order:public iOrder {

	EAN book;
	int ordered;
	int delivered;
	
	public:
		//constructors
		Order();
		virtual ~Order(){}
		Order(const EAN & ean);
		Order(const Order & source);

		//virtual ----
		EAN & getEAN();		
		bool add(std::istream& is);
		bool add(int n);
		bool receive(std::istream & is);
		int outstanding() const;
		void display(std::ostream & os) const;
};

class SpecialOrder : public Order {
	char * instruction;
	
	public:		
		SpecialOrder();
		~SpecialOrder();
		SpecialOrder& operator=(const SpecialOrder& source);
		SpecialOrder(const EAN & isbn, const char * instr);
		SpecialOrder(const SpecialOrder & source);
		
		//virtual		
		bool add(std::istream & is);
		void display(std::ostream & os) const;
};

std::ostream & operator<<(std::ostream & os, const iOrder & order);