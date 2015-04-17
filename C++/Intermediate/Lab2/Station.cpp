#include "Station.h"

Station::Station(){
	stationName ="\0";
	stuPass = 0u;
	aduPass = 0u;
}


void Station::set(const std::string& str, unsigned int stu, unsigned int adu){
	stationName = str;
	stuPass = stu;
	aduPass = adu;
}


void Station::update(PassType passtype, int change){
	if(passtype == Adult)
		aduPass = aduPass + change;
	else
		stuPass = stuPass + change;
}

unsigned int Station::inStock(PassType passtype) const{ 
	if(passtype == Adult)
		return aduPass;
	else
		return stuPass;
}

const std::string & Station::getName() const{
	return stationName;
}