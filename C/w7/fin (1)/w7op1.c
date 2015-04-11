/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop7
 * Name			- Jung Geon Choi
 * File name		- w7op1
 * Due date		- Nov. 5, 2013
 * Work in Progress
 */

#include <stdio.h>
#define INV_MAX 100 // Maximum array value


//-----------------------------------------------------------------------------
//show title of the program
void p_title(void)
{
printf("Work in Progress\n"
	"================\n");
}

//-----------------------------------------------------------------------------
//show title of output table
void p_result(void)
{
printf("\n\n	Work in Progess\n"
       "	===============\n"
       "Project   Rate  Hours      Value\n"
       "--------------------------------\n");
}

//-----------------------------------------------------------------------------
//get price value, value valid on float number between 1~999.99
float get_price()
{
	//valuable
	float num = 0;
	int r = 0;
	float range_min = 1, range_max = 999.99;
	char check = 0;

	do
		{
		printf("Rate       : ");
		r = scanf("%f%c", &num, &check);
		
		
		if(r==2 && num>=range_min && num<=range_max && check=='\n');
		else
			{
			num = 0;
			printf("*** Invalid Input. Try Again ***\n");
			if(check!='\n' || r==0) 
				while(getchar()!='\n');
			}
		}
	while(num==0);
	
	return num;
}

//-----------------------------------------------------------------------------
//get barcode input / only integer within 0~9999(4digit)
long long int get_barcode()
{
	//valuable
	long long int num = -0;
	int r = 0;
	long long int range_min = 0, range_max = 9999;
	char check = 0;

	do
		{
		printf("Project    : ");
		r = scanf("%lld%c", &num, &check);
		
		
		if(r==2 && num>=range_min && num<=range_max && check=='\n');
		else
			{
			num = -1;
			printf("*** Invalid Input. Try Again ***\n");
			if(check!='\n' || r==0) 
				while(getchar()!='\n');
			}
		}
	while(num==-1);
	
	return num;
}

//-----------------------------------------------------------------------------
//get quantity information. input int between 1~9999
int get_quantity()
{
	//valuable
	int num = 0, r = 0;
	int range_min = 1, range_max = 9999;
	char check = 0;

	do
		{
		printf("Hours Spent: ");
		
		r = scanf("%d%c", &num, &check);
		
		
		if(r==2 && num>=range_min && num<=range_max && check=='\n');
		else
			{
			num = 0;
			printf("*** Invalid Input. Try Again ***\n");
			if(check!='\n' || r==0)
				while(getchar()!='\n');
			}
		}
	while(num==0);
	
	return num;
}

int main(void)
{
//---- (valuables) -------------------------------------------------
long long int barcode[INV_MAX]={0};
float price[INV_MAX]={0};
int quantity[INV_MAX]={0};
float value[INV_MAX]={0};
int i=0; // Input position counter
int j=0; // output position counter
int k=0,l=0; // find max counter
int tmp=0; // value for value exchange
float total=0;

p_title(); // title priting

//---- (input) ------------------------------------------------------
barcode[i]=get_barcode(); //barcode[0]

for(i=0;barcode[i]!=0;i++) 
	{
	price	[i]	= get_price();
	quantity[i]	= get_quantity();
	barcode	[i+1]	= get_barcode(); // for barcode[i++]
	
	value[i]=price[i]*quantity[i]; // value calculation
	total += value[i]; // sum total
	}
//---- (calculate max) ----------------------------------------------
//k,l
for(k=0;k<i-1;k++) // compare barcode(ISBN in this program)[0~(i-1) to barcode[1~i]
	{
	for(l=k+1;l<i;l++) //range of barcode[1~i]
		{
		if(barcode[k]>barcode[l]) //if[barcode[1~i] is smaller (switch position for barcode,quantity,price 
			{
			tmp=barcode[k]; //change barcode
			barcode[k]=barcode[l];
			barcode[l]=tmp;
			
			tmp=quantity[k]; //change q
			quantity[k]=quantity[l];
			quantity[l]=tmp;
			
			tmp=price[k]; //change p
			price[k]=price[l];
			price[l]=tmp;
			
			tmp=value[k]; //change total
			value[k]=value[l];
			value[l]=tmp;
			}
		}
	} //at the end point, all data sorted in smallest to largest in order of [0~i-1]
	
//---- (output of goods in stock) -----------------------------------
p_result(); // output summary title printing
for(j=0;j!=i;j++)
	{
	printf("%04lld%10.02f%7d%11.02f\n",barcode[j],price[j],quantity[j],value[j]);
	}
//---- (total) ------------------------------------------------------
printf("                         --------\n"
       "Total Work in Progress%10.02f\n",total);
//     "Barcode    Price   Quantity   Value\n"
//     "-----------------------------------
 } // main()
 