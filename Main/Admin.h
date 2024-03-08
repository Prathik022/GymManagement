#pragma once
#include <map>
#include <string>
#include <iostream>


using namespace std;

class Admin {
	/*Admin() {}*/

public:
	void addMember(string& email, string& name, int age, string& gender, int memberShipType, float height, float weight);
	void fillDetails();
	int getTotalMembers();
	void displayMembers();
	void printOneMember(string str);
	void startFunction();

};