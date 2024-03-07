#include "Admin.h"
#include <map>
#include <string>
#include <iostream>
#include "Member.cpp"

using namespace std;

class Admin {

	int totalMembers;
	float avgBMI;
	int option;
	string mailId;

	map<string, Member> members; // map to store members using email as key

public:
	Admin() {

	}

	void startFunction() {

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

	// getting input from the user
	void fillDetails() {
		string email, name, gender;
		int age, memberShipType;
		float height, weight;
		cout << "Add details" << "\n";
		cout << "Name:";
		cin >> name;
		cout << "Age:\n";
		cin >> age;
		cout << "Email\n";
		cin >> email;
		cout << "Gender:\n";
		cin >> gender;
		cout << "\n MemberShip Type 1)1 month(Rs 2000) 2)3months(Rs 3000) 3)6 months(Rs 5500) 4)12 months(Rs 9000) : ";
		cin >> memberShipType;
		cout << "\n Height(m) : ";
		cin >> height;
		cout << "\n Weight(kg) : ";
		cin >> weight;
		addMember(email, name, age, gender, memberShipType, height, weight);
	}

	// function to add new members
	void addMember(string email, string name, int age, string gender, int memberShipType, float height, float weight) {
		// Check if email already exists
		if (members.find(email) != members.end()) {
			cout << "Member with this email already exists!" << endl;
			return;
		}
		//Member obj(name, age, email, gender, memberShipType, height, weight);
		
		
		members[email] = Member(name, age, email, gender, memberShipType, height, weight);
		members[email].invoke(height, weight, memberShipType);
		totalMembers++;
		cout << "Member added successfully!" << endl;
	}


	int getTotalMembers() {
		return this->totalMembers;
	}

	// Function to display all members
	void displayMembers() {
		cout << "----- Members -----" << endl;
		for (const auto& pair : members) {
			const Member& member = pair.second;
			cout << "Email: " << pair.first << "\n Name: " << member.name << ", Age: " << member.age << ", Gender: " << member.gender << ", BMI: " << member.BMI << endl;
			cout << "Weight Status: " << member.statusWeight << "Current Date: " << member.startDate << ", Expiry Date:" << member.expiryDate << ", Price:" << member.price << endl ;
		}
		cout << "-------------------" << endl;
	}

	void printOneMember(string str) {
		cout << "----- Your Details -----" << endl;
		bool flag = false;
		for (const auto& pair : members) {
			//cout << "\npair.first :" << pair.first << endl;
			if (pair.first == str) {
				flag = true;
				const Member& member = pair.second;
				cout << "Email: " << pair.first << "\n Name: " << member.name << ", Age: " << member.age << ", Gender: " << member.gender << ", BMI: " << member.BMI << endl;
				cout << "Weight Status: " << member.statusWeight << "Current Date: " << member.startDate << ", Expiry Date:" << member.expiryDate << ", Price:" << member.price << endl;
			}else {
				if (flag == false) {
					break;
				}
				cout << "Your are not a member";
			}
		}
		cout << "-------------------" << endl;
	}

};