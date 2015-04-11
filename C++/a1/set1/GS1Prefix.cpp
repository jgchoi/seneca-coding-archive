#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#define  PREFIX_LIST "prefixRanges.txt"
#include "GS1Prefix.h"
#include "EAN.h"

using namespace std;

 bool isRegistered(const Prefix* p, int area)
 {
	int i;

	for(i=0;i<MAX;i++)
		{

		if(p->area[i]==area)
			return true;
		}
	return false;
 }

 int minNoDigits(const Prefix* p, int area)
 {
	int min=0;
	int i;
		for(i=0;i<MAX;i++)
			{
			if(p->area[i]==area)
				{
				return p->pubLen[i];}
			}
 
	return 0;
 }
 
 bool isRegistered(const Prefix* p, int area, const char* publisher)
 {
	int i; int j; int k;
	long long int pubLen=0, pubNum=0, pubhNum=0, publNum=0;
	int givenLen = 0;
cout << publisher << "  publisher value " << endl;
	for(i=0;publisher[i]!='\0';i++)
	{ givenLen++;	}
	
	for(i=0;i<MAX;i++)
	{
	if(p->area[i] == area && givenLen == p->pubLen[i])
		{
		pubLen = p->pubLen[i];
		pubNum = 0;
		pubhNum = 0;
		publNum = 0;
		for(j=0;j<pubLen;j++)
			{
				pubNum = pubNum*10;
				pubhNum = pubhNum*10;
				publNum = publNum *10;
				
				pubNum = pubNum + publisher[j]-'0';
				pubhNum = pubhNum + p->pubHgh[i][j]-'0';
				publNum = publNum + p->pubLow[i][j]-'0';
			}	
			
			cout << pubNum << " : " << pubhNum << " : " << publNum << endl;	
			if(pubLen == 1 && pubNum <= pubhNum && pubNum >= publNum)
				{return true;}
			if(pubNum <= pubhNum && pubNum >= publNum)
				{return true;}
			
		}
	}
	return false;
 }


 // load copies the prefix table from filename into *p
 //
 bool load(const char* filename, Prefix* p) {
     bool rc = false;
     if (filename != nullptr) {
         std::ifstream file(filename);
         if (file.is_open()) {
             int no = 0;
             while (file.good()) {
                 file >> p->area[no] >> p->pubLow[no] >> p->pubHgh[no]; 
                 if (file.good()) {
                     p->pubLen[no] = std::strlen(p->pubLow[no]);
                     no++;
                 }
             }
             if (no > 0) {
                 rc = true;
                 p->no = no;
             }
         }
     }
     return rc;
 }