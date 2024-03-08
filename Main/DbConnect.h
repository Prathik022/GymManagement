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
	void addToDB(string& email, string& name, int age, string& gender, int memberShipType, float height, float weight);
};