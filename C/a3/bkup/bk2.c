/*
 * I declare that the attached assignment is wholly my own work in accordance 
 * with Seneca Academic Policy.  No part of this assignment has been copied 
 * manually or electronically from any other source (including web sites) or 
 * distributed to other students. 
 * 
 * Name   ___Jung Geon Choi_______   Student ID ___025651134_____ 
 */
 
/* Course Code		- BTP100
 * Assignment Number	- Assignment 3
 * Name			- Jung Geon Choi
 * File name		- a3.c
 * Due date		- Dec. 10, 2013
 * Pay calculator
 * Read file, report in txt file.
 */

#include <stdio.h>
#include "sales.h"
#define MAX_SIZE 100

//-----------------------------------------------------------------------------
//Structure defininition = "sales.h"
/*
struct salesPerson
{
    int salesNum;
    char lastName[31];
    char firstName[31];
    int salesLevel;
    double salesAmount;
    double salesPay;
};
*/


//-----------------------------------------------------------------------------
// 
void writePay(struct salesPerson sRec[], int rNum, FILE *fp)
{
int i;

	fprintf(fp, "%45s","Weekly Payment Report\n");
	fprintf(fp, "--------------------------------------------------------------------------------\n"
		    "| SNum | Last Name          | First Name         | Lvl | Sales Amt  | Week Pay |\n"
		    "================================================================================\n");
		for(i=0;i<rNum;i++)
			{
	fprintf(fp, "|%5d | %-19s| %-19s| %-4d| $%-10.2lf| $%-8.2lf|\n"
		    "--------------------------------------------------------------------------------\n",
		    sRec[i].salesNum, sRec[i].lastName, sRec[i].firstName, sRec[i].salesLevel,
		    sRec[i].salesAmount, sRec[i].salesPay);
			}
}

//-----------------------------------------------------------------------------
// 
void sortPay(struct salesPerson sRec[], int rNum) 
{
int i;
int j;
struct salesPerson tmp;

	for(i=0;i<rNum-1;i++)
		{
		for(j=i+1;j<rNum;j++)
			{
			if(sRec[i].salesPay < sRec[j].salesPay)
				{
				tmp=sRec[i];
				sRec[i]=sRec[j];
				sRec[j]=tmp;
				}
			}
		}
}

//-----------------------------------------------------------------------------
// 
void calcPay(struct salesPerson sRec[], float lvl[], int rNum) 
{
int i;

for(i=0;i<rNum;i++)
	{
	sRec[i].salesPay = lvl[sRec[i].salesLevel] * sRec[i].salesAmount;
	}
}

//-----------------------------------------------------------------------------
// 
int setArray(FILE *fp, struct salesPerson sRec[]) 
{
int i=0;
int j; //debug
printf("read start\n");//debug
//			1001:Brendes:Howard:1:750.92
/*
for(i=0;j=fscanf(fp, "%d:%30[^:]:%30[^:]:%d:%lf\n",&sRec[i].salesNum,sRec[i].lastName,
				    sRec[i].firstName,&sRec[i].salesLevel,
				    &sRec[i].salesAmount) == 6;i++)
				    {

				    }
				       printf("***[Read number %d]\n\tSales Num is %d\n\tLast name is %s\n\tFirst name is %s\n\tSales lvl is %d\n\tsales amount is %lf\n***End of cycle\n", i,
					sRec[i].salesNum,sRec[i].lastName,
					sRec[i].firstName,sRec[i].salesLevel,
					sRec[i].salesAmount);
			printf("value of j is %d\n", j);	    
*/

while(j=fscanf(fp, "%d:%30[^:]:%30[^:]:%d:%lf\n",&sRec[i].salesNum,sRec[i].lastName,
				    sRec[i].firstName,&sRec[i].salesLevel,
				    &sRec[i].salesAmount)==6)
				    {
				    i++;
				    printf("read success!\n");
				    }
	return i;
}

//-----------------------------------------------------------------------------
// 
int main(void)
{
	//valuable
	float level[5] = {0.02, 0.04, 0.06, 0.08, 0.10}; 
	int i;
	int j;
	int k;
	int rNum;
	
	struct salesPerson sRec[MAX_SIZE];
	
	//file pointer decrlaer
		//read
		FILE *fi=NULL;
		//write
		FILE *fo=NULL;
	//open
	fi = fopen("sales.dat","r");
	fo = fopen("pay.txt","w");
	
	//check if openfail
	if(fi == NULL)
		{
		printf("Program fail to open file \"sales.dat\"");
		return 1;
		}
	//check if write fail
	if(fo == NULL)
		{
		printf("Program fail to open file \"pay.txt\"");
		return 1;
		}
	//read file
		rNum = setArray(fi, sRec);

	
	//calculate w_pay
		calcPay(sRec, level, rNum);
		
	//sort
		sortPay(sRec, rNum);
		
	//disply
		writePay(sRec, rNum, fo);
		
	//end
}
