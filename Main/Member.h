#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream> 
#include "Member.h"

#pragma warning(suppress : 4996)

using namespace std;

class Member {

public:

	string name;
	int age;
	string phonenumber;
	string email;
	string gender;
	string password;
	int memberShipType;
	string memberShipTypeString;
	int price;
	double BMI;
	string statusWeight;
	stringstream s1;
	stringstream s2;
	string startDate = s1.str();
	string expiryDate = s2.str();

	float height;
	float weight;

	/*Member();*/

	void setName(string name);
	void setAge(int age);
	void setPhonenumber(string phonenumber);
	void setGender(string gender);
	void setmemberShipType(int n);
	void setHeight(int height);
	void setWeight(int weight);
	void selectMemberShipType(int memberShipType);
	void getExpiryDate(int memberShipType);
	double getBmi(float height, float weight);
	void invoke(string phonenumber, string name, int age, string gender, int memberShipType, float height, float weight);
	//void printMemberDetails();
};