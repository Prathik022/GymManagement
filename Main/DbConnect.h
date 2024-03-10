#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>


using namespace std;

class DbConnect {

public:
	void addToDB(string& phoneNumber, string& pass, string& name, string& gender, string& memberShipTypeString, double BMI, string& statusWeight, int price, int age, float height, float weight);
	void getDetails();
	bool getFromDB(string& phonenumber, string& pass);
	bool checkMember(string& phonenumber, string& pass);
	void getOneMemberDetails(string& phonenumber, string& pass);
};