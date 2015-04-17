#ifndef _CLASS_H_
#define _CLASS_H_
class Data{
	//Haeder
	struct Header{
		//bit fields
		unsigned char ID : 4;
		unsigned char Count : 4;
		unsigned char Flag1 : 1;
		unsigned char Flag2 : 1;
		unsigned char Flag3 : 1;
		unsigned char Flag4 : 1;

		//padding 2 byte = 16 bit, 4 bits needed
		unsigned char : 4;
	} header;

	//member function
public:
	Data();
	~Data(){};
	void Display() const;
	void SetID(const char* );
	void SetCount(const char* );
	void SetFlag1(const char *);
	void SetFlag2(const char *);
	void SetFlag3(const char *);
	void SetFlag4(const char *);

	//friend funcition
	friend void DisplayHex(Data);
};

#endif