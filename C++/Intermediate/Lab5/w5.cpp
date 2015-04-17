// Workshop 5 - Containers
// w5.cpp

#include <iostream>
#include <fstream>
#include "iMessage.h"
#include "Notifications.h"

const char REC_DELIMITER = '\n';

w5::Notifications collect(std::ifstream& in, char recDelim) {
	w5::Notifications notifications;
	w5::iMessage* message;

	do {
		message = w5::getMessage(in, recDelim);
		if (in && message && !message->empty())
			notifications += std::move(*message);
	} while (in);

	return notifications;
}

int main(int argc, char* argv[]) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}

	std::cout << "\nNotifications\n=============\n\n";
	w5::Notifications notifications = collect(file, REC_DELIMITER);
	
	notifications.display(std::cout);

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}