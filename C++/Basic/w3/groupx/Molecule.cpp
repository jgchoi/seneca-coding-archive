// Workshop 3 - Molecules
// Molecule.cpp
 
 #include <iostream>
 #include <cstring>
 #include <iomanip>
 using namespace std;
 #include "Molecule.h"
		
void Molecule::set(const char* s, const char* d, double w)
{
	strcpy (symbol,s);
	strcpy (description,d);
	weight=w;
}

void Molecule::display() const
{
	cout << setw(20) << left << symbol << setw(20) << left << description;
	cout << fixed << setw(10) << right << setprecision(3) << weight;
}
