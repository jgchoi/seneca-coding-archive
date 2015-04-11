//GS1Prefix.cppw
//
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

#define PREFIX_LIST "prefixRanges.txt"
#include "GS1Prefix.h"
#include "EAN.h"

bool Prefix::isRegistered(int are) const
 {
	int i;

	for(i=0;i<MAX;i++)
		{
		if(area[i]==are) //match area in database with database parameter
			return true;
		}
	return false;
 }

int Prefix::minNoDigits(int are) const
 {
	int i;
	for(i=0;i<MAX;i++)
		{
		if(area[i]==are)
			return pubLen[i]; //return minimum digit
		}
			
	return 0;
 }
 
bool Prefix::isRegistered(int are, const char * pub) const
{
	int i; int j; int pubSize = 0;
	long long int pubNum=0, pubHghNum=0, pubLowNum=0;
 
	//calculate publisher size
	for(i=0;pub[i]!='\0';i++)
		{
		pubSize++;
		}

	
	//check publisher
	for(i=0;i<no;i++)
		{
		if(area[i] == are) //same area code
			{
			if(pubLen[i] == pubSize) //same pub length
				{
				for(j=0;j<pubSize;j++)
					{
					//switch into int
					pubNum = pubNum * 10;
					pubHghNum = pubHghNum * 10;
					pubLowNum = pubLowNum * 10;
					
					pubNum += pub[j]-'0';
					pubHghNum += pubHgh[i][j]-'0';
					pubLowNum += pubLow[i][j]-'0';
					}

				//compare value
				if(pubNum <= pubHghNum && pubNum >= pubLowNum) //value is match
					{
					return true;
					}	
				
				//reset value if fail
				pubHghNum=0;
				pubLowNum=0;
				pubNum=0;
				}
			}
		}
	return false; //if still can't find
 }


 // load copies the prefix table from filename into *p
 //
 Prefix::Prefix(const char* filename) {
     if (filename != nullptr) {
         std::ifstream file(filename);
         if (file.is_open()) {
             no = 0;
             while (file.good()) {
                 file >> area[no] >> pubLow[no] >> pubHgh[no]; 
                 if (file.good()) {
                     pubLen[no] = std::strlen(pubLow[no]);
                     no++;
                 }
             }
             if (no > 0) {
                 no = no;
             }
         }
     }
 }
