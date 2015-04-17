#include <iostream>
#include <thread>
#include <fstream>

//show the status of T1
enum Status { wait, go };
static Status status = wait;

void RunT1()
{
	int matrixA[5][5];
	int matrixB[5][5];
	int matrixC[5][5];

	//TODO:  Print out the threads unique ID here
	std::cout << "Thread id of RunT1 = " <<
	std::this_thread::get_id() << std::endl;

	//load the matrix data
	std::ifstream infile("matrixa_input.txt");
	std::ifstream infile2("matrixb_input.txt");
	
	//check file opening
	if (!infile || !infile2){
		std::cout << "Error opening file.";
		exit(2);
	}

	//TODO:  Read the data from the open input files into matrixa and matrixb
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			infile >> matrixA[i][j];
			infile2 >> matrixB[i][j];
		}
	}
	
	infile.close();
	infile2.close();

	//TODO:  Perform the matrix multiplication here
	//REFERENCE:  http ://www.cplusplus.com/forum/beginner/100491/
	for (int i = 0; i < 5; i++){
		for (int j = 0; j<5; j++){
			matrixC[i][j] = 0;
			for (int k = 0; k<5; k++){
				matrixC[i][j] = matrixC[i][j] + (matrixA[i][k] * matrixB[k][j]);
			}
		}
	}

	std::cout << "your matrix is" << std::endl;

	//TODO:  Print out the resulting matrixC 2D array to the screen
	for (int i = 0; i<5; i++){
		for (int j = 0; j<5; j++)
			std::cout << matrixC[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl;
	
	//let T2 run display section
	status = go;
}

void RunT2(std::string inputfile)
{
	char *Buffer;
	
	//TODO:  create an ifstream infile to read the binary file inputfile
	std::ifstream infile(inputfile, std::ios::binary);

	//get size of the file
	infile.seekg(0, infile.end);
	long size = infile.tellg();
	infile.seekg(0);

	//Allocate buffer space
	Buffer = new char[size];

	//TODO:  Read the data from the binary file
	//REFERENCE:  http ://www.cplusplus.com/reference/ostream/ostream/write/
	char * buffer = new char[size];
	infile.read(buffer,size);

	//Wait for T1 to be finished
	while (status == wait)
		;

	//TODO:  Print out the threads unique ID
	//moved position so that it is really doing multi threading
	//Process the calculation first, than wait while T1 is still active then once
	//T1 change the status to go, it does the display part.
	std::cout << "Thread id of RunT2 = " <<
	std::this_thread::get_id() << std::endl;
	
	std::cout << "Number of bytes in file is " << size << std::endl;
	
	//TODO:  Display the contents of the binary file to the screen
	//HINT : You have a character buffer, but the values are of type int
	for (int i = 0; i < size; i+=sizeof(int)){
		std::cout <<(int)buffer[i];
		std::cout << " ";
	}

	//close
	infile.close();
}

int main(){
	//Opens ofstream object using binary for a file called data.bin
	std::ofstream fout("data.bin", std::ios::binary);
	if (!fout){
		std::cout << "Error with opening file.";
		return 1;
	}

	//Create a loop and write the number 0 to 99 into data.bin using an int data (tayp)
	for (int i = 0; i < 100; i++){
		fout.write((char*)&i, sizeof(int));
	}

	fout.close();

	//Creates a thread T1 that executes the RunT1() thread logic(see below)
	std::thread T1(RunT1);

	//Creates a thread T2 that executes the RunT2(std::string filename) thread logic(see below)
	std::thread T2(RunT2,"data.bin");

	//Join() threads T1 and T2 to synchronize them to the main process
	T2.join();
	T1.join();

	return 0;
}
