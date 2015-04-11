//Fraction.h group y
//

class Fraction
	{
	int nu;
	int de;
	
	public :
		void set(int n, int d);
		void simplify();
		void display() const;
		int numerator() const;
		int denominator() const;
		
		Fraction();
		Fraction(int, int);
		Fraction & operator+=(const Fraction & f);
		Fraction & operator-=(const Fraction & f);
		Fraction & operator*=(const Fraction & f);
		Fraction & operator/=(const Fraction & f);
		friend bool operator==(const Fraction & a, const Fraction & b);			
	};
Fraction operator+(const Fraction & a, const Fraction & b);