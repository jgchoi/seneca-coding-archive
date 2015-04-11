// w4.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "CreditCard.h"

int main() {
     CreditCard card(4510516545457780, "John Doe"), empty;
     double x;
     char option;

     do {
         cout << "Select (C, P or Q) : ";
         cin >> option;
         switch (option) {
         case 'C':
         case 'c':
             cout << "Charge : ";
             cin >> x;
             card.charge(x);
             break;
         case 'P':
         case 'p':
             cout << "Payment : ";
             cin >> x;
             card.pay(x);
             break;
         }
     } while (option != 'Q' && option != 'q');

     cout << "Number  " << card.number()  << endl;
     cout << "Name    " << card.name()    << endl;
     cout << "Balance " << card.balance() << endl;

     cout << "Number  " << empty.number()  << endl;
     cout << "Name    " << empty.name()    << endl;
     cout << "Balance " << empty.balance() << endl;
 }