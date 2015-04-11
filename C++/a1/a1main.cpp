#include <iostream>
#include <iomanip>
#include <cstring>

#define  PREFIX_LIST "prefixRanges.txt"
#include "GS1Prefix.h"
#include "EAN.h"

int main() {
    int keepgoing;
    char ean[14];
    Prefix prefix;
    char area[6], publisher[8], title[7];

    std::cout << "EAN Processor\n"
              << "=============\n";

    if (!load(PREFIX_LIST, &prefix))
        std::cerr << "Could not open file " << PREFIX_LIST << std::endl;
    else {
        keepgoing = 1;
        do {
            std::cout << "EAN (0 to quit) : ";
            std::cin.getline(ean, 14);
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(2000, '\n');
                std::cerr << "Error. Try Again " << std::endl;
            }
            else if (std::strcmp(ean, "0") == 0) {
                keepgoing = 0;
            }
            else if (std::strlen(ean) != 13) {
                std::cerr << " Incorrect number of digits. Try again." << std::endl;
            }
            else if (isValid(ean) == 0) {
                std::cerr << " Invalid check digit. Try again." << std::endl;
            }
            else if (isRegistered(&prefix, ean, area, publisher,
             title) == 0) {
                std::cerr << " This EAN does not have a registered prefix."
                 << std::endl;
            }
            else {
                std::cout << " Area           : " << area << std::endl;
                std::cout << " Publisher      : " << publisher << std::endl;
                std::cout << " Title          : " << title << std::endl;
            }
            std::cout << std::endl;
        } while (keepgoing == 1);

        std::cout << "Signing off ... " << std::endl;
    }
}
