#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Authentication.h"
#include "Admin.h"
#include "DbConnect.h"
#include <windows.h>

#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

using namespace std;
Authentication obj1;
Admin obj2;
DbConnect obj3;


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
					cout << ANSI_COLOR_YELLOW << "1. Get Your Details :\n2. Get Food chart\n3. Get Exercise plan\n4. Exit"<< ANSI_COLOR_RESET;
					cin >> choice;
					switch (choice)
					{
					case 1:
						obj3.getOneMemberDetails(phonenumber, password);
						break;
					case 2: {
						int getChoice;
						cout << "\n1. Active lifestyle\n2.In-active lifestyle\n";
						cin >> getChoice;
						if (getChoice == 1) {
							ifstream file("foodchart_active.txt");
							string line;
							while (getline(file, line)) {
								cout << line << std::endl;
							}
						}
						else if (getChoice == 2) {
							ifstream file("foodchart_notactive.txt");
							string line;
							while (getline(file, line)) {
								cout << line << std::endl;
							}
						}
						else {
							cout << "\nGive the correct input\n";
						}
						break;
					}
					case 3: {
						int getChoice;
						cout << "\n1. Active lifestyle\n2.In-active lifestyle\n";
						cin >> getChoice;
						if (getChoice == 1) {
							ifstream file("Ex1.txt");
							string line;
							while (getline(file, line)) {
								cout << line << std::endl;
							}
						}
						else if (getChoice == 2) {
							ifstream file("Ex2.txt");
							string line;
							while (getline(file, line)) {
								cout << line << std::endl;
							}
						}
						else {
							cout << "\nGive the correct input\n";
						}
						break;
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
		//system("Color 8B");
		cout << ANSI_COLOR_YELLOW << "\nWelcome to Fittness Zone" << ANSI_COLOR_RESET << endl;
		menu();
		return 1;
	}


