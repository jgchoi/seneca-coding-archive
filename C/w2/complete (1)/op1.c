#include <stdio.h>
/*
 * Course Code		- BTP100
 * Assignment Number 	- Workshop2 optional program 1
 * Name			- Jung Geon Choi
 * File name 		- op1
 * Due date 		- Sep.17, 2013
 *
 * To calculate total price of book with given number of unit and price.
 *
 */

main()
{

//valuable
	int n	= 0;
	float p	= 0.0, pbt = 0.0, tax = 0.0, total = 0.0;

//input
	printf("Price of a book?");
	scanf("%f", &p);
	printf("How many books?");
	scanf("%d", &n);

//calculation
	pbt	=	n*p;
	tax	=	pbt*0.13;
	total	=	pbt*1.13;

//output
	printf("Price before tax is $%.2f\n",pbt);
	printf("Tax is $%.2f\n",tax);
	printf("Total price is $%.2f \n",total);
}
