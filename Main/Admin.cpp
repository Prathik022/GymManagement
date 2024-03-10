#include "Admin.h"
#include "Member.h"
#include "DbConnect.h"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int option;
int totalMembers;
float avgBMI;
string mailId;
int phonenumber;
string password;
	
DbConnect connect;

	// function to add new members
	void Admin::addMember(string& phonenumber,string& password, string& name, int age, string& gender, int memberShipType, float height, float weight) {
		Member obj;
		obj.invoke(phonenumber, name, age, gender, memberShipType, height, weight);
		connect.addToDB(phonenumber,password,name,gender,obj.memberShipTypeString,obj.BMI,obj.statusWeight,obj.price,age,height,weight);
		cout << "Welcome " << name << " .Your are added to Fitness Gym.";
	}

	// getting input from the user
	void Admin::fillDetails() {
		string name, gender, phonenumber,password;
		int age, memberShipType;
		float height, weight;
		cout << "Add details" << "\n";
		cout << "Name:";
		cin >> name;
		cout << "Age:\n";
		cin >> age;
		cout << "Gender:\n";
		cin >> gender;
		cout << "\n MemberShip Type 1)1 month(Rs 2000) 2)3months(Rs 3000) 3)6 months(Rs 5500) 4)12 months(Rs 9000) : ";
		cin >> memberShipType;
		cout << "\n Height(m) : ";
		cin >> height;
		cout << "\n Weight(kg) : ";
		cin >> weight;
		cout << "PhoneNumber:\n";
		cin >> phonenumber;
		cout << "Give strong password:\n";
		cin >> password;
		addMember(phonenumber,password, name, age, gender, memberShipType, height, weight);

	}


	int Admin::getTotalMembers() {
		return connect.getTotalMembers();
	}

	// Function to display all members
	void Admin::displayMembers() {
		connect.getDetails();
		
	}

	void Admin::printOneMember(string str) {
		cout << str;
	}

	void Admin::startFunction() {

		do {
			cout << ANSI_COLOR_YELLOW << "1. Join New Member \n2. Get total Members \n3. Get average BMI of members\n4. Display all members\n5. exit : \n"<< ANSI_COLOR_RESET;
			
			cin >> option;
			switch (option) {
			case 1: {
				fillDetails();
				break;
			}
			case 2: {
				cout << "\nTotal members :";
				cout << getTotalMembers() << endl;
				break;
			}
			case 3: {
				cout << connect.getBMIAverage();
				break;
			}
			case 4:
				displayMembers();
				break;
			case 5:
				break;
			}
		} while (option != 5);
	}

