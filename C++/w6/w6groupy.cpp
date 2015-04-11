// Workshop 6 - Fraction Calculator
 // w6.cpp

 #include <iostream>
 #include <cstring>
 using namespace std;
 #include "Fraction.h"

 void read(const char* msg, Fraction& f) {
     int num, den;
     cout << "Enter " << msg << endl;
     cout << " Numerator : ";
     cin >> num;
     cout << " Denominator : ";
     cin >> den;
     f = Fraction(num, den);
     cin.ignore();
 }

 int main() {
     char op[3];
     bool quit = false;
     Fraction left, right, result, ref;

     cout << "Fraction Calculator\n";
     cout << "===================\n";

     read("Left Operand : ", left);

     do {
         cout << "+= -= *= /= ## to quit : ";
         cin.get(op, 3);
         char c = cin.get();
         if (c != '\n' ||
          op[1] != '=' && op[1] != '#') {
             cerr << "Try Again!" << endl;
             cin.ignore(2000, '\n');
         }
         else if (strcmp(op, "##") == 0) {
             read("Reference : ", ref);
             quit = true;
         }
         else {
             read("Right Operand : ", right);

             cout << "Result : " << endl; 
             left.display();

             switch (op[0]) {
                 case '+':
                     cout << " += ";
                     left += right;
                     break;
                 case '-':
                     cout << " -= ";
                     left -= right;
                     break;
                 case '*':
                     cout << " *= ";
                     left *= right;
                     break;
                 case '/':
                     cout << " /= ";
                     left /= right;
                     break;
             }
             right.display();
             cout << " => ";
             left.display();
             cout << endl;
         }
     } while (!quit);

     if (left == ref)
         cout << "Result == Reference"
              << endl;
     else
         cout << "Result != Reference"
              << endl;
 }