// Workshop 5 - Staff List
// w5.cpp

 #include <iostream>
 using namespace std;
 #include "Employee.h"

 void sort(Employee* employee, int n);

 int main() {
     int no, n = 0;
     Employee employee[MAX_EMPLOYEES];
	bool error, finished;
     cout << "Staff List Processor\n";
     cout << "====================\n";

     do {
         cout << " Employee number (0 to quit) ? ";
         cin >> no;
         error = true;
         if (cin.fail()) {
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
             if (str.length() > 0)
                 employee[n++] = Employee(no, str.c_str());
         }
     } while (no != 0 && n < MAX_EMPLOYEES);
     cout << endl;

     sort(employee, n);

     cout << "        Staff List\n\n";
     cout << " Number    Name\n";
     cout << "------------------------------\n";

     for (int i = 0; i < n; i++) {
         employee[i].display();
         cout << endl;
     }
 }

 // sort sorts the elements of employee[n] in ascending order
 //
 void sort(Employee* employee, int n) {

     int i, j;
     Employee temp;

     for (i = n - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
             if (employee[j].isGreaterThan(employee[j+1])) {
                 temp          = employee[j];
                 employee[j]   = employee[j+1];
                 employee[j+1] = temp;
             }
         }
     }
 }