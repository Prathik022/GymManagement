#pragma once
#include <string>
using namespace std;

class Authentication
{
public:
	string phonenumber;
	string password;

	bool LoginMember(string& phonenumber, string& password);
	bool Login(string& phonenumber, string& password);
};

