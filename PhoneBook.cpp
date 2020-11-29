#include "PhoneBook.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>

PhoneBook::PhoneBook() {
	head = NULL;
	tail = NULL;
	size = 0;
}

PhoneBook::~PhoneBook() {
	destructPhoneBook(head);
}

//complete
void PhoneBook::display() {
	PBnode* temp = head;
	for (int i = 1;i <= size;i++) {
		cout << setw(4) << i << ". "
			<< *temp << endl;
		temp = temp->next;
	}
}

//complete
void PhoneBook::searchByFName() {
	char option = 'a';

	while (option != 'x' && option!='X') {
		cin.ignore(10000, '\n');
		string searchTerm = "";
		cout << "Enter First name to search: ";
		getline(cin, searchTerm);

		if (searchTerm.empty()) {
			searchTerm = "(Empty)";
		}

		PBnode* temp = head;
		int found = 0;
		while (temp != NULL) {
			if (temp->getFirstName() == searchTerm) {
				cout << setw(4) << found + 1 << ". " << *temp << endl;
				found++;
			}
			temp = temp->next;
		}
		cout << "Found " << found << " entries with first name " << searchTerm << endl << endl;

		cout << "Press x to go back to main menu or r to search again: ";
		option = getchar();
		cout << endl;
	}
	
}

//complete
void PhoneBook::searchByLName() {
	char option = 'a';

	while (option != 'x' && option != 'X') {
		cin.ignore(10000, '\n');
		string searchTerm = "";
		cout << "Enter Last name to search: ";
		getline(cin, searchTerm);

		if (searchTerm.empty()) {
			searchTerm = "(Empty)";
		}

		PBnode* temp = head;
		int found = 0;
		while (temp != NULL) {
			if (temp->getLastName() == searchTerm) {
				cout << setw(4) << found + 1 << ". " << *temp << endl;
				found++;
			}
			temp = temp->next;
		}
		cout << "Found " << found << " entries with last name " << searchTerm << endl << endl;

		cout << "Press x to go back to main menu or r to search again: ";
		option = getchar();
		cout << endl;
	}
}

//complete
void PhoneBook::searchByEmail() {
	char option = 'a';

	while (option != 'x' && option != 'X') {
		cin.ignore(10000, '\n');
		string searchTerm = "";
		cout << "Enter email to search: ";
		getline(cin, searchTerm);

		if (searchTerm.empty()) {
			searchTerm = "(Empty)";
		}

		PBnode* temp = head;
		int found = 0;
		while (temp != NULL) {
			if (temp->getEmail() == searchTerm) {
				cout << setw(4) << found + 1 << ". " << *temp << endl;
				found++;
			}
			temp = temp->next;
		}
		cout << "Found " << found << " entries with email " << searchTerm << endl << endl;

		cout << "Press x to go back to main menu or r to search again: ";
		option = getchar();
		cout << endl;
	}
}

//complete   replace insertEnd with insertInOrder
void PhoneBook::add() {
	cin.ignore();
	string fName;
	string lName;
	string email;
	string phoneNumber = "";

	cout << "Enter First Name: ";
	getline(cin, fName);
	if (fName.empty()) fName = "(Empty)";

	cout << "Enter Last Name: ";
	getline(cin, lName);
	if (lName.empty()) lName = "(Empty)";

	cout << "Enter email: ";
	getline(cin, email);
	if (email.empty()) email = "(Empty)";

	cout << "Enter 10 digit phone number: ";
	getline(cin, phoneNumber);
	if (phoneNumber.empty()) phoneNumber = "(Empty)";
	else {
		bool notValid = true;
		while (notValid) {
			for (int i = 0;i < phoneNumber.length();i++) {
				if (phoneNumber[i] >= '0' && phoneNumber[i] <= '9') {
					notValid = false;
				}
				else notValid = true;
			}

			if (notValid) {
				cout << "Invalid phone number entered. Try again.\nPhone Number: ";
				getline(cin, phoneNumber);
			}
		}
	}
	

	/*while (phoneNumber.size() != 10) {
		getline(cin, phoneNumber);
		if (phoneNumber.size() != 10) {
			cout << "Invalid phone number entered.\nEnter Phone number again: ";
		}
	}*/
	PBnode* temp = new PBnode(fName, lName, email, phoneNumber);
	insertEnd(temp);
}

void PhoneBook::update() {

}

void PhoneBook::deleteE() {
	display();
}

void PhoneBook::save() {
	ofstream data("phonebook.pb");
	if (data.fail()) {
		cout << "Error saving to file...";
		return;
	}
	data << size << endl;
	PBnode* temp = head;
	while (temp != NULL) {
		data << temp->getFirstName() << " " 
			<< temp->getLastName() << " " 
			<< temp->getEmail() << " " 
			<< temp->getPhoneNumber();
		if (temp->next != NULL) data << endl;
		temp = temp->next;
	}

}

void PhoneBook::restore() {
	deleteAll();

	ifstream data("phonebook.pb");
	if (data.fail()) {
		cout << "Error restoring from file...";
		return;
	}
	
	int size;
	data >> size;
	if (size == 0) return;

	while (!data.eof()) {
		string fName;
		string lName;
		string email;
		string phoneNumber = "";

		data >> fName >> lName >> email >> phoneNumber;
		PBnode *temp = new PBnode(fName, lName, email, phoneNumber);
		insertEnd(temp);
	}
}

void PhoneBook::deleteAll() {
	destructPhoneBook(head);
	head = NULL;
	tail = NULL;
	size = 0;
}

void PhoneBook::insertEnd(PBnode* data) {
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

void PhoneBook::destructPhoneBook(PBnode* x) {
	if (x == NULL) {
		return;
	}
	destructPhoneBook(x->next);
	delete x;
}

