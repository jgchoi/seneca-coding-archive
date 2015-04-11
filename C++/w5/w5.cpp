// Workshop 5 - Staff List
 // w5.cpp

 #include <iostream>
 using namespace std;
 #include "Employee.h"

 void sort(Employee* employee, int n);

 int main() {
     int n = 0;
     bool more = true;
     Employee employee[MAX_EMPLOYEES];

     cout << "Staff List Processor\n";
     cout << "====================\n";

     do {
         more = employee[n].read();
         if (more) n++;
     } while (more && n < MAX_EMPLOYEES);
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