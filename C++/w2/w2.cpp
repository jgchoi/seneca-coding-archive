// Workshop 2 - Fraction Simplifier
// w2.cpp

 #include <iostream>
 using namespace std;
 
 #include "Fraction.h"

 int unitTests(Fraction* f) {

   cout << "Fraction Simplifier Tests" << endl; 
     cout << "=========================" << endl;
	int result[5]={0};
	int i=0;
	
	
	//test1
     f->set(4,16); // input 4 and 16
	 if(f->numerator()==1 && f->denominator()==4) //should be 1 and 4
		{
			cout << "Test 1 Passed" << endl;
			cout << "Input : 4/16" << endl;
			cout << "Output: "; f->display();
			cout << endl;
			result[0]=1;
		}
	//test2
     f->set(-4,16); //-4, 16
	 if(f->numerator()==-1 && f->denominator()==4) //should be -1 and 4
		{
			cout << "Test 2 Passed" << endl;
			cout << "Input : -4/16" << endl;
			cout << "Output: "; f->display();
			cout << endl;
			result[1]=1;
		}
	//test3
     f->set(0,16); //0, 16
	 if(f->numerator()==0 && f->denominator()==16) //should be no change
		{
			cout << "Test 3 Passed" << endl;
			cout << "Input : 0/16" << endl;
			cout << "Output: "; f->display();
			cout << endl;
			result[2]=1;
		}
		
	//test4
     f->set(4,0); // 4, 0
	 if(f->numerator()==4 && f->denominator()==0) // should be no change
		{
			cout << "Test 4 Passed" << endl;
			cout << "Input : 4/0" << endl;
			cout << "Output: "; f->display();
			cout << endl;
			result[3]=1;
		}
	//test5
     f->set(0,0);
	 if(f->numerator()==0 && f->denominator()==0) // should be no change
		{
			cout << "Test 5 Passed" << endl;
			cout << "Input : 0/0" << endl;
			cout << "Output: "; f->display();
			cout << endl;
			result[4]=1;
		}
	//case if all test passed
	while(result[i]==1)
		{
		i++;
		if(i==5)
		return 1;
		}
		

		
	return 0; //fail to pass all test
 }

 int main() {
     Fraction fraction;
     bool passed;

     passed = unitTests(&fraction);

     if (passed)
         cout << "Passed All Tests" << endl;
     else
         cout << "Failed Tests" << endl;
 }
