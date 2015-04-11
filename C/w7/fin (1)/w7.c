/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop7
 * Name			- Jung Geon Choi
 * File name		- w7
 * Due date		- Nov. 5, 2013
 * 
 */

#include <stdio.h>
#define INV_MAX 100 // Maximum array value

void p_title(void);
void p_result(void);
float get_price();
long long int get_barcode();
int get_quantity();

int main(void)
{
//---- (valuables) -------------------------------------------------
long long int barcode[INV_MAX]={0};
float price[INV_MAX]={0};
int quantity[INV_MAX]={0};
float value[INV_MAX]={0};
int i=0; // Input position counter
int j=0; // output position counter
float total=0;
p_title(); // title priting

//---- (input) ------------------------------------------------------
barcode[i]=get_barcode();

for(i=0;barcode[i]!=0;i++)
	{
	price	[i]	= get_price();
	quantity[i]	= get_quantity();
	barcode	[i+1]	= get_barcode();
	
	value[i]=price[i]*quantity[i]; // value calculation
	total += value[i];
	}

//---- (output of goods in stock) -----------------------------------
p_result(); // output summary title printing
for(j=0;j!=i;j++)
	{
	printf("%010lld%7.2f       %3d%8.02f\n",barcode[j],price[j],quantity[j],value[j]);
	}
//---- (total) ------------------------------------------------------
printf("                              -----\n"
       "Total value goods in stock%9.02f\n",total);
 } // main()
 

//-----------------------------------------------------------------------------
//show title of the program
void p_title(void)
{
printf("Grocery Store Inventory\n"
	"=======================\n");
}

//-----------------------------------------------------------------------------
//show title of output table
void p_result(void)
{
printf("\n\n	Goods in Stock\n"
       "	==============\n"
       "Barcode    Price   Quantity   Value\n"
       "-----------------------------------\n");
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
		printf("Price	  :  ");
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
//get barcode input / only integer within 0~9999999999(10digit)
long long int get_barcode()
{
	//valuable
	long long int num = -0;
	int r = 0;
	long long int range_min = 0, range_max = 9999999999;
	char check = 0;

	do
		{
		printf("Barcode   :  ");
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
		printf("Quantity  :  ");
		
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

