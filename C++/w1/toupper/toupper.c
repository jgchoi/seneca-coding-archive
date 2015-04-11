#include <stdio.h>

int main(void)
{
printf("Enter string : ");
char string[25];
scanf("%[^\n]",string);
int i=0;
i=convert(string);
printf("%s\n",string);
printf("%d\n",i);
return 0;
}

int convert(char alphabets[])
{
int i;
int j=0;
for(i=0;alphabets[i]!='\0';i++)
	{
	if(alphabets[i]>='a' && alphabets[i]<='z')
		{
		alphabets[i]-=32;
		j++;
		}
	//	printf("%s\n",alphabets);
	}
	return j;
}
