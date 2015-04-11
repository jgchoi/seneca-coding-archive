/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop8
 * Name			- Jung Geon Choi
 * File name		- w8
 * Due date		- Nov. 19, 2013
 * Word Counter : Count number of words
 */
 
#include <stdio.h>
#define MAX_WORD_SIZE 100

//-----------------------------------------------------------------------------
//prototypes
void p_title(void);
int wordCount(char input[]);


//-----------------------------------------------------------------------------
//main
int main(void)
{
	//---- (valuable) -------------------------------------------
	char input[MAX_WORD_SIZE] = {0};
	
	//---- (title) ----------------------------------------------
	p_title();
	
	//---- (input) ----------------------------------------------
	printf("Text to be analyzed : ");
		scanf("%100[^\n]",input);
		
	//---- (count word) -----------------------------------------
	printf("Word count          : %d\n",wordCount(input));
	
	//---- (end) ------------------------------------------------
	return 0;
}

//-----------------------------------------------------------------------------
//wordCount : Counter number of word in the string
int wordCount(char input[])
{
	//---- (valuable) -------------------------------------------
	int al_word = 0; // 1=previous string is already a word 
	int i = 0; // simple loop counter
	int count_word = 0; // if(changes from "white" to "word" ++;
	
	//---- (count) ----------------------------------------------
	for(i=0;input[i]!='\0';i++) // loop till end of string
		{
		if(input[i]=='\n' || input[i]=='\t' || input[i]=='\f' ||
		   input[i]=='\v'||input[i]==' ') // if(any white spaces)
			{
			al_word=0;
			}
		else // string is word
			{
			if(al_word==1) //(looping within same word, no change)
				{
				;
				}
			else
			if(al_word==0) //it is new word followed by blank
				{
				count_word++;
				al_word=1;
				}
			} //if else end
		} // loop end
	return count_word;
}

//-----------------------------------------------------------------------------
//"P"rint Title
void p_title(void)
{
	printf("Word Counter\n"
	       "============\n");
}

