#pragma once
#include <map>
#include <string>
#include <iostream>
#include "Member.h"


using namespace std;

class Admin {
	/*Admin() {}*/

public:
	void addMember(string& phonenumber ,string& password, string& name, int age, string& gender, int memberShipType, float height, float weight);
	void fillDetails();
	int getTotalMembers();
	void displayMembers();
	void printOneMember(string str);
	void startFunction();

};