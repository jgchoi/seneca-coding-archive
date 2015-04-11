// Bookstore Order Processor
// OOP244.141 - Assignment 3
// a3main.cpp
// Version 1.0
// Chris Szalwinski
// Nov 15 2013

#include <cstdio>
#include <iostream>
#include "GS1Prefix.h"
#include "Order.h"

#define MAXORDERS 100
char menu(std::istream& is);
bool style(std::istream&, char&);

int main() {
    char choice;
    int noOrders = 0;
    Order* order[MAXORDERS];
    Prefix prefix("prefixRanges.txt");

    std::cout << "Bookstore Order Processor\n"
              << "=========================\n";

    // process user input
    do {
        choice = menu(std::cin);
        std::cout << std::endl;
        switch(choice) {
            case 'P':
                {
                    EAN ean;
                    if (ean.read(std::cin, prefix)) {
                        int index = -1, created = false;
                        for (int i = 0; i < noOrders && index == -1; i++)
                            if (ean == order[i]->getEAN())
                                index = i;
                        if (index == -1)
                            if (noOrders < MAXORDERS) {
                                index = noOrders;
                                order[noOrders++] = new Order(ean);
                                created = true;
                            }
                            else
                                std::cerr << "No space for more orders!" << std::endl;
                        if(!order[index]->add(std::cin) && created)
                            delete order[--noOrders];
                    }
                }
                break;
            case 'A':
                {
                    EAN ean;
                    if (ean.read(std::cin, prefix)) {
                        int index = -1;
                        for (int i = 0; i < noOrders && index == -1; i++)
                            if (ean == order[i]->getEAN())
                                index = i;
                        if (index != -1)
                            order[index]->add(1);
                        else {
                            std::cerr << "No order for " << ean;
                            std::cerr << " found!" << std::endl;
                        }
                    }
                }
                break;
            case 'D':
                {
                    EAN ean;
                    if (ean.read(std::cin, prefix)) {
                        int index = -1;
                        for (int i = 0; i < noOrders && index == -1; i++)
                            if (ean == order[i]->getEAN())
                                index = i;
                        if (index != -1)
                            order[index]->receive(std::cin);
                        else {
                            std::cerr << "No order for " << ean;
                            std::cerr << " found!" << std::endl;
                        }
                    }
                }
                break;
            case 'F':
                {
					char s;
					if (style(std::cin, s))
                    for (int i = 0; i < noOrders; i++)
						order[i]->getEAN().style(s);
                }
                break;
            case 'V':
                std::cout << "              EAN  Ordered  Delivered\n";
                std::cout << "-------------------------------------\n";
                for (int i = 0; i < noOrders; i++)
                    std::cout << *order[i] << std::endl;
                break;
        }
    } while (choice != 'Q');

    std::cout << "\nSigning off ... " << std::endl;
    // deallocate order memory
    for (int i = 0; i < noOrders; i++)
        delete order[i];
}

// menu prompts for and accepts an option selection from standard input and
// returns the character identifying the selected option
//
char menu(std::istream& is) {
    char c;
    int  ok = false;

    std::cout << '\n';
    std::cout << "Please select from the following options :\n";
    std::cout << " P - Place an order with a publisher\n";
    std::cout << " A - Add one copy to an existing order\n";
    std::cout << " D - Record a delivery from a publisher\n";
	std::cout << " F - Change output style\n";
    std::cout << " V - View status of books on order\n";
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
        } else if (c != 'P' && c != 'A' && c != 'D' && c != 'V'
         && c != 'Q' && c != 'F') {
            is.ignore(2000, '\n');
            std::cerr << " Invalid Character.  Try again." << std::endl;
        } else if (is.get() != '\n') {
            is.ignore(2000, '\n');
            std::cerr << " Trailing Characters.  Try Again. " << std::endl;
        } else if (c == 'P' || c == 'A' || c == 'D' || c == 'V'
         || c == 'Q' || c == 'F')
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