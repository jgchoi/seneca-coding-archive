// Assignment 2 - Type-Safe List - JSON Reader
// OOP345 BTP305 143
// JSONReader.cpp
// Mark Fernandes, Chris Szalwinski

#include <iostream>
#include <fstream>
#include <string>
#include "JSONReader.h"

namespace json {
	// trim removes leading and trailing spaces
	//  from => "name": "value"
	//  gets => "name"
	std::string trim(const std::string& str) {

		if (str.empty() || str == "\"\"") return std::string();
		else {
			auto beg = str.find_first_not_of(" \t");
			auto end = str.find_last_not_of(" \t");

			if (beg == std::string::npos)       return str;
			else if (end == std::string::npos)  return str.substr(beg);
			else                                return str.substr(beg, end + 1);
		}
	}

	// trim when passed a char removes that char
	std::string trim(const std::string& str, char c) {

		if (str.empty() || str == "\"\"") return std::string();
		else {
			auto beg = str.find_first_not_of(c);
			auto end = str.find_last_not_of(c);

			if (beg == std::string::npos)       return str;
			else if (end == std::string::npos)  return str.substr(beg);
			else                                return str.substr(beg, end);
		}
	}

	// getName extracts name from name-value pair
	//  from => "name": "value"
	//  gets => "name"
	std::string getName(const std::string& str) {

		auto dq = str.find_first_of('"');
		auto c = str.find_first_of(':');

		if (dq == std::string::npos || c == std::string::npos)
			return std::string();
		else
			return str.substr(dq, c - dq);
	}

	// getValue extracts name from name-value pair
	// from => "name": "value"
	// gets => "value"
	std::string getValue(const std::string& str) {

		auto c = str.find_first_of(':');
		auto dq = str.find_last_of('"');

		if (c == std::string::npos || dq == std::string::npos)
			return std::string();
		else
			return str.substr(c + 1, dq - c);
	}

	JSON_TYPE get_json_type(std::string s) {

		// matches would be better handled by regexes, obviously but since
		// we do not teach regexes, we simply assume these will always work
		if (s == "{}" || s == "[]" || s.empty())      return EMPTY;
		if (s == "[")                                  return ARRAY_OPEN;
		if (s == "]")                                  return ARRAY_CLOSE;
		if (s == "{")                                  return OBJECT_OPEN;
		if (s == "}" || s == "},")                     return OBJECT_CLOSE;
		if (s.find_first_of(':') != std::string::npos) return NV_PAIR;

		return UNKNOWN;
	}
}
