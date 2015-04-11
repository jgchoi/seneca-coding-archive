/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop6
 * Name			- Jung Geon Choi
 * File name		- w6
 * Due date		- Oct.29, 2013
 * Game of Dice : You win if you get your sought with less throw!
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//prototypes
int getnum();
int throw(int trial);

int main(void)
{
	//valuables
	int goal = 0, trial = 0, dice_val = 0;

	//program title
	printf("Game of Dice\n"
	       "============\n");

	//Get number between 2~12
	goal = getnum();

	//Rolling
	do
		{
		trial++;
		dice_val = throw(trial);
		sleep(1);
		}
	while(dice_val < goal);
//End program with output
	printf("You got your total in %d throws!\n", trial);
	return 0;
}

//Output 2 Dice value, return total value
int throw(int trial)
{
		//rand seeding by time
		srand(time(NULL));
		
		//valuables
		int dice1=0, dice2=0, max=6, min=1, total=0;
		
		//dice
		dice1 = min + (rand()%(max+1-min));
		dice2 = min + (rand()%(max+1-min));
			
		//total to return
		total = dice1 + dice2;
		
		//output
		printf("Result of throw  %2d : %d + %d \n", trial, dice1, dice2);

	return total;
}

//Get integer between 2~12 and invalid other inputs
int getnum()
{
	//valuable
	int num = 0, r = 0;
	int range_min = 2, range_max = 12;
	char check = 0;

	do
		{
		printf("Enter total sought : ");
		
		r = scanf("%d%c", &num, &check);
		
		//Only accept integer input value between 2~12 otherwise return 0
		if(r==2 && num>=range_min && num<=range_max && check=='\n');
		else
			{
			num = 0;
			printf("*** Invalid Input. Try Again ***\n");
			if(check!='\n' || r==0) // in case of trailing char input or non \n, clear buffer
				while(getchar()!='\n');
			}
		}
	while(num==0);
	
	return num;
}
