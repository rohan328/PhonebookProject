#pragma once
#include <string>

using namespace std;

class PBentry {
public:
	PBentry(string, string,string="",string="");
	
	bool setFirstName(string);
	bool setLastName(string);
	bool setEmail(string);
	bool setPhoneNumber(string);


private:
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
};


class PBnode : PBentry {

private:
	PBnode* next;
	PBnode* prev;
};
