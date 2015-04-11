
 // Workshop 10 - Sort
 // w10.cpp

 #include <iostream>
 #include "sort.h"

 int main() {
     int a[] = {1234, 546, 786, 2341};
    char* c[6] = {"Harry", "Jane", "Anne", "John"};
//		char c[][6]={"Harry", "Jane", "Anne", "John"};
     sort(a, 4);
     sort(c, 4);

    for (int i = 0; i < 4; i++)
         std::cout << a[i] << std::endl;
    std::cout << std::endl;

     for (int i = 0; i < 4; i++)
      std::cout << c[i] << std::endl;
   std::cout << std::endl;
 }