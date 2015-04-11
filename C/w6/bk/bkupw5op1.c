#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char get_suit();
char get_rank();
void draw_card(char *p_suit,char *p_rank);

main()
{
	//title
	printf("Card Draw\n"
		   "=========\n");
		   
	//valuables
	int repeat=0;
	char suit=0, rank=0, goal_rank=0, goal_suit=0;
	
	//input
	do
		{
		printf("Enter Suit : ");
		goal_suit = get_suit();
		}
	while(goal_suit==0);
	
	do
		{
		printf("Enter Rank : ");
		goal_rank = get_rank();
		}
	while(goal_rank==0);

	//draw cards
	do
		{
		repeat++;	
		draw_card(&suit, &rank);
		sleep(1);
		printf("Result of draw    %3d : %c%c%c\n",repeat,rank=='0'?'1':' ',rank,suit);
		}
	while(goal_suit != suit || goal_rank != rank);
	
	//Last output
	printf("You drew your card in %d draws!\n", repeat);
	

}

char get_rank() //input char (#1-10,J,Q,K) otherwise invalid
{
	//valuables
	char digit1=0, digit2=0, result=0;
	int valid_pass=0, count =0;
	//input
	count = scanf("%c%c", &digit1, &digit2);
	
	//validation
	if(digit1>47 && digit1<58 && digit2=='\n')
		{
		valid_pass=1;
		result = digit1;
		}
	if(digit1 == 74 || digit1 == 81 || digit1 == 75)
		{
		if(digit2 == '\n')
			{
			valid_pass=1;
			result = digit1;
			}
		}
	if(digit1 == 49 && digit2 == 48)
		{
		valid_pass=1;
		result = 48; //10=0
		}
	if(valid_pass==0 )
		{
		result = 0;
		printf("*** Please don't waste my time***\n\n");
		if(count ==2 && digit1 !='\n' && digit2 != '\n')
			{
			while(getchar()!='\n');
			}
		}
	return result;
}

char get_suit() // input C D H S otherwise invalid
{	//valuables
	char digit1=0, digit2=0, result=0;
	int valid_pass=0, count =0;
	//input
	count = scanf("%c%c", &digit1, &digit2);
	
	//validation
	if(digit1 == 67 || digit1 == 68 || digit1==72 ||digit1==83)
		{
		if(digit2 == '\n')
			{
			valid_pass=1;
			result = digit1;
			}
		}
	if(valid_pass==0)
		{
		result = 0;
		printf("*** Please don't waste my time***\n\n");
		if(count ==2 && digit1 !='\n' && digit2 != '\n')
			{
			while(getchar()!='\n');
			}
		}
	return result;
}

void draw_card(char *p_suit,char *p_rank)
{
	int suit_min = 0, suit_max = 3, rank_min = 0, rank_max = 13;
	int suit=0, rank=0;

	srand(time(NULL));
	suit = suit_min + (rand()%(suit_max+1-suit_min));
	rank = rank_min + (rand()%(rank_max+1-rank_min));
	
	switch(suit)
	{
	case 0 :
		*p_suit = 'C';
		break;
	case 1 :
		*p_suit = 'D';
		break;
	case 2 :
		*p_suit = 'H';
		break;
	case 3 :
		*p_suit = 'S';
		break;
	deafult :
		;
	}
	
	switch(rank)
	{
	case 0 :
		*p_rank = 48;
		break;
	case 1 :
		*p_rank = 49;
		break;
	case 2 :
		*p_rank = 50;
		break;
	case 3 :
		*p_rank = 51;
		break;
	case 4 :
		*p_rank = 52;
		break;
	case 5 :
		*p_rank = 53;
		break;
	case 6 :
		*p_rank = 54;
		break;
	case 7 :
		*p_rank = 55;
		break;
	case 8 :
		*p_rank = 56;
		break;
	case 9 :
		*p_rank = 57;
		break;
	case 10 : // J
		*p_rank = 74;
		break;
	case 11 : // Q
		*p_rank = 75;
		break;
	case 12 : // K
		*p_rank = 81;
		break;
	}
}