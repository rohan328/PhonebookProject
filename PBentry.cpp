#include "PBentry.h"

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

bool PBentry::setPhoneNumber(string) {

	return false;
}

