#include "iFood.h"

class Pizza:public iFood{
	double size;
	int portion;
	int currentPortion;
	
	public:
		Pizza();
		Pizza(double a, int b);
		
		int portions() const;
		void consume();
		int remaining() const;
		void display() const;
};

class DeluxePizza : public Pizza{
	char toppings[41];
	
	public:
		DeluxePizza();
		DeluxePizza(double a, int b,const char * c);
		void display() const;
};