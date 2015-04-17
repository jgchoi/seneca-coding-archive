#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>

enum PassType {Student, Adult};

class Station {
	std::string stationName;
	unsigned int stuPass;
	unsigned int aduPass;
	
	public:
		Station();
		void set(const std::string& str, unsigned int stu, unsigned int adu);
		void update(PassType passtype, int change);
		unsigned int inStock(PassType passtype) const;
		const std::string & getName() const;
};