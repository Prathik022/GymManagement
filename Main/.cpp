#include "interface2.h"
#include "Admin.h"

void menu() {
	Admin obj1;
	int option;
	do {
		cout << "1. Admin \n2. Member \n3. Join Gym\n4. Exit\n";
		cin >> option;
		switch (option) {
		case 1: {
			obj1.startFunction();
			break;
		}
		case 2: {
			cout << "Give mailID";
			char* str;
			cin >> str;
			obj1.printOneMember(str);
			break;
		}

		case 3: {
			obj1.fillDetails();
			break;
		}
		case 4: {
			cout << "Thank You! Visit Again!";
			break;
		}
		default:
			cout << "Invalid choice! Please enter a valid option." << endl;
		}
	} while (option != 4);
}