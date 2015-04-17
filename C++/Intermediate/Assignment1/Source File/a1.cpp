// Assignment 1 - Naive JSON Parser
// ../a1/main.cpp

#include <iostream>
#include <string>
#include "JSONReader.h"

#define DIRECTORY "../data/"  // directory containing the test files
#define MAX_LINES 50          // maximum number of lines in a JSON file 
#define MAX_COLLECTIONS 50    // maximum number of collections in a JSON file 

void clear_screen();

int main(int argc, char** argv) {

    if (argc == 1) {
        std::cerr << "***Filename(s) missing***\n";
        return 1;
    }

    auto data_dir = std::string(DIRECTORY);

    for (int k = 1; k < argc; k++) {

        std::string buffer[MAX_LINES];
        json::Collection collection[MAX_COLLECTIONS];

        // read file into buffer
        auto no_lines = json::read(data_dir + argv[k], buffer);
        clear_screen();
        if (no_lines == -1) {
            std::cerr << "***" << argv[k] << " not found***\n";
            return 2;
        } else {
            std::cout << "Filename " << argv[k] << " has " << no_lines <<
             " lines in total\n\n";
        }

        // extract collections from buffer
        int  line_no = 1;
        auto no_objects = 0;
        auto no_collections = 0;
        for (int i = 0; i < MAX_COLLECTIONS && line_no < no_lines; i++)
            no_objects += json::extract(buffer, no_lines, line_no,
             collection[no_collections++]);

        // display name-value pairs of each collection
        auto no_nv_pairs = 0;
        for (int i = 0; i < no_collections; i++)
            no_nv_pairs += json::print(collection[i]);

        std::cout << "\nSummary Report\n" <<
         "-----------------------------" << std::endl;
        std::cout << "No of collection(s)      : " << no_collections << std::endl; 
        std::cout << "No of object(s)          : " << no_objects << std::endl;
        std::cout << "No of name-value pair(s) : " << no_nv_pairs << std::endl;

        std::cout << "\nPress any key to continue ... ";
        std::cin.get();
    }
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