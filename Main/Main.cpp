#include <iostream>
#include <fstream>
#include <string>
#include "Authentication.h"
#include "Admin.h"
#include "DbConnect.h"

using namespace std;
Authentication obj1;
Admin obj2;
DbConnect obj3;
string filename = "foodchart.txt";

void menu() {
	int option;
	do {
		cout << "\n1. Admin \n2. Member \n3. Join Gym\n4. Exit\n";
		cin >> option;
		switch (option) {
		case 1: {
			string phonenumber;
			string password;
			cout << "Enter PhoneNumber :";
			cin >> phonenumber;
			cout << "\nEnter password :";
			cin >> password;
			bool flag = obj1.Login(phonenumber, password);
			if (flag == true) {
				obj2.startFunction();
			}
			break;
		}
		case 2: {
			string phonenumber;
			string password;
			cout << "Enter PhoneNumber :";
			cin >> phonenumber;
			cout << "\nEnter password :";
			cin >> password;
			bool flag = obj1.LoginMember(phonenumber, password);
			if (flag == true) {
				int choice;
				do{
					cout << "1. Get Your Details :\n2. Get Food chart\n3. Get Exercise plan\n4. Exit";
					cin >> choice;
					switch (choice)
					{
					case 1:
						obj3.getOneMemberDetails(phonenumber, password);
						break;
					case 2: {
						ifstream file(filename);
						string line;
						while (std::getline(file, line)) {
							std::cout << line << std::endl;
						}
						break;
					}
					default:
						cout << "Invalid choice! Please enter a valid option." << endl;
						break;
					}
				}while (choice != 4);
				obj2.displayMembers();
			}
			else {
				cout << "Give correct credientials";
			}
			break;
		}
		case 3: {
			string phonenumber;
			string password;
			cout << "-Need admin access-\n";
			cout << "Login\n";
			cout << "Enter PhoneNumber :";
			cin >> phonenumber;
			cout << "\nEnter password :";
			cin >> password;
			bool flag = obj1.Login(phonenumber, password);
			if (flag == true) {
				obj2.fillDetails();
			}
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


