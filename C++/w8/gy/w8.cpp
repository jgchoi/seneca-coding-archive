 // Workshop 8 - Derived Classes
 // w8.cpp

 #include <iostream>
 #include "Phone.h"

 const int MAX_NO = 20;

 int main() {
     int  n = 0, country, code, local;
     IntlPhone phone[MAX_NO];

     std::cout << "Telephone List\n";
     std::cout << "==============\n";
     do {
         std::cout << "Country   : ";
         std::cin >> country;
         if (country != 0) {
             std::cout << "Area Code : ";
             std::cin >> code;
             std::cout << "Local No. : ";
             std::cin >> local;
             IntlPhone temp(country, code, local);
             if (temp.isValid())
                 phone[n++] = temp;
         }
     } while (country != 0 && n < MAX_NO);
     std::cout << std::endl;

     for (int i = 0; i < n; i++) {
         phone[i].display();
         std::cout << std::endl;
     }
 }