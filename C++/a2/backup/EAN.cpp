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

EAN::EAN(){	
		ean[0]='\0';
		area[0] = '\0';
		publisher[0] = '\0';
		title[0] = '\0';
}


bool EAN::read(std::istream & is, const Prefix & list)
{
	int keepgoing;
 
    keepgoing = 1;
        do {
            std::cout << "EAN (0 to quit) : ";
            std::cin.getline(ean, 14);
            if (!std::cin) {
                std::cin.clear();
                std::cin.ignore(2000, '\n');
                std::cerr << "Error. Try Again " << std::endl;
            }
            else if (std::strcmp(ean, "0") == 0) {
                keepgoing = 0;
				return false;
            }
            else if (std::strlen(ean) != 13) {
                std::cerr << " Incorrect number of digits. Try again." << std::endl;
            }
            else if (isValid(ean) == 0) {
                std::cerr << " Invalid check digit. Try again." << std::endl;
            }
            else if (isRegistered(list) == 0) {
                //std::cerr << " This EAN does not have a registered prefix."
                // << std::endl;
				s='\n';
				keepgoing = 0;
				return true;
            }
            else {
                keepgoing = 0;//
				s='-';
				return true;
            }
        } while (keepgoing == 1);

}

void EAN::display(std::ostream & os) const
{	char eanWithStyle[18];
	toStrWithStyle(eanWithStyle);
	cout << setw(17) << right << eanWithStyle;
}


void EAN::toStrWithStyle(char * str) const
{	int i;
	//prefix-area-publisher-title-check
	//check registered

	if(s != '-' && s != ' ')
		{
		strcpy(str,ean);
		}
	else
		{
		//copy prefix
		for(i=0;i<3;i++)
			{
			str[i]=ean[i];
			}
		//add style char
		str[i]=s;	//3
		i++;	
		str[i]='\0';//4
		
		//area
		strcat(str,area);
		//add style
		str[strlen(area)+i]=s; //4
		i++;
		str[strlen(area)+i]='\0';//5
		
		//publisher
		strcat(str,publisher);
		//add style
		str[strlen(area)+strlen(publisher)+i]=s;//5
		i++;
		str[strlen(area)+strlen(publisher)+i]='\0';//6
		
		//title
		strcat(str,title);
		//add style
		str[strlen(area)+strlen(publisher)+strlen(title)+i]=s;
		i++;
		str[strlen(area)+strlen(publisher)+strlen(title)+i]='\0';
		
		//check digit
		str[16]=ean[12];
		str[17]='\0';
		}

}

void EAN::toStr(char * str) const
{
	strcpy(str,ean);
}



bool EAN::empty() const
{	
	if(ean[0]=='\0')
		return true;
	else
		return false;
}

bool EAN::isRegistered() const
{	
	
	if(area[0] != '\0' && publisher[0] != '\0' && title[0] != '\0')
		return true;
	else
		return false;

}

void EAN::style(char c)
{
	if(c != '-' && c != ' ' && c != '\n' && c != '0')
		s = '\0';
	else
		s = c;
}

EAN::EAN(const char * str, const Prefix & list){
	strcpy(ean,str);

	s='-';
	//validation
	if(isValid(str)==false)
		{
		ean[0]='\0';
		area[0] = '\0';
		publisher[0] = '\0';
		title[0] = '\0';
		}
	else if(isRegistered(list)==false)//registration
		{
		area[0] = '\0';
		publisher[0] = '\0';
		title[0] = '\0';
	}
}


bool EAN::isRegistered(const Prefix & list)
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
			eanNum = (eanNum * 10) + (ean[i]-'0');
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
	if(list.isRegistered(areaNum)==false)
		return false;

// get minimum digit
	pubDigit = list.minNoDigits(areaNum);


	//validate pub value
	do{

			//write publisher from str
			for(i=0;i<pubDigit;i++)
				{
				pub[i]=ean[areaDigit+2+i];
				}
			//adding \0
			pub[i] = '\0';

		pubDigit++;

			//terminate if publisher code is more than 7
			if(pubDigit > 8)
				{//cout << "pub range over " << endl; 
				return false;}

		}while(list.isRegistered(areaNum, pub) == false);

	//copy title value
	i = areaDigit + pubDigit + 1;

		for(j=0;i<12;j++)
			{
			tit[j]=ean[i];
			i++;
			}
		tit[j]='\0';


	are[areaDigit-1] = '\0';
	//convert eanNum to eaning are
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

