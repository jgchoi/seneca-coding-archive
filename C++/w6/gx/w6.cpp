// Workshop 6 - Fraction Calculator
// w6.cpp

#include <iostream>
using namespace std;

#include "Fraction.h"

void read(const char* msg, Fraction& f) {
	int num, den;
	cout << "Enter " << msg << endl;
	cout << " Numerator : ";
	cin >> num;
	cout << " Denominator : ";
	cin >> den;
	f = Fraction(num, den);
}

int main() {
	Fraction left, right, result, ref;
	cout << "Fraction Calculator\n";
	cout << "===================\n";

	read("Left Operand : ", left);
	read("Right Operand : ", right);

	cout << "Result : " << endl;
	left.display();
	cout << " + ";
	right.display();
	cout << " = ";
	result = left + right;
	result.display();
	cout << endl;

	read("2nd Right Operand : ", right);

	cout << "Result : " << endl; 
	result.display();
	cout << " += ";
	right.display();
	cout << " => ";
	result += right;
	result.display();
	cout << endl;

	read("Reference : ", ref);
	if (result == ref)
		cout << "Result == Reference" << endl;
	else
		cout << "Result != Reference" << endl; 
}