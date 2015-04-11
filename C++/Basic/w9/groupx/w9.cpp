 // Workshop 9 - Pizza
 // w9.cpp

 #include <iostream>
 #include "Pizza.h"

 int main() {
     iFood* food;

     food = new Pizza(14.0, 8);

     for (int i = 0; i < 4; i++)
         food->consume();
     food->display();
     std::cout << std::endl;

     delete food;
		
	
     food = new DeluxePizza(12.0, 6, "mushrooms, peppers");

     for (int i = 0; i < 3; i++)
         food->consume();
     food->display();
     std::cout << std::endl;

     delete food;
 }