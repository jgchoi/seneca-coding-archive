// Workshop 8 - STL Algorithms
// DataTable.h

#ifndef _DATATABLE_H_
#define _DATATABLE_H_
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

namespace w8{
	template<typename T>
	class DataTable{
		int fw; // number of width of display
		int nd; // number of digits
		std::vector<T> x; // values in first column
		std::vector<T> y; // values in second column
	public:
		DataTable() :fw(0), nd(0), x(nullptr), y(nullptr){} //safe empty constructor
		DataTable(std::ifstream & fin, const int _fw, const int _nd){
			fw = _fw;
			nd = _nd;

			//Assuming input data is valid
			while (fin.good()) {
				T _x;
				T _y;
				
				//add x
				fin >> _x;
				x.push_back(_x);
				
				//add y
				fin >> _y;
				y.push_back(_y);
			}
		}
		T mean() const{
			//calculate sum
			T sum = std::accumulate(y.begin(), y.end(), (T)0);
			
			//find number of entries
			float n = y.size();
			return sum / n;
		}
		T sigma() const{
			//use mean from member function
			T mean_value = mean();
			
			//size used in stddv
			float n = y.size() - 1;
			
			//sum of square value of y minus mean of y
			T sum = std::accumulate(y.begin(), y.end(), (T)0,
				[=](T _x, T _y){ return _x + std::pow((_y - mean_value), 2); });
				
			//calculate the sqrt of the sum of top value
			T result = std::sqrt(sum/n);
			return result;
		}
		T median() const{
			//first, copy to tmp, then sort!
			std::vector<T> temp = y;

			//small to large sort
			std::sort(temp.begin(), temp.end(), [](T i, T j){return i < j; });
			
			//find the size
			int n = y.size();
			
			//find median position
			int middle = n / 2;
			
			return temp.at(middle);

		}
		void regression(T& _slope, T& _intercept) const{
			int n = y.size();
			float slope;
			float intercept;
			
			//variable name explains what value it takes
			T sum_of_product = std::inner_product(x.begin(), x.end(), y.begin(),(T)0);
			T sum_x = std::accumulate(x.begin(), x.end(), (T)0);
			T sum_y = std::accumulate(y.begin(), y.end(), (T)0);
			T sqr_sum_x = pow(sum_x, 2);
			T sum_sqr_x = std::accumulate(x.begin(), x.end(), (T)0, [](T _x, T _y){return _x + pow(_y, 2); });
			
			//calculating slope
			slope = ((n * (sum_of_product)) - (sum_x * sum_y)) / ((n*sum_sqr_x) - sqr_sum_x);
			
			//calculating intercept
			intercept = (sum_y - slope * sum_x) / n;

			//assigning values to references
			_slope = slope;
			_intercept = intercept;
		}
		void display(std::ostream& os) const{
			//display setup
			os << std::fixed << std::setprecision(nd);
			
			//label
			os << std::setw(fw) << "x";
			os << std::setw(fw) << "y";
			os << std::endl;
			
			//display
			for (int i = 0; i < x.size(); i++){
				os << std::setw(fw) << x[i];
				os << std::setw(fw) << y[i];
				os << std::endl;
			}
		}
	};//end of class

	//non-member helper function
	std::ostream & operator<<(std::ostream& os, const DataTable<float> & src){
		src.display(os);
		return os;
	}
}
#endif