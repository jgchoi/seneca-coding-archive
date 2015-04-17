#ifndef _I_MESSAGE_H_
#define _I_MESSAGE_H_

// Workshop 5 - Containers
// iMessage.h

#include <iostream>
#include <fstream>

namespace w5 {
	class iMessage {
	public:
		virtual void display(std::ostream&) const = 0;
		virtual iMessage* clone() const = 0;
		virtual bool empty() const = 0;
	};

	iMessage* getMessage(std::ifstream&, char);
}
#endif