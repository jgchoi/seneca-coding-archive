// Workshop 5 - Containers
// Messages.h


#ifndef _MESSAGES_H_
#define _MESSAGES_H_
#include "iMessage.h"
#include <string>
namespace w5{

	class Twitter : public iMessage{
		std::string user;
		std::string tweet;
		std::string reply;
	public:
		Twitter(std::ifstream &,char);
		void display(std::ostream&) const;
		iMessage* clone() const;
		bool empty() const;
	};

	class eMail  : public iMessage{
		std::string from;
		std::string to;
		std::string date;
		std::string body;
	public:
		eMail(std::ifstream& is, char recDelim);
		void display(std::ostream&) const;
		iMessage* clone() const;
		bool empty() const;
	};
}	
	#endif

