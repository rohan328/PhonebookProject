#include <iostream>
#include "PBentry.h"
#include "PhoneBook.h"

using namespace std;

void wait() {
	cin.ignore();
	cout << "press enter to go back";
	char x;
	while (true) {
		x = getchar();
		if (x == '\n') return;
	}
}

int main() {
	PhoneBook pb;
	pb.restore();
	char option = NULL;
	while (true) {
		system("cls");
		
		cout << "1. Display PhoneBook\n"
			<< "2. Search(By first name)\n"
			<< "3. Search(By last name)\n"
			<< "4. Search(By Email)\n"
			<< "5. Add new entry\n"
			<< "6. Update an entry\n"
			<< "7. Delete an entry\n"
			<< "8. Save to database\n"
			<< "9. Restore from database\n"
			<< "D. Delete all entries\n"
			<< "x. Exit\n";
		cout << "Choose an option: ";
		cin >> option;
		
		system("cls");
		
		switch (option) {
		case '1':
			pb.display();
			wait();
			break;
		case '2':
			pb.searchByFName();
			wait();
			break;
		case '3':
			pb.searchByLName();
			wait();
			break;
		case '4':
			pb.searchByEmail();
			wait();
			break;
		case '5':
			pb.add();
			break;
		case '6':
			pb.update();
			wait();
			break;
		case '7':
			pb.deleteE();
			wait();
			break;
		case '8':
			pb.save();
			break;
		case '9':
			pb.restore();
			break;
		case 'D':
			pb.deleteAll();
			break;
		case 'x':
			return 0;
		}
	}
}



/*
Realtime input
int main ()
{
  char c;
  puts ("Enter text. Include a dot ('.') in a sentence to exit:");
  do {
	c=getchar();
	putchar (c);
  } while (c != '.');
  return 0;
}

*/