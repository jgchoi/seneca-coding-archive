//Item.h
//
class Item {
	int num;
	double price;
	
	public:
	
		Item();
		Item(int, double);
		bool empty() const;
		void operator=(double p);
		void display(std::ostream & os) const ;
		

};

std::istream  & operator >> (std::istream & is, Item & i);
std::ostream  & operator <<  (std::ostream & os, const Item & i);