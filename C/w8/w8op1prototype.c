/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop8
 * Name			- Jung Geon Choi
 * File name		- w8op1
 * Due date		- Nov. 19, 2013
 * Word Cleaner : Remove unwanted spaces!
 */

#include <stdio.h>
#define MAX_WORD_SIZE 100
//-----------------------------------------------------------------------------
//prototypes
void cleaner(char input[]);
void p_title(void);

//-----------------------------------------------------------------------------
//main
int main(void)
{
	//valuable
	char input[MAX_WORD_SIZE];
	
	//title
	p_title();
	
	//input
	printf("Text to be analyzed : ");
		scanf("%[^\n]",input);

	cleaner(input);

	printf("***%s***\n",input);
	
	//end
	return 0;
}
void cleaner(char input[])
{
	int al_white=0;
	int i=0;
	int j=0;
	char temp=0;
	int count_word=0;
	int i_reset=0;

	while(input[i]!='\0')
		{
		printf("input start point \"%c\"\n",input[i]); //-----------------------------------
		printf("value of [i] = %d\n\n",i); //---------------------
		if(input[i]=='\n' || input[i]=='\t' || input[i]=='\f' || input[i]=='\v'||input[i]==' ')
			{
			if(i==0)
				{
				printf("this is only if initial is space\n");//-----------------------------------
				for(i=0;input[i]!='\0';i++)
					{
					printf("This is %dth i shift\n",i);//-----------------------------------
					printf("Value of input[%d] is %c \n",i,input[i]);//-----------------------------------
					input[i]=input[i+1];
					}
					printf("This is %dth i shift\n",i);//-----------------------------------
					printf("Value of input[%d] is %c \n",i,input[i]);//-----------------------------------
					i_reset=1;
					printf("value of [i] = %d\n",i); //---------------------
				}
			else 
			if(al_white==1)
				{ printf("this is when already white\n");//-----------------------------------
				for(j=i;input[j]!='\0';j++)
					{
					printf("j shift\n");//-----------------------------------
					input[j]=input[j+1];
					}
				i_reset=1;
				}
			else
				{
				printf("First point of finding white\n");//-----------------------------------
				al_white=1;
				}
			}
		else //char
			{
			printf("input is char\n");//-----------------------------------
			al_white=0;
			}
			
		if(i_reset==1)
			{
			i_reset=0;
			i=0;
			}
		else
			{
			i++;
			}
			
		}
}

void p_title(void)
{
	printf("Word Counter\n"
		   "============\n");
}

