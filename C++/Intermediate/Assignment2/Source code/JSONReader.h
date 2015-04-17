#ifndef _JSON_READER_H_
#define _JSON_READER_H_

// Assignment 2 - Type-Safe List - JSON Reader
// OOP345 BTP305 143
// JSONReader.h
// Mark Fernandes, Chris Szalwinski

#include "Object.h"
#define OBJECTS_PER_JSON_FILE 10 //Maximum number of object in example file is less than 10
#define DATA_MEMBERS_PER_OBJECT 3 //Each object has 3 data member
namespace json {

	enum JSON_TYPE {
		UNKNOWN, EMPTY, ARRAY_OPEN, ARRAY_CLOSE, OBJECT_OPEN, OBJECT_CLOSE, NV_PAIR
	};

	std::string trim(const std::string& str);
	std::string trim(const std::string& str, char c);
	std::string getName(const std::string& str);
	std::string getValue(const std::string& str);
	JSON_TYPE get_json_type(std::string s);

	template<typename T>
	List <T, OBJECTS_PER_JSON_FILE>* deserializeJSON(std::string filename, T obj, bool debug) {

		//
		// -- asking students to write this code might be too much --
		// -- but would be great assignment if we did --
		//
		std::ifstream fin(filename);
		if (fin.fail())
			throw std::string("Couldn't open: " + filename);

		std::string fline, line, n, v;
		bool done = false;

		auto list = new List <T, OBJECTS_PER_JSON_FILE>();
		auto members = new List <NVPair <std::string, std::string>, DATA_MEMBERS_PER_OBJECT>();

		if (debug)
			std::cout << "File Contents :\n";
		while (!fin.eof() && !done){

			std::getline(fin, fline);
			if (debug)
				std::cout << fline << std::endl;
			line = trim(fline);

			switch (get_json_type(line)){

			case UNKNOWN:
			case EMPTY:
			case ARRAY_CLOSE:
				done = true;
				break;

			case ARRAY_OPEN:
				if (list == nullptr) throw std::string("List is not initialized");
				break;

			case OBJECT_OPEN:
				if (list->size() == OBJECTS_PER_JSON_FILE)
					throw std::string("List is full");

				if (members == nullptr)
					members = new List <NVPair <std::string, std::string>, DATA_MEMBERS_PER_OBJECT>();
				break;

			case OBJECT_CLOSE:
				obj.set(*members);
				(*list) += obj;
				delete members;
				members = nullptr;
				break;

			case NV_PAIR:
				n = trim(trim(getName(line)), '"');
				v = trim(trim(getValue(line)), '"');
				*members += NVPair<std::string, std::string>(n, v);
				break;

			default:
				done = true;
				break;
			}
		}
		if (debug) std::cout << std::endl;
		return list;
	}

	// readJSON() de-serializes 'jsonFile' into 'list', accumulates the data values
	// for each element in the list into a string, and returns a copy of that string.
	// This function reports any thrown exception that is of type string.
	// 'debug' turns on intermediate debugging output
	// 'delimiter' holds the character that separates the values for the data members
	// in each object in the list
	//
	template<typename T>
	std::string readJSON(std::string jsonFile, T& object, bool debug = false, char delimiter = ',') {
		std::string string_of_values;
		try {

			auto list = json::deserializeJSON(jsonFile, object, debug);

			std::cout << "De-Serialized List :" << std::endl;
			for (unsigned int i = 0; i < list->size(); i++) {
				auto element = (*list)[i];
				std::cout << element << "\n";
				string_of_values += element.getDSV(delimiter) + "\n";
			}

			// responsibility of freeing list lies with the client
			delete list;
			list = nullptr;
		}
		catch (const std::string& err){
			std::cerr << err << "\n";
		}

		if (debug)
			std::cout << "Delimiter Separated Values : \n" << string_of_values << std::endl;
		return string_of_values;
	}
}

#endif
