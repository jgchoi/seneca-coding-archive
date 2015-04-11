// Workshop 3 - Molecules
// Molecule.h

class Molecule{
	char symbol[20];
	char description[20];
	double weight;
	
	public :
		void set(const char*, const char*, double);
		void display() const;
};

//Robust validation function
void getString(char* s, int t, int size);
double getWeight(); 
int getN();