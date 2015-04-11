/*
 * Course Code		- BTP100
 * Assignment Number	- Workshop5 Bonus1
 * Name			- Jung Geon Choi
 * File name		- w5b1.c
 * Due date 		- Oct. 08 / 2013
 * 
 * Average calculator : Calculate avrage of marks
 */

#include<stdio.h>
#define MAX 100
#define MIN 0

//Clear buffer leftover from getchar
//
void clearbuf (void)
{
	while (getchar() != '\n')
		;
}

//input validator. only accept numbers in between #MAX & #MIN
//
float getint(int min, int max)
{
	float value, keeptrying = 1, rc;
	char after;

	do
	{
		printf( "Enter a mark [%d..%d]", min,max);
		rc = scanf("%f%c", &value,&after);
		if(rc==0)
		{
			printf("*** No valid input. Re-input again.\n");
			clearbuf();
		}
		else if(after!='\n')
		{
			printf("*** Trailing characters. Re-input again.\n");;
			clearbuf();
		}
		else if(value < min || value > max)
		{
			printf("*** Out of range. Re-input again.\n");
		}
		else
			keeptrying = 0;
	}while (keeptrying ==1);
	return value;
}


main()
{

//valuable
//
int entry=-1;
float total=0,mark=0,avg1=0;

//get input with validation using getint counts number of entry
//
do
{
mark = getint(MIN,MAX);

entry++;
total = total + mark;
}while (mark!=0);

//Calculation of avg and output
//
avg1 = total/entry;
printf("The average of the %d marks is %.2f\n",entry,avg1);
}
