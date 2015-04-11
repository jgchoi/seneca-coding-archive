#ifndef _OBJECT_C_
#define _OBJECT_C_
class Object{
	int * buffer;
	struct Status{
		int bufferSize;
		int currentIndex;
	} status;

public:
	Object(int);
	~Object();
	void display() const;
	Object & operator+=(int);
};

#endif