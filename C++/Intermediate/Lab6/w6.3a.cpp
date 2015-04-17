// Workshop 6 - Lambda Expression
// w6.3a.cpp

#include <iostream>
#include <iomanip>
#include <cstdlib>

template <typename T, typename Func>
void transform(const T* a, const T* b, T* c, unsigned n,
const Func & f
	) {
	for (unsigned i = 0; i < n; i++)
		c[i] = f(a[i], b[i]);
}

int main(int argc, char* argv[]) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 4) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	unsigned n = std::atoi(argv[1]);
	float wa = std::atof(argv[2]);
	float wb = std::atof(argv[3]);

	// initialize
	float* a = new float[n];
	float* b = new float[n];
	float* c = new float[n];
	for (unsigned i = 0; i < n; i++) {
		a[i] = b[i] = (float)i * 0.1f;
	}
	// transform using weighted addition
	/* call transform(...) here */
	/* define your lambda expression as an argument here */
	transform(a, b, c, n, [=](const float & a,const float & b){return (a * wa) + (b*wb); });

	// output results
	std::cout << std::fixed << std::setprecision(2);
	for (unsigned i = 0; i < n; i++)
		std::cout << a[i] << " + " << b[i] << " = "
		<< c[i] << std::endl;

	// clean up
	delete[] a;
	delete[] b;
	delete[] c;

	std::cout << "Press any key to continue ... ";
	std::cin.get();
}
