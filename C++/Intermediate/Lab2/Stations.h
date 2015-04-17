#include "Station.h"

namespace w2{
	class Stations {
		std::string fileName;
		int numStation;
		Station *station;

	public:
		Stations(char *str);
		~Stations();
		void update() const;
		void restock() const;
		void report() const;
	};
}