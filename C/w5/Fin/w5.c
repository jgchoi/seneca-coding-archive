/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop5
 * Name			- Jung Geon Choi
 * File name		- w5
 * Due date		- Oct.15, 2013
 * Program Title	- Simplifier : Simplify numerator and denominator using pointer
 */

#include <stdio.h>

//Prototype
void simplify(int *numerator, int *denominator);

main()
{
	//valuables: numo(original) numf(final)
	int numo=0, deino=0, numf=0, deinf=0;
	
	//input
	printf("Fraction Simplifier\n"
		   "===================\n"
		   "Numerator  : ");
	 scanf("%d", &numo);
	printf("Denominator: ");
	 scanf("%d", &deino);

	//keep original value
		numf=numo;
		deinf=deino;
		
	//Call simplify
		simplify(&numf, &deinf);
		
	//output
	printf("\n%d / %d = %d / %d\n", numo, deino, numf, deinf);
}

//simplifying function
void simplify(int *numerator,int *denominator)
{
	//valuable : dc (divider counter), minkeep(keeping min number)	
	int dc=1, minkeep=0;
	
	//case of *numerator = *denominator
	if(*numerator == *denominator)
		return;
		
	//set minimum number
	else if(*numerator < *denominator)
		minkeep = *numerator;
	else
		minkeep = *denominator;

	//Trying division starting with 2
	do
	{
		dc++;
		if(*numerator % dc == 0 && *denominator % dc == 0)
		{
			*numerator = *numerator / dc;
			*denominator = *denominator / dc;
			dc = 1;
		}
	}
	while(dc<minkeep); // if divider get bigger than min value it stops
}

