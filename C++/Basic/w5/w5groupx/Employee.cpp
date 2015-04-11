//Employee.cpp
//
#include <new>
#include <cstring>
#include <iostream>
#include <iomanip>

#include "Employee.h"

using namespace std;

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
