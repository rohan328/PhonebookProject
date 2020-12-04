#include <iostream>
#include "PBentry.h"
#include "PhoneBook.h"

using namespace std;

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
			<< "8. Save to database (WARNING: This will overwrite existing data in file)\n"
			<< "9. Restore from database(WARNING: This will overwrite existing data in the list)\n"
			<< "D. Delete all entries\n"
			<< "x. Exit\n";
		cout << "Choose an option: ";
		cin >> option;
		
		system("cls");
		
		switch (option) {
		case '1':
			pb.display();
			system("pause");
			break;
		case '2':
			pb.searchByFName();
			system("pause");
			break;
		case '3':
			pb.searchByLName();
			system("pause");
			break;
		case '4':
			pb.searchByEmail();
			system("pause");
			break;
		case '5':
			pb.add();
			break;
		case '6':
			pb.update();
			system("pause");
			break;
		case '7':
			pb.deleteE(NULL);
			system("pause");
			break;
		case '8':
			pb.save();
			system("pause");
			break;
		case '9':
			pb.restore();
			system("pause");
			break;
		case 'D':
			pb.deleteAll();
			break;
		case 'x':
			return 0;
		}
	}
}

