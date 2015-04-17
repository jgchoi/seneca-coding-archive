
#include "Notifications.h"
namespace w5{
	//default constructor
	Notifications::Notifications(){
		messages = nullptr;
		length = 0;
	}

	//copy constructor
	Notifications::Notifications(const Notifications & src){
		if (src.messages != nullptr){
			//array size
			length = src.length;

			//new array
			messages = new iMessage*[length];

			//copy data
			for (int i = 0; i < length; i++){

				messages[i] = src.messages[i]->clone();
			}
		}
		else
			messages = nullptr;
		
	}

	//copy assignment opr
	Notifications & Notifications::operator=(const Notifications & src){
		//check current object
		if (messages != nullptr)
			delete [] messages;

		//check if this and src same
		if (this != &src){
			//array size
			length = src.length;

			//new array
			messages = new iMessage*[length];

			//copy data
			for (int i = 0; i < length; i++){
				messages[i] = src.messages[i]->clone();
			}
		}

		return *this;
	}

	//move constructor
	Notifications::Notifications(Notifications&& src){
		messages = src.messages;
		length = src.length;
		src.length = 0;
		src.messages = nullptr;
	}

	//Move assignment
	Notifications && Notifications::operator=(Notifications && src){
		if (messages != nullptr)
			delete[] messages;

		//check if this and src same
		if (this != &src){
			messages = src.messages;
			length = src.length;
			src.length = 0;
			src.messages = nullptr;
		}
		return std::move(*this);
	}

	//destructor
	Notifications::~Notifications(){
		if (messages != nullptr)
			delete[] messages;
	}
	
	//add iMessage
	void Notifications::operator+=(const iMessage & im){
		if (messages == nullptr){
			//new object. insert first one
			messages = new iMessage*[1];
			messages[0] = im.clone();
			length = 1;
		}
		else{					
			//copy to tmp
			Notifications temp(*this);

			//delete current
			if (messages != nullptr)
			{
				delete[] messages;
				messages = nullptr;
			}

			//create new

			//new array
			messages = new iMessage*[length + 1];

			//copy
			int i;
			for (i = 0; i < length; i++){
				messages[i] = temp.messages[i]->clone();
				temp.messages[i] = nullptr;
			}

			//add new
			length++;
			messages[i] = im.clone();
		}
	
	}

	//display
	void Notifications::display(std::ostream & os) const{
		
		int i=0;
		if (messages != nullptr){
			for (i = 0; i < length; i++){
				messages[i]->display(os);
			}
		}
	}
}