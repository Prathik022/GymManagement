#include "Authentication.h"
#include "iostream"
#include "DbConnect.h"

DbConnect obj;
bool Authentication::LoginMember(string& phonenumber, string& password) {
	bool status = obj.checkMember(phonenumber, password);
	return status;
}
	bool Authentication::Login(string& phonenumber, string & password) {
		bool status = obj.getFromDB(phonenumber, password);
		return status;
}




