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


bool load(const char* filename, Prefix* p);
bool isRegistered(const Prefix* p, int area);
int minNoDigits(const Prefix* p, int area);
bool isRegistered(const Prefix* p, int area, const char* publisher);


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
		//	cout << "eanNum is " << eanNum << " str[i] is " << str[i] << endl;
			}
		

//cout << "eanNum is " << eanNum << endl;

	//conversion finished. 978	070002046
	//9070002046
	//1000000000
// 0~7 (1 digit) 80~92 (2digit) 950~989 / 9946 ~9989 / 99901 ~99944

		//select area code
		if(eanNum/1000000000 <=7)
			{
			areaNum = eanNum/1000000000;
			areaDigit =2;
			}
		else if(eanNum/100000000 <= 92)
			{
			areaNum = eanNum/100000000;
			areaDigit = 3;
			}
		else if(eanNum/10000000 <989)
			{
			areaNum = eanNum/10000000;
			areaDigit = 4;
			}
		else if(eanNum/1000000 <9989)
			{
			areaNum = eanNum/1000000;
			areaDigit = 5;
			}
		else if(eanNum/100000 <99944)
			{
			areaNum = eanNum/100000;
			areaDigit = 6;
			}
//cout << "area code found is " << areaNum << endl;

// check area digit
	if(isRegistered(p, areaNum)==false)
		return false;

// find pub digit
	pubDigit = minNoDigits(p, areaNum);
//cout << "pubDigit is " << pubDigit << endl;
//cout << "area digit is " << areaDigit << endl;

while(isRegistered(p, areaNum, pub)==false){

	i=areaDigit+2;
	j=areaDigit+pubDigit+2;
// publisher string creation
	do
		{
		pub[i-areaDigit-2] = str[i];
cout << "for i as " << i << endl;
cout << "for j as " << j<< endl;
cout << "pub[i] : str [i] " << pub[i-areaDigit] << " : " << str[i] << endl;
		i++;
		}while(i<j);
	pub[i-areaDigit]='\0';
	
	pubDigit = pubDigit + 1 ;	
	if(pubDigit == 13)
		return false;
	}



//cout << "publisher code is " << pub << endl;
	
	/*/check publisher
	if(isRegistered(p, areaNum, pub)==false)
		return false;*/
//geet publisehr code


//copy title
	do{
//cout << "for i as " << i << endl;
//cout << "for j as " << j<< endl;
//cout << "tit[i] : str [i] " << tit[i] << " : " << str[i] << endl;
	tit[i-j]=str[i];
	i++;
	}while(i<12);
tit[i-j]='\0';
//cout << "title is " << tit << endl;

i=areaDigit - 2;
for(i;i>=0;i--)
	{//cout << "area[i] is " <<area[i] << ":: Area Num is " <<areaNum << endl;
	are[i]=(areaNum%10)+'0';
	areaNum=areaNum/10;
//cout << "area[i] is " <<area[i] << ":: Area Num is " <<areaNum << endl;
	}
	
	are[areaDigit-1]='\0';






//cout << "area is " << are[0] << endl;
//copy all values
strcpy(publisher,pub);
strcpy(title,tit);
strcpy(area,are);
return true;
}