//JSONReader.h
//

#ifndef JSONReader_H
	#define JSONReader_H
	#define MAX_NAME_VALUE 50    // maximum number of collections in a JSON file
	
	#include <fstream>
	#include <iostream>
	#include <string>
	#include <iomanip>
	
		namespace json{
			struct Collection{
				std::string collectionName;
				std::string name[MAX_NAME_VALUE];
				std::string value[MAX_NAME_VALUE];
			};

			int read(const std::string&, std::string*);
			int extract(const std::string* buffer, int, int&, Collection&);
			int print(const Collection&);
		}
#endif