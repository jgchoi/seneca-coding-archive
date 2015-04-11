//Phone.h
//
class Phone {
	int areaCode;
	long long int locanNumber;
	
	public:
		Phone();
		Phone(int, long long int);
		void display(std::ostream& os) const;
		bool isValid() const;
	

};

class IntlPhone: public Phone {
	int countryCode;
	
	public:
		IntlPhone();
		IntlPhone(int, int, long long int);
		
		void display(std::ostream& os) const;
		

};

std::istream& operator>>(std::istream& is, Phone& p);
std::istream& operator>>(std::istream& is, IntlPhone& p);
std::ostream& operator<<(std::ostream& os, const Phone& p);
std::ostream& operator<<(std::ostream& os, const IntlPhone& p);