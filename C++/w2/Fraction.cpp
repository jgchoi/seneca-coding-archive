#include <iostream>
using namespace std;

#include "Fraction.h"

void Fraction::set(int n , int d)
{
 nu=n;
 de=d;
 simplify();
}

int Fraction::numerator() const
{return nu;};
		
int Fraction::denominator() const
{return de;};
		
void Fraction::simplify()
{
        //valuable : dc (divider counter), minkeep(keeping min number)  
        int dc=1, minkeep=0;
	int demi=0, numi=0;
        //case of nu = de
        if(nu == de)
		return;
	//case of de=0
	if(de == 0)
		return;

	if(nu == 0)
		return;

	//case if any numb is minus
	if(nu<0)
		{nu*=-1;numi=1;}
	if(de<0)
		{de*=-1;demi=1;}
        
		
	//set minimum number
	if(nu < de)
			minkeep = nu;
	else
			minkeep = de;

        //Trying division starting with 2
        do
        {
                dc++;
                if(nu % dc == 0 && de % dc == 0)
                {
                        nu = nu / dc;
                        de = de / dc;
                        dc = 1;
                }
        }
        while(dc<minkeep); // if divider get bigger than min value it stops
	
	//if it was minus, change back
	if(demi==1 && numi==1)
		;
	else if(demi==1)
		nu *= -1;
	else if(numi==1)
		nu *= -1;
}





void Fraction::display() const
{
if(de==0)
cout << "Undefined" << endl;
else if(nu==0)
cout << 0 << endl;
else
cout << nu << "/" << de << endl;
}
