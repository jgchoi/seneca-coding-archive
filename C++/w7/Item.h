//Item.h
//
class Item {
	int num;
	double price;
	char * desc;
	
	public:
	
		Item();
		Item(int n, double p, char * s);
		~Item();
		bool empty() const;
		void operator=(double p);
		void display(std::ostream & os) const ;
//		Item & operator=(const Item & a);
		friend std::istream  & operator >> (std::istream & is, Item & i);

};


std::ostream  & operator <<  (std::ostream & os, const Item & i);
