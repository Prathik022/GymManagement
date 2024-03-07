#include "Member.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream> 

#pragma warning(suppress : 4996)

using namespace std;

class Member {
	// Attrubutes of gym members
public:
	string name;
	int age;
	string email;
	string gender;
	int memberShipType;
	string memberShipTypeString;
	int price;
	double BMI;
	string statusWeight;
	stringstream s1;
	stringstream s2;
	string startDate = s1.str();
	string expiryDate = s2.str();

public:
	float height;
	float weight;

	Member() {

	}

	Member(string name, int age, string email, string gender, int memberShipType, float height, float weight)
		: name(name), age(age), email(email), gender(gender), memberShipType(memberShipType), height(height), weight(weight) {}


	void invoke(float height,float weight,int memberShipType) {
		selectMemberShipType(memberShipType);
		getBmi(height,weight);
		getExpiryDate(memberShipType);
	}

	void printMemberDetails() {
		// print the basic details
		cout << "Basic Details of Member \n";
		cout << "Name : " << name << "\n";
		cout << "Plan Price : " << price << " Plan : " << memberShipTypeString << "\n";
		cout << "Expiry Date : ";
		getExpiryDate(memberShipType);
		//BMI = getBmi(height, weight);
		cout << "BMI : " << this->BMI << " " << this->statusWeight << "\n";
	}



	void selectMemberShipType(int memberShipType) {
		// depending up the plan membership will be calculated
		// price for the gym
		switch (memberShipType) {
		case 1:
			price = 2000;
			memberShipTypeString = "1 month";
			break;
		case 2:
			price = 3000;
			memberShipTypeString = "3 months";
			break;
		case 3:
			price = 5500;
			memberShipTypeString = "6 months";
			break;
		case 4:
			price = 9000;
			memberShipTypeString = "12 months";
			break;
		case 5:
			price = -1;
			cout << "give correct input";
			break;
		}
		return;

	}


	void getExpiryDate(int memberShipType) {
		// getting the current date and expiry date
		// Get the current time
		time_t now = time(0);
		// Convert now to tm struct for local timezone
		tm* localtm = localtime(&now);
		// Handle overflow/underflow of months
		mktime(localtm);
		
		//cout << "Current Date: ";
		s1 << 1900 + localtm->tm_year << '-' << setw(2) << setfill('0') << 1 + localtm->tm_mon << '-' << setw(2) << setfill('0') << localtm->tm_mday << endl;
		// Add months to current date
		localtm->tm_mon += memberShipType;
		s2 << 1900 + localtm->tm_year << '-' << setw(2) << setfill('0') << 1 + localtm->tm_mon << '-' << setw(2) << setfill('0') << localtm->tm_mday << endl;
		
	}

	void getBmi(float height, float weight)
	{
		// calculating BMI
		BMI = weight / pow(height, 2);
		if (BMI < 18.5) {
			statusWeight = "Under Weight";
		}
		else if (BMI > 18.5 && BMI <= 24.9) {
			statusWeight = "Healthy Weight";
		}
		else if (BMI >= 25.5 && BMI <= 29.9) {
			statusWeight = "Heavy Weight";
		}
		else if (BMI >= 30) {
			statusWeight = "Obesity";
		}
		return;
	}

};