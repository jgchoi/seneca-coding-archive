#include "iFoodTests.h"

class Chocolate:public iFood{

	int portion;
	int currentPortion;
	
	public:
		Chocolate();
		Chocolate(int b);
		Chocolate(Chocolate & src);
		int portions() const;
		void consume();
		int remaining() const;
		void display() const;
};

class DeluxeChocolate : public Chocolate{
	char toppings[41];
	
	public:
	DeluxeChocolate(DeluxeChocolate & src);
		DeluxeChocolate();
		DeluxeChocolate(int b,const char * c);
		void display() const;
};