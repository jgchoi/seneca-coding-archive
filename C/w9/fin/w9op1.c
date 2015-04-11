/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop Week 9
 * Name			- Jung Geon Choi
 * File name		- w9op1
 * Due date		- Dec. 03, 2013
 * Statistic calculator : calculate mean, stddv.
 */


#include <stdio.h>
#include <math.h>

//-----------------------------------------------------------------------------
//prototypes
void p_title(void);
double cal_avg(double p_data[], int size);
double cal_sum(double p_data[], int size);
double cal_stddv(double sum, double avg, int size);

//-----------------------------------------------------------------------------
//main
int main(void)
	{
	p_title(); // program title
	
	//---- (valuables) ----------------------------------------------
	char f_name[50];
	int i = 0;
	int j = 0;
	double price[50]={0};
	double avg;
	double sum;
	double std;
	
	//---- (file starting point) ------------------------------------
	//file declare
	FILE *f_from = NULL;

	//user input file name
		printf("Enter the name of the data file : ");
			scanf(" %s", f_name);
			
			
	//open
	f_from = fopen(f_name, "r");
	
	//read
	if(f_from==NULL)
	{
	printf("Can not find file name \"%s\"\n", f_name);
	}
	else
	{
		while(fscanf(f_from, "%lf\n", &price[i])!=EOF)
			{
			i++;
			}
	}
	
	//---- (calculation) --------------------------------------------
	avg=cal_avg(price, i);
	sum=cal_sum(price, i);
	std=cal_stddv(sum,avg,i);
	
	//close file
	fclose(f_from);
	
	//last output
	printf("The number of data values read from this file was %3d\n"
		   "Their statistical mean is %6.2lf\n"
		   "Their standard deviation is %6.2lf\n",i, avg, std);
		   
	return 0;
	}

//-----------------------------------------------------------------------------
//print title
void p_title(void)
{
	printf("Statistics Calculator\n"
		   "=====================\n");
}

//-----------------------------------------------------------------------------
//calculate average value from array
double cal_avg(double p_data[], int size)
{
int i;
double sum=0;
for(i=0;i<size;i++)
	{
	sum += p_data[i];
	}
	return sum/size;
}

//-----------------------------------------------------------------------------
//calculate sum of power value from each array
double cal_sum(double p_data[], int size)
{
int i;
double sum=0;
for(i=0;i<size;i++)
	{
	sum+=powl(p_data[i], 2);
	}
	return sum;
}

//-----------------------------------------------------------------------------
//calculate stddv
double cal_stddv(double sum, double avg, int size)
{
return  sqrtl((sum/size)-pow(avg, 2));
}