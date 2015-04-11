 // Workshop 8 - Derived Classes
 // w8.cpp

 #include <iostream>
 #include "Phone.h"

 const int MAX_NO = 20;

 int main() {
     int  n = 0, country, code, local;
     IntlPhone temp, phone[MAX_NO];

     std::cout << "Telephone List\n";
     std::cout << "==============\n";
     do {
         std::cin >> temp;
         if (temp.isValid())
             phone[n++] = temp;
     } while (temp.isValid() && n < MAX_NO);
     std::cout << std::endl;

     for (int i = 0; i < n; i++)
         std::cout << phone[i] << std::endl;
 }