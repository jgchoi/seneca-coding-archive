//DArray2d.cpp

#include "DArray2d.h"

namespace w3{
	DArray2d::DArray2d(){
		array=nullptr;
		r=0;
		c=0;
	}
	
	DArray2d::DArray2d(int row, int column){
		//set r & c
		r = row;
		c = column;

		//row declare
		array = new double*[r];
		
		//column declare
		for (int i=0 ; i<r ; i++)
			array[i] = new double[c];
		
		//input random values
		for (int i=0; i<r ; i++)
			for (int j=0 ; j<c ; j++)
				array[i][j] = (rand() % (11))==0 ? 0 : (rand() % (11))/10.0;
		
	}
	DArray2d::DArray2d(const DArray2d & src){
		r = src.r;
		c = src.c;

		//row declare
		array = new double*[r];
		
		//column declare
		for (int i=0 ; i<r ; i++)
			array[i] = new double[c];
		
		//input random values
		for (int i=0; i<r ; i++)
			for (int j=0 ; j<c ; j++)
				array[i][j] = src.array[i][j];
	}

	DArray2d & DArray2d::operator=(const DArray2d & src){
		if(this != & src){//check if same
			//remove original assignment if any
			if(array != nullptr){
				for(int i=0; i<r ; i++)
					delete [] array[i];
				delete [] array;
			}
			
			//copy r & c
			r = src.r;
			c = src.c;

			//row declare
			array = new double*[r];
			
			//column declare
			for (int i=0 ; i<r ; i++)
				array[i] = new double[c];
			
			//input random values
			for (int i=0; i<r ; i++)
				for (int j=0 ; j<c ; j++)
					array[i][j] = src.array[i][j];
		}
		return *this;
	}
	DArray2d::DArray2d(DArray2d && src){
		r = src.r;
		c = src.c;

		//row declare
		array = new double*[r];
		
		//column declare
		for (int i=0 ; i<r ; i++)
			array[i] = new double[c];
		
		//input random values
		for (int i=0; i<r ; i++)
			for (int j=0 ; j<c ; j++)
				array[i][j] = src.array[i][j];
		

	}
	
	
	DArray2d & DArray2d::operator=(DArray2d && src){
		if(this != & src){
			//remove original assignment if any
			if(array != nullptr){
				for(int i=0; i<r ; i++)
					delete [] array[i];
				delete [] array;
			}
			
			r = src.r;
			c = src.c;

			//row declare
			array = new double*[r];
			
			//column declare
			for (int i=0 ; i<r ; i++)
				array[i] = new double[c];
			
			//input random values
			for (int i=0; i<r ; i++)
				for (int j=0 ; j<c ; j++)
					array[i][j] = src.array[i][j];
		}
		return *this;
	}



	DArray2d::~DArray2d(){
		for(int i=0; i<r ; i++)
			delete [] array[i];
		delete [] array;
	}
	
	double DArray2d::check() const{
		//variables
		long double s=0;
		int i = 0;
		int j = 0;
		
		if(array==nullptr){ //return 0 if array is empty
			return 0;
		}else{
			for (i=0; i<r ; i++)
				for (j=0 ; j<c ; j++)
				  s = s + array[i][j];//add all up
				 s = s/(i*j);//divide by total number of elements (i * j) to get avg
			return s;
		}
	}

}