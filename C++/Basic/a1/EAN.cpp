//EAN.cpp
//
#include <iostream>
#include <iomanip>
#include <cstring>

#define  PREFIX_LIST "prefixRanges.txt"
#include "GS1Prefix.h"
#include "EAN.h"

using namespace std;

bool isValid(const char* str)
{
int testFail = 0;
int i;
int sum=0;

		for(i=0;i<=11;i+=2) //add even digit
			{
			sum+=str[i]-'0';
			}
		for(i=1;i<12;i+=2) //add odd digit // need *3
			{
			sum+=(str[i]-'0')*3;
			}
		sum+=str[12]-'0';
		if(sum%10 != 0)
			testFail=1;

	if(testFail == 1)
		return false;
	else
		return true;
}

bool isRegistered(const Prefix* p, const char* str, char area[], char publisher[], char title[])
{
long long int eanNum = 0;
long long int areaNum = 0;
long long int pubDigit = 0;
long long int areaDigit = 0;
int i,j,k;

char pub[8];
char tit[8];
char are[8];

	// conversion
		for(i=3;i<13;i++)
			{
			eanNum = (eanNum * 10) + (str[i]-'0');
			}

	//conversion finished.
		//select area code
		if(eanNum/1000000000 <=7 && eanNum/1000000000>=0) // 1 digit
			{
			areaNum = eanNum/1000000000;
			areaDigit =2;
			}
		else if(eanNum/100000000 <= 92 && eanNum/100000000 >= 80) // 2 digit
			{
			areaNum = eanNum/100000000;
			areaDigit = 3;
			}
		else if(eanNum/10000000 <=989 && eanNum/10000000 >=950) // 3 digit
			{
			areaNum = eanNum/10000000;
			areaDigit = 4;
			}
		else if(eanNum/1000000 <=9989 && eanNum/1000000 >=9946) // 4 digit
			{
			areaNum = eanNum/1000000;
			areaDigit = 5;
			}
		else if(eanNum/100000 <=99944 && eanNum/100000 >=99901) // 5digit
			{
			areaNum = eanNum/100000;
			areaDigit = 6;
			}
		else
			return false; // if area code is not in this category

// check publisher digit
	if(isRegistered(p, areaNum)==false)
		return false;

// get minimum digit
	pubDigit = minNoDigits(p, areaNum);


	//validate pub value
	do{

			//write publisher from str
			for(i=0;i<pubDigit;i++)
				{
				pub[i]=str[areaDigit+2+i];
				}
			//adding \0
			pub[i] = '\0';

		pubDigit++;

			//terminate if publisher code is more than 7
			if(pubDigit > 7)
				return false;

		}while(isRegistered(p, areaNum, pub) == false);

	//copy title value
	i = areaDigit + pubDigit + 1;

		for(j=0;i<12;j++)
			{
			tit[j]=str[i];
			i++;
			}
		tit[j]='\0';


	are[areaDigit-1] = '\0';
	//convert eanNum to string are
	 for(i=areaDigit-2;i>=0;i--)
		{
		are[i] = areaNum%10+'0';
		areaNum = areaNum / 10 ;
		}
	
	//at this point, all test must be passed, otherwise returned false in previous sequence
	//copy all value into main's valuables
	strcpy(area,are);
	strcpy(title,tit);
	strcpy(publisher,pub);

	return true;
}