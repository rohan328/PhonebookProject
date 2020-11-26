#pragma once
#include "PBentry.h"

class PhoneBook {

public:
	PhoneBook();
	~PhoneBook();

	void display();
	void searchByFName();
	void searchByLName();
	void searchByEmail();
	void add();
	void update();
	void deleteE();
	void save();
	void restore();
	void deleteAll();

private:
	//functions
	void insertEnd(PBnode*); // for testing purposes
	void destructPhoneBook(PBnode*); // deletes all the dynamically allocated nodes

	//data
	PBnode* head;
	PBnode* tail;
	int size;
};

