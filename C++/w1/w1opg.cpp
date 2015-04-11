// Modular Programs - Workshop 1
 // w1.cpp

 #include <iostream>
 using namespace std;
 #define MAX 25

 int getPosInt(int max);

 int main() {
     int i;
     i = getPosInt(MAX);
     cout << "You entered " << i << endl;
 }

 // getPosInt returns a positive integer not greater than max
 //
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
     } while ( keepgoing == 1 );

     return i;
 }
