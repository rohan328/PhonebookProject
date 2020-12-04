#include "PBentry.h"
#include <iostream>
#include <iomanip>

PBentry::PBentry(string firstName, string lastName, string email, string phoneNumber) {
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->phoneNumber = phoneNumber;
}

bool PBentry::setFirstName(string firstName) {
	if (firstName.empty()) return false;
	this->firstName = firstName;
	return true;
}

bool PBentry::setLastName(string lastName) {
	if (lastName.empty()) return false;
	this->lastName = lastName;
	return true;
}

bool PBentry::setEmail(string email) {
	if (email.empty()) return false;
	this->email = email;
	return true;
}

bool PBentry::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
	return true;
}

string PBentry::getFirstName() { return firstName; }

string PBentry::getLastName() { return lastName; }

string PBentry::getEmail() { return email; }

string PBentry::getPhoneNumber() { return phoneNumber; }

PBnode::PBnode(string firstName, string lastName, string email, string phoneNumber)
	: PBentry(firstName, lastName, email, phoneNumber) {
	next = NULL;
	prev = NULL;
}

//overload << operator for displaying list on screen
ostream& operator<<(ostream& os, PBentry& data) {
	os << "First Name: " << data.firstName << endl
		<< setw(4) << "" << "  Last Name: " << data.lastName << endl
		<< setw(4) << "" << "  Email: " << data.email << endl
		<< setw(4) << "" << "  Phone Number: " << data.phoneNumber;
	return os;
}
