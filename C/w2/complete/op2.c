#include <stdio.h>
/*
 * Course Code		- BTP100
 * Assignment Number	- Workshop2 optional program2
 * Name			- Jung Geon Choi
 * File name		- op2
 * Due date		- Sep.17, 2013
 *
 * To calculate total price of ticket with given number of adult and child.
 *
 */

main()
{

//valuable
	int a=0,c=0;
	float	t=49.99, sub=0.0, tax=0.0, total=0.0;

//input
	printf("Enter the number of adults : ");
	scanf("%d", &a);
	printf("Enter the number of children : ");
	scanf("%d", &c);

//calculation

	sub	=	(a*t)+(c*t*0.9);
	tax	=	sub*0.13;
	total	=	sub*1.13;

//output
	printf(	"subtotal is	: $%.2f\n"
	      	"tax is		: $%.2f\n"
		"total is	: $%.2f\n",sub,tax,total);
}
