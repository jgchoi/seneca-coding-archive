#include <stdio.h>

/*
 * Course Code		- BTP100
 * Assignment Number	- Workshop2
 * Name			- Jung Geon Choi
 * File name		- w2
 * Due date		- Sep.17, 2013
 *
 * To calculate total price with given price,unit and calculte change with given cash tender.
 *
 */

main()
{

//valuables1
	int n = 0, loonie = 0, cent = 0;
	float uprice = 0.0, pprice = 0.0, tax = 0.0, tender = 0.0, total = 0.0;

//input
	printf("Enter the number of items	: ");
	scanf("%d", &n);
	printf("Enter the unit price		: ");
	scanf("%f", &uprice);

//calculation
	pprice	=	n*uprice;
	tax	=	pprice*0.13;
	total	=	pprice*1.13;
//output
	printf(	"Purchase price			: %.2f\n"
		"HST (13%)			: %.2f\n"
		"Total price			: %.2f\n\n",pprice,tax,total);

//tender
	printf("cash tendered			: ");
	scanf("%f", &tender);
//calculation2

	float change = 0.0, centint = 0.0;
	change = tender - total;

	loonie = (int) change;
	centint = (change - loonie)*100;
	cent = (int) centint;


//output2
	printf( "Change loonies			: %d\n"
		"Change cents			: %d\n",loonie,cent);
}
