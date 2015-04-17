//DArray2d.h

#ifndef __DArray2d__
#define __DArray2d__
	#include <iostream>
	#include <iomanip>
	#include <cstdlib>
	#include <ctime>
	
	namespace w3{
		class DArray2d{
			double ** array;
			int r;
			int c;
			
			public:
				DArray2d();
				DArray2d(int row, int column);
				DArray2d(const DArray2d & src);
				DArray2d & operator=(const DArray2d & src);
				DArray2d(DArray2d && src);
				DArray2d & operator=(DArray2d && src);
				~DArray2d();
				double check() const;
		};
	}
#endif