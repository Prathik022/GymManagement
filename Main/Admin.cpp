#include "Admin.h"
#include "Member.h"
#include "DbConnect.h"



int option;
int totalMembers;
float avgBMI;
string mailId;
	
	
DbConnect connect;

	// function to add new members
	void Admin::addMember(int phonenumber, string& name, int age, string& gender, int memberShipType, float height, float weight) {
		
		Member obj;
		obj.invoke(phonenumber, name, age, gender, memberShipType, height, weight);
		
		connect.addToDB(phonenumber,name,gender,obj.memberShipTypeString,obj.BMI,obj.statusWeight,obj.price,age,height,weight);
		cout << "added members successfully";
	}

	// getting input from the user
	void Admin::fillDetails() {
		string name, gender;
		int age, memberShipType,phonenumber;
		float height, weight;
		cout << "Add details" << "\n";
		cout << "Name:";
		cin >> name;
		cout << "Age:\n";
		cin >> age;
		cout << "PhoneNumber:\n";
		cin >> phonenumber;
		cout << "Gender:\n";
		cin >> gender;
		cout << "\n MemberShip Type 1)1 month(Rs 2000) 2)3months(Rs 3000) 3)6 months(Rs 5500) 4)12 months(Rs 9000) : ";
		cin >> memberShipType;
		cout << "\n Height(m) : ";
		cin >> height;
		cout << "\n Weight(kg) : ";
		cin >> weight;
		addMember(phonenumber, name, age, gender, memberShipType, height, weight);

	}


	int Admin::getTotalMembers() {
		return totalMembers;
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
			cout << "1. Join New Member \n2. Get total Members \n3. Get average BMI of members\n4. Display all members\n5. exit : \n";
			cin >> option;
			switch (option) {
			case 1: {
				fillDetails();
				break;
			}
			case 2: {
				cout << getTotalMembers();
				break;
			}
			case 3: {
				cout << "need to implement";
				break;
				// need implementation
			}
			case 4:
				displayMembers();
				break;
			case 5:
				break;
			}
		} while (option == 5);
	}

