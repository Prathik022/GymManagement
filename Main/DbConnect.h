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
	void addToDB(int phoneNumber, string& name, string& gender, string& memberShipTypeString, double BMI, string& statusWeight, int price, int age, float height, float weight);
	void getDetails();
};