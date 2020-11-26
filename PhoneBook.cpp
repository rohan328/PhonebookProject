#include "PhoneBook.h"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	head = NULL;
	tail = NULL;
	size = 0;
}

PhoneBook::~PhoneBook() {
	destructPhoneBook(head);
}

void PhoneBook::display() {
	PBnode *temp = head;
	for (int i = 1;i <= size;i++) {
		cout <<setw(4)<<i<<". "
			<<*temp<<endl;
		temp = temp->next;
	}
}

void PhoneBook::searchByFName() {
}

void PhoneBook::searchByLName() {
}

void PhoneBook::searchByEmail() {
}

void PhoneBook::add() {
	PBnode *temp = new PBnode("Rohan", "Ohlan", "rrr", "555");
	insertEnd(temp);
}

void PhoneBook::update() {
}

void PhoneBook::deleteE() {
	display();
}

void PhoneBook::save() {
}

void PhoneBook::restore() {
	cout << "restore";
}

void PhoneBook::deleteAll() {
	destructPhoneBook(head);
	head = NULL;
	tail = NULL;
	size = 0;
}

void PhoneBook::insertEnd(PBnode *data) {
	if (head == NULL) {
		head = data;
		tail = data;
		size++;
		return;
	}
	tail->next = data;
	data->prev = tail;
	tail = data;
	size++;
}

void PhoneBook::destructPhoneBook(PBnode *x) {
	if (x->next == NULL) {
		return;
	}
	destructPhoneBook(x->next);
	delete x;
}

