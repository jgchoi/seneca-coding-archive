// Workshop 5 - Containers
// Notifications.h


#ifndef _NOTIFICATIONS_H_
#define _NOTIFICATIONS_H_
#include "iMessage.h"
namespace w5{
	class Notifications{
		iMessage** messages;
		int length;

	public:
		Notifications();
		Notifications(const Notifications &);
		Notifications & operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications && operator=(Notifications&&);
		~Notifications();
		void operator+=(const iMessage&);
		void display(std::ostream&) const;

	};
}	
#endif

