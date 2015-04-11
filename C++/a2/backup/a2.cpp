// Bookstore Order Processor
// OOP244.141 - Assignment 2
// a2main.cpp
// Version 1.0
// Chris Szalwinski
// Nov 16 2013

#include <iostream>
#include "GS1Prefix.h"
#include "EAN.h"

#define MAX_EAN 100
char menu(std::istream& is);
bool style(std::istream& is, char& s);

int main() {
    int no = 0;
    char s, choice;
    Prefix prefix("prefixRanges.txt");
    EAN ean[MAX_EAN];

    std::cout << "EAN Processor\n"
              << "=============\n";

    // process user input
    do {
        choice = menu(std::cin);
        std::cout << std::endl;
        switch(choice) {
            case 'A':
                {
                    EAN temp;
                    if (temp.read(std::cin, prefix))
                        if (no < MAX_EAN)
                            ean[no++] = temp;
                        else
                            std::cerr << "** No space for more EANs!" << std::endl;
                    else
                        std::cerr << "** No EAN added!" << std::endl;
                }
                break;
            case 'V':
                std::cout << "              EAN\n";
                std::cout << "-----------------\n";
                for (int i = 0; i < no; i++) {
                    if (!ean[i].empty()) {
                        ean[i].display(std::cout);
                        std::cout << std::endl;
                    }
                }
                break;
            case 'F':
                if (style(std::cin, s))
					for (int i = 0; i < no; i++)
						ean[i].style(s);
                break;
        }
    } while (choice != 'Q');

    return 0;
}

// menu prompts for and accepts an option selection from standard input and
// returns the character identifying the selected option
//
char menu(std::istream& is) {
    char c;
    int  ok = false;

    std::cout << '\n';
    std::cout << "Please select from the following options :\n";
    std::cout << " A - Add an EAN\n";
    std::cout << " F - Change output style\n";
    std::cout << " V - View all EANs\n";
    std::cout << " Q - Quit\n";
    do {
        std::cout << " Your selection : ";
        c = ' ';
        is.get(c);
        if (c >= 'a' && c <= 'z')
            c -= 'a' - 'A';
        if (is.fail()) {
            is.clear();
            is.ignore(2000, '\n');
            std::cerr << " Invalid input.  Try again." << std::endl;
        } else if (c == '\n') {
            ; // no input - try again
        } else if (c != 'A' && c != 'V' && c != 'F' && c != 'Q') {
            is.ignore(2000, '\n');
            std::cerr << " Invalid Character.  Try again." << std::endl;
        } else if (is.get() != '\n') {
            is.ignore(2000, '\n');
            std::cerr << " Trailing Characters.  Try Again. " << std::endl;
        } else if (c == 'A' || c == 'V' || c == 'F' || c == 'Q')
            ok = true;
    } while (ok == 0);

    return c;
}

// style prompts for and accepts the style from input stream is
//
bool style(std::istream& is, char& s) {
	bool rc = false, ok = false;
	char c;
	do {
		std::cout << " EAN Style ('-', ' ', '\\n' or '0' to quit) : ";
		c = ' ';
		is.get(c);
		if (is.fail()) {
			is.clear();
			is.ignore(2000, '\n');
			std::cerr << " Invalid input. Try again.\n";
        } else if (c != '-' && c != ' ' && c != '\n' && c != '0') {
            is.ignore(2000, '\n');
            std::cerr << " Invalid Character.  Try again.\n";
		} else if (c == '0') {
			if (is.get() != '\n') {
				is.ignore(2000, '\n');
				std::cerr << " Trailing Characters.  Try Again.\n";
			} else
				ok = true;
		} else if (c == '\n') {
			ok = true;
			s = '\0';
			rc = true;
        } else if (is.get() != '\n') {
            is.ignore(2000, '\n');
            std::cerr << " Trailing Characters.  Try Again.\n";
        } else if (c == '-' || c == ' ') {
            ok = true;
			s = c;
			rc = true;
		}
	} while (!ok);

	return rc;
}