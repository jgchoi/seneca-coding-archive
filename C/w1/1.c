#include <stdio.h>

main()
{
//valuables
	int n = 0.0;
	float unitp = 0.0,purchasep = 0.0, tax = 0.0, total = 0.0, tender = 0.0; 

//input
	printf("Enter the number of items	:  ");
	scanf("%d", &n);
	
	printf("Enter the unit price		:  ");
	scanf("%f", &unitp);

//calculation
	purchasep=n*unitp;
	tax 	= n*unitp*0.13;
	total	= n*unitp*1.13;

//output
	printf("Purchase price			: %.2f\n",purchasep);
	printf("HST (13%)			: %.2f\n",tax);
	printf("Total price			: %.2f\n",total);

//tender input
	printf("Cash tendered			: ");
	scanf("%f", &tender);

// change
	float change = 0.0, loonie = 0.0, cents = 0.0;

	change=total-tender;

	printf(%f,tender);
}
