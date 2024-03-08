#include "DbConnect.h"
#include "Member.h"
#include "Admin.h"

const string server = "localhost:3306";
const string username = "root";
const string password = "prathik";

void DbConnect::addToDB(int phonenumber, string& name, string& gender, string& memberShipTypeString, double BMI, string& statusWeight, int price, int age, float height, float weight) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        cout << "Dabase connected";
        con->setSchema("prathik");
        con->setSchema("prathik");

        string query = "INSERT INTO member(phonenumber,name,password,gender,memberShipTypeString,BMI,statusWeight,price,age,weight,height) VALUES(?, ?,?,?,?,?,?,?,?,?,?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, phonenumber);
        pstmt->setString(2, name);
        pstmt->setString(3, "123");
        pstmt->setString(4, gender );
        pstmt->setString(5, memberShipTypeString);
        pstmt->setDouble(6, BMI );
        pstmt->setString(7, statusWeight);
        pstmt->setInt(8, price);
        pstmt->setInt(9, age);
        pstmt->setDouble(10, weight);
        pstmt->setDouble(11, height);
        pstmt->execute();

        cout << "Data inserted into " << "user" << " table." << endl;

        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        cout << "Error inserting data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

void DbConnect::getDetails() {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");


        string query = "SELECT * FROM  member";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();

        while (result->next() ){
            cout << "\n PhoneNumber : " << result->getInt("phonenumber");
            cout << "\t name :" << result->getString("name") << endl;
            cout << "\t BMI :" << result->getDouble("BMI") << endl;
            cout << "\t Status Weight:" << result->getString("statusWeight") << endl;
            cout << "\t Plan :" << result->getString("memberShipTypeString") << endl;
            cout << "\t Price :" << result->getString("price") << endl;
        }
        delete pstmt;
        delete con;

    }
    catch (sql::SQLException& e) {
        cout << "Error checking data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}