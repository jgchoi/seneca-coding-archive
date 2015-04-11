// Assignment 2 - Type-Safe List - Test Main
 // OOP345 BTP305 143
 // ../a2/a2main.cpp
 //
 // Mark Fernandes

 #include <iostream>
 #include <fstream>
 #include <string>
 #include "Identity.h"
 #include "Cartoon.h"
 #include "Course.h"
 #include "JSONReader.h"

 #define DIRECTORY "../data/"  // directory containing the test files

 void clear_screen();

 int main(int argc, char** argv) {

     bool ok = false;

     // set to true for verbose output
     bool debug = true;

     auto data_dir = std::string(DIRECTORY);
     try {
         std::string out;

         // IDENTITY FILES
         Identity e;
         std::cout << "\nList of Identity Objects:\n======================\n"
                   << "Testing with empty files\n------------------------\n";

         out = json::readJSON(data_dir + "a2-empty_object.json", e, debug);
         if (!out.empty())
             throw std::string("FAILED WITH: empty object");

         out = json::readJSON(data_dir + "a2-empty_array.json", e, debug);
         if (!out.empty())
             throw std::string("FAILED WITH: empty array");

         out = json::readJSON(data_dir + "a2-empty_array_with_empty_object.json",
          e, debug);
         if (!out.empty())
             throw std::string("FAILED WITH: empty array containing empty object"); 

         // CARTOON OBJECTS
         Cartoon c;
         std::cout << "\nList of Cartoon Objects:\n========================\n"
                   << "Testing with one item\n---------------------\n";
         out = json::readJSON(data_dir + "a2-cartoon_tom.json", c, debug);
         if ( out != "cat,Tom,mice\n")
             throw std::string("FAILED WITH: one object\n") +
                   std::string("EXPECTED: cat,Tom,mice\n") +
                   std::string("GOT: ") + out;

         out = json::readJSON(data_dir + "a2-cartoon_tom_array.json", c, debug);
         if ( out != "cat,Tom,mice\n")
             throw std::string("FAILED WITH: one object in an array\n") +
                   std::string("EXPECTED:=>cat,Tom,mice\n") +
                   std::string("GOT:=>") + out;

         std::cout << "Testing with multiple items, delimit with |\n"
          "-------------------------------------------\n";
         out = json::readJSON(data_dir + "a2-cartoons.json", c, debug, '|');
         if ( out != "cat|Tom|mice\nmouse|Jerry|cheese\n")
             throw std::string("FAILED WITH: multi-objects in array, "
                   "delimited with |\n")  +
                   std::string("EXPECTED:=>cat|Tom|mice\nmouse|Jerry|cheese\n") +
                   std::string("GOT:=>") + out;

         //  COURSE OBJECTS
         Course crs;
         auto cexp="Game Engine Techniques;GAM532;DPS932\n"\
                   "Data Structures And Algorithms In C++;DSA555;\n"\
                   "Windows Programming Using C#;;DPS910\n";

         std::cout << "\nList of Course Objects:\n=======================\n"
                   << "Testing with multipe items, delimit with ;\n"
                   "------------------------------------------\n";
         out = json::readJSON(data_dir + "a2-courses.json", crs, debug, ';');
         if ( out != cexp)
             throw std::string("FAILED WITH: multi-objects in array, "
                   "delimited with :\n")  +
                   std::string("EXPECTED:=>") + cexp +
                   std::string("GOT:=>") + out;

         // ALL OK
         ok = true;

     }
     catch(const std::string& e){
         std::cerr << e << "\n";
     }

     if (ok)
         std::cout << "CONGRATULATIONS! You passed all tests.\n"
                   << "You may now hand-in your assignment according"
                   " to your professor's instructions.\n";
     return 0;
 }

 // clear display - platform dependent
 //
 void clear_screen() {
 #ifdef _MSC_VER
     system("cls");
 #else
     system("clear");
 #endif
 }