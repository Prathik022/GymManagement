#include "Member.h"

	// Attrubutes of gym members


	void Member::setName(string name) {
		name = name;
	}
	void Member::setAge(int age) {
		age = age;
	}
	void Member::setPhonenumber(string phonenumber) {
		phonenumber = phonenumber;
	}
	void Member::setGender(string gender) {
		gender = gender;
	}
	void Member::setmemberShipType(int n) {
		memberShipType = n;
	}
	void Member::setHeight(int height) {
		height = height;
	}
	void Member::setWeight(int weight) {
		weight = weight;
	}

	

	void Member::selectMemberShipType(int memberShipType) {
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


	void Member::getExpiryDate(int memberShipType) {
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


	double Member::getBmi(float height, float weight)
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
		return BMI;
	}

	void Member::invoke(string phonenumber, string name, int age, string gender, int memberShipType, float height, float weight) {
		setPhonenumber(phonenumber);
		setName(name);
		setAge(age);
		setGender(gender);
		setmemberShipType(memberShipType);
		setHeight(height);
		setWeight(weight);
		selectMemberShipType(memberShipType);
		getBmi(height, weight);
		getExpiryDate(memberShipType);
		
	}
