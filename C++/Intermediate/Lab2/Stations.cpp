#include "Stations.h"

namespace w2{
	Stations::Stations(char * str){
		int i = 0;
		
		//File connection
		fileName = str;
		std::ifstream fin(fileName.c_str());
		
		//Check if open
		if(!fin.is_open()){
			std::cerr << "*ERROR* Problem occurred to open file: "<< fileName <<"\n";
			exit(1);
		}
		else{
			//Get number of stations
			fin >> numStation;
			fin.ignore();

			//Creating new Station array
			station = new Station[numStation];
			
			//Get station information
			while(i < numStation){
				std::string stationName;
				unsigned int std;
				unsigned int adu;

				std::getline(fin, stationName, ';');
				fin >> std;
				fin >> adu;

				station[i].set(stationName, std, adu);
				i++;
			}
		}

	}
	
	Stations::~Stations(){
		int i = 0;
		
		//File connection
		std::ofstream fout(fileName.c_str());
		
		//Write on file
		fout << numStation << ";";
		
		while(i<numStation){
			fout << station[i].getName() << ";" << station[i].inStock(Student) << " " << station[i].inStock(Adult) ;
			i++;
		}
		
		delete [] station;
		
	}
	
	void Stations::update() const{
		int a, b;
		std::cout << "\nPasses Sold :\n-------------";
		for (int i = 0; i < numStation; i++){
			std::cout << station[i].getName() << std::endl;
			std::cout << "Student Passes sold : ";
			std::cin >> a;
			std::cout << "Adult   Passes sold : ";
			std::cin >> b;
			
			a = a*-1;
			b = b*-1;
			
			station[i].update(Student, a);
			station[i].update(Adult, b);
		}
	}
	void Stations::restock() const{
		int a, b;

		std::cout << "\nPasses Added :\n--------------";
		for (int i = 0; i < numStation; i++){
			std::cout << station[i].getName() << std::endl;
			std::cout << "Student Passes added : ";
			std::cin >> a;
			std::cout << "Adult   Passes added : ";
			std::cin >> b;
			station[i].update(Student, a);
			station[i].update(Adult, b);
		}
	}
	void Stations::report() const{
		std::cout << "\nPasses in Stock : Student Adult\n===============================";
		for (int i = 0; i < numStation; i++){
			std::cout << std::setw(19) << std::left << station[i].getName();
			std::cout << std::setw(7) << std::right << station[i].inStock(Student);
			std::cout << std::setw(6) << station[i].inStock(Adult);
		}
	std::cout << "\n";
	}
}