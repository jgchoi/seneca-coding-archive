#ifndef _CARTOON_H_
#define _CARTOON_H_
#include "Object.h"
	class Cartoon :public Object{
		std::string type;
		std::string name;
		std::string likes;
	public:
		void set(json::List<json::NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT> & src){
			//assigning values assuming that incomming data is valid
			type = src[0].value();
			name = src[1].value();
			likes = src[2].value();
		}

		const std::string getDSV(char d) const{
			std::string result;
			//create test string
			result = type + d + name + d + likes;
			return result;
		}

		void display(std::ostream& os) const{
			os << "type " << type << std::endl;
			os << "name " << name << std::endl;
			os << "likes " << likes << std::endl;
		}
	};

	//non-member helper function
	std::ostream& operator<<(std::ostream& os, const Cartoon& src){
		src.display(os);
		return os;
	}

	

#endif