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
	};