#pragma once
#include "PBentry.h"

class PhoneBook {
public:
	PhoneBook();


private:
	PBnode* head;
	PBnode* tail;
	int size;
};

