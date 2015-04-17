//CString.cpp

#include "CString.h"

namespace w1{
int numberOfChar = MAX; //No use in the function. Required specification.

	CString::CString(char *str){
		int i;
		for (i = 0; i < MAX; i++){
			//in case of getting '\0' 
			if(str[0]=='\0'){
				newStr[0]='\0';
				i = MAX;
			}
			newStr[i] = str[i];
		}
		newStr[i] = '\0';

	}


	void CString::display(std::ostream & os) const{
		os << newStr;
	}
	
	
	
	std::ostream & operator<<(std::ostream& os, const CString& cstring){
		static int callCounter = 0;
		os << callCounter << ": ";
		cstring.display(os);
		callCounter++;
		return os;
	}
}
