// Workshop 3 - Molecules
// Molecule.cpp
 
 #include <iostream>
 #include <cstring>
 #include <iomanip>
 
 using namespace std;
 
 #include "Molecule.h"
 
// Set value in object
//		
void Molecule::set(const char* s, const char* d, double w)
{
	strcpy (symbol,s);
	strcpy (description,d);
	weight=w;
}

// display value in object
//
void Molecule::display() const
{
	cout << setw(20) << left << symbol << setw(20) << left << description;
	cout << fixed << setw(10) << right << setprecision(3) << weight;
}


//function to take string value and validate and return to main's string.
//
void getString(char* s, int t, int size)
{
	int keepTrying = 0;
	while(keepTrying==0)
		{	//taking input
			if(t == 1 )
			cout << "Enter symbol		: ";
			else if(t==2)
			cout << "Enter description	: ";
			cin.getline(s, size, '\n');

			//validation

			if (cin.fail()) {   // check for invalid character
             cerr << "Invalid character.  Try Again." << endl;
             cin.clear();
             cin.ignore(2000, '\n');
		 } else
             keepTrying = 1;
		}
}
//function to validate int value.
//
int getN()
{
	int keepTrying = 0;
	int weight =0;
	while(keepTrying == 0)
	{
	//input
	cout << "Number of molecule	: ";
	cin >> weight;
	
	//validation
	if(cin.fail())
		{
		cerr << "Invalid character. Try Again." << endl;
		cin.clear();
		cin.ignore(2000, '\n');
		}
	else if (weight <= 0 || weight > 1000)
		{
		cerr << weight << " is outside the range " << endl;
		cerr << "Invalid input. Try again." << endl;
		cin.ignore(2000, '\n');
		}
	else if (char(cin.get()) != '\n')
		{
		cerr << "Trailing characters. Try again." << endl;
		cin.ignore(2000, '\n');
		}
	else // test passed
		keepTrying =1;
	}
	return weight;
}
//function to validate double value.
//
double getWeight()
{
	int keepTrying = 0;
	double weight =0;
	while(keepTrying == 0)
	{
	//input
	cout << "Enter weight		: ";
	cin >> weight;
	
	//validation
	if(cin.fail())
		{
		cerr << "Invalid character. Try Again." << endl;
		cin.clear();
		cin.ignore(2000, '\n');
		}
	else if (weight <= 0 || weight > 1000)
		{
		cerr << weight << " is outside the range " << endl;
		cerr << "Invalid input. Try again." << endl;
		cin.ignore(2000, '\n');
		}
	else if (char(cin.get()) != '\n')
		{
		cerr << "Trailing characters. Try again." << endl;
		cin.ignore(2000, '\n');
		}
	else // test passed
		keepTrying =1;
	}
	return weight;
}