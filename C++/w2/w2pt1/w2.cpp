#include <iostream>
using namespace std;
#include "Fraction.h"

int main()
	{
	Fraction fraction;
	int num, den;

	cout << "Fraction Simplifier" << endl;
	cout << "===================" << endl;

	cout << "Numerator	: ";
	cin >> num;
	cout << "Denomenator	: ";
	cin >> den;
	cout << endl;

	fraction.set(num, den);
	fraction.display();
	}

