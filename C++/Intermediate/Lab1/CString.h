//CString.h

#ifndef __CSTRING_H__
#define __CSTRING_H__
#include <iostream>
		namespace w1 {
			const int MAX = 3;
			
			class CString{
				char newStr[MAX+1];
				
			public:
				CString(char *str);
				void display(std::ostream & os) const;
			};
			
			std::ostream & operator<<(std::ostream& os, const CString& cstring);
		}
#endif