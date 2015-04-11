#ifndef _CLASS_H_
#define _CLASS_H_
class protocol{
	struct header{
		unsigned char ID : 4;
		unsigned char Count : 4;
		unsigned char flag1 : 1;
		unsigned char flag2 : 1;
		unsigned char flag3 : 1;
		unsigned char flag4 : 1;
		unsigned char : 4;
	} header_str;
	int * data;
	int size;
public:
	protocol(int size_arg);
	~protocol();
	void display_header() const;

	friend void set_data_items(protocol & protocoal_obj);
	friend void display_data_items(protocol & protocoal_obj);
};

#endif