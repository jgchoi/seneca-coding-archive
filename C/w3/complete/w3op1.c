/*
 * Course Code 			- BTP100
 * Assignment Number	- Workshop3 Optional program 1
 * Name					- Jung Geon Choi
 * File name			- w3op1
 * Due date				- Sep.24, 2013
 * UPC number validator : As user input UPC number output tells whether the 
 * 			 			  UPC number is valid or not
 */
#include <stdio.h>

main()
{
	//valuables
		long long upc = 0LL;
		int tripleDigit,singleDigit,d1,d2,d3,d4,d5,d6,d7,d8,d9,d10,d11,check,match;

	//Input UPC number
		printf("\nUPC Validator\n\n"
			   "===============\n"
		       "Enter UPS (0 to quit) : ");
		scanf("%lld", &upc);
	while(upc>0)
		{	
	// separate digit 
		check = upc%10;
		d11=upc/10%10;
		d10=upc/100%10;
		d9 =upc/1000%10;
		d8 =upc/10000%10;
		d7 =upc/100000%10;
		d6 =upc/1000000%10;
		d5 =upc/10000000%10;
		d4 =upc/100000000%10;
		d3 =upc/1000000000%10;
		d2 =upc/10000000000%10;
		d1 =upc/100000000000%10;



		//validation calculation
		tripleDigit = d2+d4+d6+d8+d10;
		singleDigit = (d1+d3+d5+d7+d9+d11)*3;
		match		= check+singleDigit+tripleDigit;
		//check if total sum is ends in 0's
		match = match%10==0?1:0;
		if(match==1)
			{
			printf("This is valid UPC.\n");
			printf("The company code is %d%d%d%d%d%d.\n",d1,d2,d3,d4,d5,d6);
			printf("The product code is %d%d%d%d%d.\n",d7,d8,d9,d10,d11);
			}
		else
			printf("This is not a valid UPC.\n");
		//Ask UPS again
		printf("Enter UPS (0 to quit) : ");
		scanf("%lld", &upc);
		}
		//If 0 is entered
	printf("Have a nice day!\n");
		
}