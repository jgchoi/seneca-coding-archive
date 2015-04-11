/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop4 Optional 1
 * Name			- Jung Geon Choi
 * File name		- w4op1
 * Due date		- Oct.01, 2013
 * Program Title	- Prime chart creator : Creates prime number chart with given top number and number of columns
 */
 
#include <stdio.h>


int checkdigit(int numb)//Calculate how many digit the prime number have
{
int digit=0;
while(numb>0)
	{
	++digit;
	numb=numb/10;
	}
return digit;
}


main()
{
int lim,num=1,colm,colmo,digit1;

printf("\nTable of Primes\n"
         "===============\n"
	 "Upper limits : ");
	scanf("%d", &lim);
printf("# of columns : ");
	scanf("%d", &colm);
colmo=colm;
	
	while(num<lim)
		{	
		++num;
		if(prime(num)==1)
			{
			digit1=checkdigit(num);
			while(digit1<5)//Add space depends on how man digit it has (max 5 digit for now), by changing number, digits can increase
				{
				printf(" ");
				digit1++;
				}
			printf("%d\t",num);
			colm--;//substract colm value to count how many values have been entered, if it become 0 next if() will print \n
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
div=num;
numorig=num;
	
	while(div>2)
		{
		div--;
		num=numorig%div;
		if(num==0)
			{
			return primefail=0;
			}
		}
return primefail;
}
