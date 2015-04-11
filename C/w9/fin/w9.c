/*
 * Course Code 		- BTP100
 * Assignment Number	- Workshop Week 9
 * Name			- Jung Geon Choi
 * File name		- w9
 * Due date		- Dec. 03, 2013
 * Text file case changer : change English text file contact to upper/lower
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 40

//-----------------------------------------------------------------------------
//Print program title
void p_title(void)
	{
		printf("Change Case\n"
			   "===========\n");
	}
	
int main(void)
{
	//---- (valuables)
	FILE *p_input = NULL;
	FILE *p_output= NULL;
	char original_file[MAX_SIZE]={"\0"};
	char updated_file[MAX_SIZE]={"\0"};
	char line[MAX_SIZE]={"\0"};
	char perf = 0;
	int i;
	
	//---- (input)
	printf("Case (U for upper, L for lower) : ");
		scanf(" %c",&perf);
	printf("Name of the original file : ");
		scanf("%s",original_file);
	printf("Name of the updated file  : ");
		scanf("%s",updated_file);
		
	//---- (open files)
	p_input = fopen(original_file,"r");
	p_output= fopen(updated_file,"w");
	
	//---- (change opened file)
	if(p_input==NULL)//fail to open the file
		{
		printf("Can not find file name : \"%s\"\n",original_file);
		return 1;
		}
	else//successfully find the file
		{
		if(perf=='U')//change to upper
			{
			while(fgets(line,MAX_SIZE,p_input)!=NULL)
				{
				for(i=0;i<MAX_SIZE;i++)
					{
					line[i]=toupper(line[i]);
					fprintf(p_output, "%c",line[i]);
					}
				}
			}
		else//change to lower
			{
			while(fgets(line,MAX_SIZE,p_input)!=NULL)
				{
				for(i=0;i<MAX_SIZE;i++)
					{
					line[i]=tolower(line[i]);
					fprintf(p_output, "%c",line[i]);
					}
				}
			}
		}
	//---- (close)
	fclose(p_input);
	fclose(p_output);
	printf("Text has been updated and stored in %s \n",updated_file);
}