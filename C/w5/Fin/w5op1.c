/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop5
 * Name			- Jung Geon Choi
 * File name		- w5op1
 * Due date		- Oct.15, 2013
 * Program Title	- Firework calculator : calculate the time firework reachs desired height
 */
 
#include <stdio.h>

//magic number (gravity)
#define G -4.9

//prototypes
double sqrt(double num);
int roots(double a, double b, double c, double *r1, double *r2);


int main(void)
{

	//valuables
	double v=1,h=0,time1=0,time2=0;
	int rootresult=0;
	
    do // main program starting (loop)
    {
		//input
		printf( "Fireworks\n"
			"=========\n"
			"Initial vertical velocity (m/sec) (0 to quit) : ");
			scanf("%lf", &v);
		if(v==0) // in case of user input 0 at 1st cycle
			{
			printf("Have a Nice Day !\n");
			return 0;
			}
		printf(	"Desired Height (m) : ");
			scanf("%lf", &h);

	//calculation
	rootresult = root(G, v, h, &time1, &time2);
	
	//output
	switch(rootresult) //depends on rootresult, it can have 3 outcomes (no root, 1 root, 2roots)
	{
		case 0:
			printf( "Your firework will never reach %.2lf m\n\n", h);
			break;
		case 1:
			printf(	"Your firework will reach the desired height at time\n"
				"  %.2lf sec\n\n", time1);
			break;
		case 2:
			printf(	"Your firework will reach the desired height at time\n"
				"  %.2lf sec\n"
				"  %.2lf sec\n\n", time1, time2);
			break;
		default: //there will be no other case
			;
	}
    }while(v!=0);
	printf("Have a Nice Day !\n");
}

//calculating square root
double sqrt(double num)
{
	double numo=0;
	int i=0;
	numo=num;
	while(i<20)
	{
		i++;
		num=0.5 * (num + (numo/num));
	}
return num;
}

//return how many roots are there, pointers to change root value in main as time1 and time 2
int root(double a, double b, double c, double *r1, double *r2)
{	//D
	double d = (b*b) + (4 * a * c);
	int result=0;
	if(d<-0.00000001) // if 'd' < 0 ; 0.0000001 is to exclude sqrt approximation error
		result = 0;
	else if(d>-0.00000001 && d<0.00000001)
	{	// range is from -1*10^8 to 1*10^8, because sqrt approximation error never gives d==0
		*r1 = (-b + sqrt(d))/(2*a);
		*r2 = *r1;
		result = 1;
	}
	else if(d>0)
	{
		*r1 = (-b + sqrt(d))/(2*a);
		*r2 = (-b - sqrt(d))/(2*a);
		result = 2;
	}
return result;
}
