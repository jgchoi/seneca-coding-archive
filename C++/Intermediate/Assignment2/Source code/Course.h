#ifndef _COURSE_H_
#define _COURSE_H_
#include "Object.h"


class Course :public Object{
	std::string Name;
	std::string CPA;
	std::string BSD;
public:
	void set(json::List<json::NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT> & src){
		//assigning values assuming that incomming data is valid
		Name = src[0].value();
		CPA = src[1].value();
		BSD = src[2].value();
	}

	const std::string getDSV(char d) const{
		std::string result;
		result = Name +d + CPA + d + BSD;
		return result;
	}
	void display(std::ostream & os)const{
		os << "Name " << Name << std::endl;
		os << "CPA " << CPA << std::endl;
		os << "BSD " << BSD << std::endl;
	}
};

std::ostream& operator<<(std::ostream& os, const Course& src){
	src.display(os);
	return os;
}
#endif