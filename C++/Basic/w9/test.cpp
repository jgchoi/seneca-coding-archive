 // Workshop 9 - Chocolate Tests
 // w9.tests.cpp


 #include "Chocolate.h"

 int main() {
     iFood* food;

     food = new Chocolate(10);
     iFoodTests(food);
     delete food;

     food = new DeluxeChocolate(
   12,"marzipan");
     iFoodTests(food);
    delete food;
 }