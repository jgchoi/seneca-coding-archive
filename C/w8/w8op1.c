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
int main(void)
{
	//valuable
	char input[MAX_WORD_SIZE]={0};
	
	//title
	p_title();
	
	//input
	printf("Text to be cleaned  : ");
		scanf("%100[^\n]",input);
	cleaner(input);
	
	//output
	printf("Cleaned text        : %s\n",input);
	
	//end
	return 0;
}

//-----------------------------------------------------------------------------
void cleaner(char input[])
{
	int al_white=0;
	int i=0;
	int j=0;
	int i_reset=0;

	while(input[i]!='\0')
		{
		if(input[i]=='\n' || input[i]=='\t' || input[i]=='\f' || input[i]=='\v'||input[i]==' ')
			{
			if(i==0)
				{
				for(i=0;input[i]!='\0';i++)
					{
					input[i]=input[i+1];
					}
				i_reset=1;
				}
			else 
			if(al_white==1)
				{
				for(j=i;input[j]!='\0';j++)
					{
					input[j]=input[j+1];
					}
				i_reset=1;
				}
			else
				{
				al_white=1;
				}
			}
		else //char
			{
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
	printf("Text Cleaner\n"
		   "============\n");
}
