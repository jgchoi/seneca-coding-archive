// Workshop 3 - Copy and Move Semantics
// w3.cpp

 #include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <ctime>
 #include "DArray2d.h"

 #define TIME(start, end) double((end) - (start)) / CLOCKS_PER_SEC

 int main (int argc, char* argv[]) {
     std::cout << "\nCommand Line : ";
     for (int i = 0; i < argc; i++) {
         std::cout << argv[i] << ' ';
     }
     std::cout << std::endl;
     if (argc != 3) {
         std::cerr << "\nIncorrect number of arguments\n";
         return 1;
     }
     std::clock_t cs, ce;
     int nr = std::atoi(argv[1]);
     int nc = std::atoi(argv[2]);
     {
         std::cout << std::fixed << std::setprecision(3);
         cs = std::clock();
         w3::DArray2d a;
         ce = std::clock();
         std::cout << "Constructor     " << TIME(cs, ce) << " seconds";
         std::cout << " - a.check = " << a.check() << std::endl;

         cs = std::clock();
         w3::DArray2d b(nr, nc);
         ce = std::clock();
         std::cout << "Constructor     " << TIME(cs, ce) << " seconds";
         std::cout << " - a.check = " << a.check();
         std::cout << " - b.check = " << b.check() << std::endl;

         cs = std::clock();
         a = b;
         ce = std::clock();
         std::cout << "Copy Assignment " << TIME(cs, ce) << " seconds";
         std::cout << " - a.check = " << a.check();
         std::cout << " - b.check = " << b.check() << std::endl;

         cs = std::clock();
         a = std::move(b);
         ce = std::clock();
         std::cout << "Move Assignment " << TIME(cs, ce) << " seconds";
         std::cout << " - a.check = " << a.check();
         std::cout << " - b.check = " << b.check() << std::endl;

         cs = std::clock();
         a = w3::DArray2d(nr, nc);
         ce = std::clock();
         std::cout << "Move Assignment " << TIME(cs, ce) << " seconds"; 
         std::cout << " - a.check = " << a.check();
         std::cout << " - b.check = " << b.check() << std::endl;

         cs = std::clock();
     }
     ce = std::clock();
     std::cout << "Destructor      " << TIME(cs, ce) << " seconds\n";
 }