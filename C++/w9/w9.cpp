 // Workshop 9 - Chocolate
 // w9.cpp

 #include <iostream>
 #include "Chocolate.h"

 int main() {
     iFood* food;

     food = new Chocolate(10);

     for (int i = 0; i < 4; i++)
         food->consume();
     food->display();
     std::cout << std::endl;

     delete food;

     food = new DeluxeChocolate(12,"marzipan");

     for (int i = 0; i < 3; i++)
         food->consume();
     food->display();
     std::cout << std::endl;

     delete food;
 }