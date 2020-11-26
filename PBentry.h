#pragma once
#include <string>
using namespace std;

class PBentry {
	friend ostream& operator<<(ostream&, PBentry&);

public:
	PBentry(string, string,string="",string="");

	// mutators/setters
	bool setFirstName(string);
	bool setLastName(string);
	bool setEmail(string);
	bool setPhoneNumber(string);

	// accessors/getters
	string getFirstName();
	string getLastName();
	string getEmail();
	string getPhoneNumber();

private:
	string firstName;
	string lastName;
	string email;
	string phoneNumber;
};


class PBnode : public PBentry {
public:
	PBnode(string, string, string = "", string = "");

	PBnode* next;
	PBnode* prev;
};
