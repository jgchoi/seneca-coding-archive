
#include "Messages.h"
namespace w5{
	//Virtual Functions
	//Twitter
	void Twitter::display(std::ostream& os) const{
		os << "Twitter\n";
		os << " User  : " << user << "\n";
		if(!reply.empty())
		os << " Replay: " << reply << "\n";
		os << " Tweet : " << tweet << "\n";
	}
	iMessage* Twitter::clone() const{
		return new Twitter(*this);
	}
	bool Twitter::empty() const{
		if (user.empty() && tweet.empty())
			return true;
		return false;
	}

	//eMail
	void eMail::display(std::ostream& os) const{
		os << "eMail\n";
		os << " From  : " << from << "\n";
		os << " To    : " << to << "\n";
		os << " Date  : " << date << "\n";
		os << " Body  : " << body << "\n";
	}

	iMessage* eMail::clone() const{
		return new eMail(*this);
	}
	bool eMail::empty() const{
		if (from.empty() && to.empty() && date.empty() && body.empty())
			return true;
		return false;
	}
	
	//constructor
	
	Twitter::Twitter(std::ifstream& is, char recDelim){
		getline(is, user, recDelim);

		//test if it is incomplate
		if (user.length() == 1){
			//no username & tweet exist
			user.clear();
			tweet.clear();
			reply.clear();
		}
		if (user.length() < user.find(' ')){
			//no tweet
			user.clear();
			tweet.clear();
			reply.clear();
		}
		else if(user.find(" @ ") < user.length()){
			//empty reply exist
			user.clear();
			tweet.clear();
			reply.clear();
		}
		else{
			//valid
			//check for reply

			
			tweet = user.substr(user.find(' ')+1);
			if(tweet.find("@")<tweet.length()){
			reply = tweet.substr(1, tweet.find(' ')-1);
			tweet = tweet.substr(tweet.find(' ')+1);
			}
			user = user.substr(1, user.find(' ') - 1);
		}
		
		
			
		
	}

	eMail::eMail(std::ifstream& is, char recDelim){
		getline(is, from, recDelim);
		if (from.length() == 1){
		//string is emplty except front 'e'
			from.clear();
			to.clear();
			date.clear();
			body.clear();
		}
		else if (from.find("eFrom:") > from.length() ||
			from.find(" To:") > from.length() ||
			from.find(" Date:") > from.length() ||
			from.find(" Body:") > from.length() ){
			//any of those 4 titles are missing;
			from.clear();
			to.clear();
			date.clear();
			body.clear();
		}
		else if (from.length() < 47){
		//If entry is less than smallest possible complete entry
		//eFrom:a@a.c To : a@a.c Date : 12345678 Body : a (47 char)
		from.clear();
		to.clear();
		date.clear();
		body.clear();
		}
	else {
		//valid
		body = from.substr(from.find(" Body:")+6);
		from = from.substr(0,from.find(" Body:"));
		date = from.substr(from.find(" Date:")+6);
		from = from.substr(0,from.find(" Date:"));
		to = from.substr(from.find(" To:")+4);
		from = from.substr(6,from.find(" To:")-6);
	}
	}
		

	//helper function
	iMessage* getMessage(std::ifstream& is, char recDelim){
		std::string temp;

		int currentPos = is.tellg();
		if (currentPos >= 0){
			getline(is, temp, recDelim);
		


		if (temp.front() == 'T'){
			is.seekg(currentPos, is.beg);
			Twitter t(is, recDelim);
			return t.clone();
		}
		else if (temp.front() == 'e'){
			is.seekg(currentPos, is.beg);
			eMail e(is, recDelim);
			return e.clone();
		}
else
		return nullptr;
		}else return nullptr;
	}
}