#include "w1.h"
#include "getPosInt.h"
 #include <iostream>
 using namespace std;

int getPosInt(int max) {
     int i;
     int keepasking; 
     int keepgoing;
     keepasking = 1;
     do {
         cout << "Enter a positive integer not greater than "
              << max << " : ";
         cin >> i;
         if ( i < 0 || i > max)
             cout << "Your entry is out of range.  Try again." << endl; 
         else
             keepasking = 0;
     } while ( keepasking == 1 );

     return i;
 }
