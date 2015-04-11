/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop4
 * Name			- Jung Geon Choi
 * File name		- w4
 * Due date		- Oct.01, 2013
 * Program Title	- Interest Calculator : Calculate total amount of own would receive with given principal
 *						interest rate and number of period using functions
 */
 
#include <stdio.h>

float sqr(float base,int exp)//calculation exponential value from base and int
{
float rate=1;
base = base + 1;
while(exp>0)
	{
	exp--;
	rate=rate*base;
	}
return rate;
}

main()
{
int exp;
float base,prin;

printf(	"\nInvest Calculator\n"
	  "=================\n"
	  "Principal : ");
	scanf("%f", &prin);
printf( "Annual Rate : ");
	scanf("%f", &base);
printf(	"No of Years : ");
	scanf("%d", &exp);
		
prin=prin*sqr(base,exp);
printf("\nThe future value is $%.2f\n\n",prin);
}
