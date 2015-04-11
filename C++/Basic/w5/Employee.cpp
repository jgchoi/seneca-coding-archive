//Employee.cpp
//
#include <new>
#include <cstring>
#include <iostream>
#include <iomanip>

#include "Employee.h"

using namespace std;

bool Employee::read(){
int no, n = 0;
bool error, finished;

	do{
         cout << " Employee number (0 to quit) ? ";
         cin >> no;
         error = true;
		 
		 if(no == 0)
			{
			return false;
			}
         else if (cin.fail()) {
             cin.ignore(2000, '\n');
             cerr << "Bad character.  Try again." << endl;
             cin.clear();
         }
         if (cin.get() != '\n') {
             cin.ignore(2000, '\n');
             cerr << "Trailing characters.  Try again." << endl; 
         }
         else if (no < 0) {
             cin.ignore(2000, '\n');
             cerr << "Must be positive.  Try again." << endl;
             error = false;
             n++;
             finished = true;
         }
         else if (no != 0) {
             cout << " Employee name ? ";
             string str;
             getline(cin, str);
			 
             if (str.length() > 0){
               	empName = new (nothrow) char[strlen(str.c_str())+1];
				
				if(empName != nullptr)
					{
					strcpy(empName,str.c_str());
					empNum = no;
					}
				return true;
				}
			}
		}while(no!=0);
}

void Employee::display() const{
	cout << setw(8) << left << empNum << empName;
}

bool Employee::isGreaterThan(const Employee & src) const {
	if(strcmp(src.empName,empName)<0)
		return true;
	else
		return false;
}

Employee::Employee(){
	empNum = 0;
	empName = new (nothrow) char[1];
	if(empName != nullptr)
	empName[0] = '\0';
}

Employee::Employee(int a, const char * b){
	empName = new (nothrow) char[strlen(b)+1];
	if(empName != nullptr)
		{
		strcpy(empName,b);
		empNum = a;
		}
}

Employee::~Employee(){
	if(empName != nullptr)
		delete [] empName;
}

Employee::Employee(Employee & src){
	empName = new (nothrow) char[strlen(src.empName)+1];
	if(empName != nullptr)
		{
		strcpy(empName,src.empName);
		empNum = src.empNum;
		}
}

Employee & Employee::operator = (const Employee & src){
	if(this != &src)
		{
		delete [] empName;
		empName = new (nothrow) char[strlen(src.empName)+1];
		if(empName != nullptr)
			{
			strcpy(empName,src.empName);
			empNum = src.empNum;
			}
		
		}
	return *this;
}
