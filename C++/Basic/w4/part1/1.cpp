#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class CreditCard {
	long long int cardNum;
	char cardHolder[21];
	double bal;
	
	public : 
		//constructors
		CreditCard();
		CreditCard(long long int num, char * name);
		
		//memberfunctions
		void charge(double c);
		void pay(double p);
		long long number() const;
		double balance() const;
		const char * name() const;
		};
		
		//---- ( main ) -------------------------------------------------------
		//
		int main() {
     CreditCard card(1234, "John Doe"), empty;
     double x;
     char option;

     do {
         cout << "Select (C, P or Q) : ";
         cin >> option;
         switch (option) {
         case 'C':
         case 'c':
             cout << "Charge : ";
             cin >> x;
             card.charge(x);
             break;
         case 'P':
         case 'p':
             cout << "Payment : ";
             cin >> x;
             card.pay(x);
             break;
         }
     } while (option != 'Q' && option != 'q');

     cout << "Number  " << card.number()  << endl;
     cout << "Name    " << card.name()    << endl;
     cout << "Balance " << card.balance() << endl;

     cout << "Number  " << empty.number()  << endl;
     cout << "Name    " << empty.name()    << endl;
     cout << "Balance " << empty.balance() << endl;
 }
 
void CreditCard::charge(double c){
	bal = bal + c;
}
	
void CreditCard::pay(double p){
	bal = bal - p;
}

long long CreditCard::number() const{
	return cardNum;
}

double CreditCard::balance() const{
	return bal;
}

const char * CreditCard::name() const{
	return cardHolder;
}

CreditCard::CreditCard(){
	strcpy(cardHolder,"\0");
	cardNum = 0;
	bal = 0;	
}


CreditCard::CreditCard(long long int num, char * name){
	strcpy(cardHolder, name);
	cardNum = num;
}