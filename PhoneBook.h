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
	void deleteE(int);
	void save();
	void restore();
	void deleteAll();

private:
	//functions
	void insertEnd(PBnode*); 
	void insertInOrder(PBnode*); //sorts by firstname
	void destructPhoneBook(PBnode*); // deletes all the dynamically allocated nodes

	//data
	PBnode* head;
	PBnode* tail;
	int size;
};

