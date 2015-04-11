class Phone {
	int areaCode;
	long long int locanNumber;
	
	public:
		Phone();
		Phone(int, long long int);
		void display() const;
		bool isValid() const;
	

};

class IntlPhone: public Phone {
	int countryCode;
	
	public:
		IntlPhone();
		IntlPhone(int, int, long long int);
		
		void display() const;
};