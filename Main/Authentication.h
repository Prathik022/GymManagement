#pragma once
#include <string>
using namespace std;

class Authentication
{
public:
	
	bool LoginMember(string& phonenumber, string& password);
	bool Login(string& phonenumber, string& password);
};

