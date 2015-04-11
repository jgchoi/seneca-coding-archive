//GS1Prefix.cppw
//
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

		if(p->area[i]==area) //match area in database with database parameter
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
				return p->pubLen[i];} //return minimum digit
			}
 
	return 0;
 }
 
 bool isRegistered(const Prefix* p, int area, const char* publisher)
 {
int i; int j; int pubSize = 0;
 long long int pubNum=0, pubHghNum=0, pubLowNum=0;
 
 //calculate publisher size
	for(i=0;publisher[i]!='\0';i++)
		{
		pubSize++;
		}
 
 
 //check publisher
	for(i=0;i<p->no;i++)
		{
		if(p->area[i] == area) //same area code
			{
			if(p->pubLen[i] == pubSize) //same pub length
				{
				for(j=0;j<pubSize;j++)
					{//switch into int
					pubNum = pubNum * 10;
					pubHghNum = pubHghNum * 10;
					pubLowNum = pubLowNum * 10;
					
					pubNum += publisher[j];
					pubHghNum += p->pubHgh[i][j];
					pubLowNum += p->pubLow[i][j];
					}
					
				//compare value
					if(pubNum <= pubHghNum && pubNum >= pubLowNum) //value is match
						{
						return true;
						}	
				}
			
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