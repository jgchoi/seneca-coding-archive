#ifndef _IDENTITY_H_
#define _IDENTITY_H_
#include "Object.h"

	class Identity:public Object{

	public:
		void set(json::List<json::NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT> & src){ ; }
		const std::string getDSV(char c) const{
			std::string empty = "";
			return empty;
		}
	};
	std::ostream& operator<<(std::ostream& os, const Identity& src){
		return os;
	}

#endif