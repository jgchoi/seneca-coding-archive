// Workshop 3 - Molecules with Robust validation function
// w3.cpp
 #include <istream>
 #include <iostream>
 using namespace std;
 #include "Molecule.h"

 int main() {
     int n;


	Molecule* molecule;

     cout << "Molecular Information\n";
     cout << "=====================" << endl;

     cout << "Number of Molecules : ";
     cin >> n;

    molecule = new Molecule[n+1]; //edited
     
     for (int i = 0; i < n; i++) {
         char symbol[21];
         char description[21];
         double weight;
		cin.ignore();
         cout << "Enter structure	:";
		cin.getline(symbol, 20, '\n');
		 cout << "Enter full name	:";
		 cin.getline(description,20,'\n');
		 cout << "Enter weight	:";
		 cin >> weight;
         molecule[i].set(symbol, description, weight);
     }
     cout << endl;

     cout << "Structure            Name                     Mass\n";
     cout << "==================================================" << endl; 

     for (int i = 0; i < n; i++) {
         molecule[i].display();
         cout << endl;
     }

     delete [] molecule;
 }
