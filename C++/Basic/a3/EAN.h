//EAN.h
//
class EAN{
	char ean[14];
	char area[8];
	char publisher[8];
	char title[8];
	char s;
	
	bool isRegistered(const Prefix & list);
	
	public:
		EAN();
		EAN(const char * str, const Prefix & list);
		
		bool empty() const;
		bool isRegistered() const;
		void style(char c);
		void toStr(char * str) const;
		void toStrWithStyle(char * str) const;
		void display(std::ostream & os) const;
		bool read(std::istream & is, const Prefix & list);
		
		friend bool operator==(const EAN & left, const EAN & right);
		
};

std::ostream & operator<<(std::ostream& os, const EAN& ean);
bool isValid(const char* str);
	