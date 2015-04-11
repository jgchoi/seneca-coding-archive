/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop3
 * Name			- Jung Geon Choi
 * File name		- w3
 * Due date		- Sep.24, 2013
 * SIN number validator : As user input SIN number output tells whether the 
 * 			  SIN number is valid or not
 */
#include <stdio.h>

main()
{
		long sin=0;
		int doubleDigit,singleDigit,d1,d2,d3,d4,d5,d6,d7,d8,check,match;

		printf("\nSIN Validator\n\n");
		printf("=============\n");
		printf("SIN (0 to quit) : ");
		scanf("%ld", &sin);
		
		while(sin>0)
		
		{	
					
			check = sin%10;
			d8=sin/10%10;
			d7=sin/100%10;
			d6=sin/1000%10;
			d5=sin/10000%10;
			d4=sin/100000%10;
			d3=sin/1000000%10;
			d2=sin/10000000%10;
			d1=sin/100000000%10;
			switch (d2)
				{
				case 1 :
						d2=2;
						break;
				case 2 :
						d2=4;
						break;
				case 3 : 
						d2=6;
						break;
				case 4 :
						d2=8;
						break;
				case 5 :
						d2=1;
						break;
				case 6 :
						d2=3;
						break;
				case 7 :
						d2=5;
						break;
				case 8 :
						d2=7;
						break;
				case 9 :
						d2=9;
						break;
				default :
						break;
				}	
			switch (d4)
				{
				case 1 :
						d4=2;
						break;
				case 2 :
						d4=4;  
						break;    
				case 3 :
						d4=6;
						break;
				case 4 :
						d4=8;
						break;
				case 5 :
						d4=1;
						break;
				case 6 :
						d4=3;
						break;
				case 7 :
						d4=5;
						break;
				case 8 :
						d4=7;
						break;
				case 9 :
						d4=9;
						break;
				default :
						break;
				}
			switch (d6)
				{
				case 1 :
						d6=2;
						break;
				case 2 :
						d6=4;  
						break;    
				case 3 :
						d6=6;
						break;
				case 4 :
						d6=8;
						break;
				case 5 :
						d6=1;
						break;
				case 6 :
						d6=3;
						break;
				case 7 :
						d6=5;
						break;
				case 8 :
						d6=7;
						break;
				case 9 :
						d6=9;
						break;
				default:
						break;
				}
			switch (d8)
				{
				case 1 :
						d8=2;
						break;
				case 2 :
						d8=4;  
						break;    
				case 3 :
						d8=6;
						break;
				case 4 :
						d8=8;
						break;
				case 5 :
						d8=1;
						break;
				case 6 :
						d8=3;
						break;
				case 7 :
						d8=5;
						break;
				case 8 :
						d8=7;
						break;
				case 9 :
						d8=9;
						break;
				deafult:
						break;
				}
					doubleDigit = d2+d4+d6+d8;
					singleDigit = d1+d3+d5+d7;
					match		= check+singleDigit+doubleDigit;
		match = match%10==0?1:0;
		if(match)
		printf("This is a valid SIN\n");
		else
		printf("This is not a valid SIN\n");
		
		printf("SIN (0 to quit) : ");
		scanf("%ld", &sin);
		
			}
			
		
		printf("Have a nice day!\n");
}
