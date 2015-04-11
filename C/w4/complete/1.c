/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop4 Optional 1
 * Name			- Jung Geon Choi
 * File name		- w4op1
 * Due date		- Oct.01, 2013
 * Program Title	- Prime chart creator : Creates prime number chart with given top number and number of columns
 */
 
#include <stdio.h>

main()
{
int lim,num=1000000,colm,colmo,digit1;
lim=100000000;
colm=10;

colmo=colm;
	
	while(num<lim)
		{	
		++num;
		if(prime(num)==1)
			{
			printf("%8d",num);
			colm--;
			}
		if(colm==0)
			{
			colm=colmo;
			printf("\n");
			}
		}
printf("\n");//If there is no more prime number, print \n to clearly divide chart from command line
}

int prime(int num)//this function gives either 0 or 1 by checking if the number is prime or not. That's it
{
int numorig,div,primefail=1;
div=1;
numorig=num;
	
	while(numorig-1>div)
		{
		div++;
		//printf("numorig = %d, div = %d\n",numorig,div);
		num=numorig%div;
		//printf("num = %d\n",num);
		if(num==0)
			{
			return primefail=0;
			}
		}
return primefail;
}
