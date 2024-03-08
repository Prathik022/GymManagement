#include "Admin.h"
#include <iostream>

using namespace std;

void menu() {
	Admin obj1;
	int option;
	do {
		cout << "\n1. Admin \n2. Member \n3. Join Gym\n4. Exit\n";
		cin >> option;
		switch (option) {
		case 1: {
			obj1.startFunction();
			break;
		}
		case 2: {
			cout << "Give mailID";
			string str;
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

	int main()
	{
		std::cout << "Welcome to fitness zone!\n";
		menu();
		return 1;
	}


