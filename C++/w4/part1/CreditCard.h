//CreditCard.h
//
class CreditCard {
	long long int cardNum;
	char cardHolder[21];
	double bal;
	
	public : 
		//constructors
		CreditCard();
		CreditCard(long long int num, char * name);
		
		//memberfunctions
		void charge(double c);
		void pay(double p);
		long long number() const;
		double balance() const;
		const char * name() const;
		};
		