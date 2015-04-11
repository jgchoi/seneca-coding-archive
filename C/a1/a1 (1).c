/* I declare that the attached assignment is wholly my
 * own work in accordance with Seneca Academic Policy.  No part of this
 * assignment has been copied manually or electronically from any
 * other source (including web sites) or distributed to other students.
 *
 * Name : Jung_Geon_Choi		Student ID : 025651134
 */


/* Course Code 		- BTP100
 * Assignment Number	- Assignment 1
 * Name			- Jung Geon Choi
 * File name		- a1.c
 * Due date		- Oct.14 , 2013
 * Clock calculator
 * Perform addition or subtraction of two clocks input from user
 */
 
#include <stdio.h>
 
//Clear Buffer
//
void clearbuf (void) 
{
	while (getchar() != '\n')
		;
}
 
//Validate Input using 4 criterias
//
int invali (int hh, int mm, int ss,char newline, int countin)
  	{
	int vfail = 0;
		if(countin==0)		//if there are no number input
			{
			vfail=1;
			printf("*** No valid data input. Try again!\n");
			clearbuf();
			}
		else if(countin<3)	//if input is not in correct format
			{
			vfail=1;
			printf("*** Enter in forms of \"00:00:00\". Try again!\n");
			clearbuf();
			}
		else if(newline != '\n') //if there input is not end with number
			{
			vfail=1;
			printf("*** Trailing characters. Try again!\n");
			clearbuf();
			}
		else if(hh>23 || mm>59 || ss>59 || hh<0 || mm<0 || ss<0) //if any time value is not in range
			{
			vfail=1;
			printf("*** Out of Range. Try again!\n");
			}
			
		return vfail; // if vfail=1 : not valid / vfail=0 : Good input
	}

//output for show time	
//
void showTime(int h1, int m1, int s1, int p, int h2, int m2, int s2, int h3, int m3, int s3)
	{
	printf("%02d:%02d:%02d %c %02d:%02d:%02d = %02d:%02d:%02d\n",h1,m1,s1,p,h2,m2,s2,h3,m3,s3);
	}


main()
	{
	//valuables
	//
	int hh1=0,hh2=0,mm1=0,mm2=0,ss1=0,ss2=0,hh3=0,mm3=0,ss3=0,perfnum,rep=1,countin=0;
	char perf, newline; //perf is valuable scan performance

	//input
	//
	while(rep!=0)
	{
		do // Input for 1st clock
			{
			printf("Enter first clock in the format of hh:mm:ss => ");	
				countin = scanf("%d:%d:%d%c",&hh1,&mm1,&ss1,&newline);
			}while(invali(hh1,mm1,ss1,newline,countin)==1);		

		do // Input for 2nd clock
			{
			printf("Enter second clock in the format of hh:mm:ss => ");
				countin = scanf("%d:%d:%d%c",&hh2,&mm2,&ss2,&newline);
			}while(invali(hh2,hh2,ss2,newline,countin)==1);
		
		//input for performance
		//
		printf("Select the operation [+/-] to perform:\n"
		       "+: addition (+),moving clock one forward by the time shown on clock two.\n"
		       "-: subtraction (-), moving clock on backward by the time shown on clock two.\n"
		       "select [+/-] => ");
			scanf(" %c", &perf);
	//Change char into number +=1, otherwise=0
	//
	perfnum = (perf=='+')?1:0;
	
	//Calculation of time based on perfnum
	//
	if(perfnum==1)
		{	//Addition
		hh3=hh1+hh2;
		mm3=mm1+mm2;
		ss3=ss1+ss2;
		}
	else
		{	//Substraction
		hh3=hh1-hh2;
		mm3=mm1-mm2;
		ss3=ss1-ss2;
		}

	//Adjust time if result exceed or below 0
	//
	if(ss3>59)
		{
		ss3=ss3-60; // if second over 60 then -60 and +1 for min
		mm3=mm3+1; 
		}
	if(ss3<0)
		{
		ss3=ss3+60; // if second less 0 then +60 and -1 from min
		mm3=mm3-1;
		}
	if(mm3>59)
		{
		mm3=mm3-60;
		hh3=hh3+1;
		}
	if(mm3<0)
		{
		mm3=mm3+60;
		hh3=hh3-1;
		}
	if(hh3>23)
		{
		hh3=hh3-24;
		}
	if(hh3<0)
		{
		hh3=hh3+24;
		}
	
	//output of result in form of 00:00:00 (+/-) 00:00:00 = 00:00:00 by using showTime
	//
	showTime(hh1,mm1,ss1,perf,hh2,mm2,ss2,hh3,mm3,ss3);
	
	//Repeat Program by prompt user to input 1 or 0
	//
	printf("Try again? [1/0] [1: yes, 0: no] => ");
		scanf("%d", &rep);

	printf("\n\n"); // New line to distinct from privious run
	
	}
}
	
