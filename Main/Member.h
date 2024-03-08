#pragma once
#include "Member.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream> 

#pragma warning(suppress : 4996)

using namespace std;

class Member {

public:
	Member() {

	}

	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setGender(string gender);
	void setmemberShipType(int n);
	void setHeight(int height);
	void setWeight(int weight);
	void selectMemberShipType(int memberShipType);
	void getExpiryDate(int memberShipType);
	void getBmi(float height, float weight);
	void invoke(string email, string name, int age, string gender, int memberShipType, float height, float weight);
	void printMemberDetails();
};