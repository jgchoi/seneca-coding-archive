//Object.h
//
#ifndef _OBJECT_H_
#define _OBJECT_H_
#include "NVPair.h"
#include "List.h"
#include "JSONReader.h"
#define DATA_MEMBERS_PER_OBJECT 3

	class Object{
	public:
		virtual void set(json::List<json::NVPair<std::string, std::string>, DATA_MEMBERS_PER_OBJECT> &) = 0;
		virtual const std::string getDSV(char) const = 0;
	};

#endif