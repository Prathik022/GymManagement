#include "DbConnect.h"
#include "Member.h"
#include "Admin.h"

const string server = "localhost:3306";
const string username = "root";
const string password = "prathik";

void DbConnect::addToDB(string& phonenumber,string& pass, string& name, string& gender, string& memberShipTypeString, double BMI, string& statusWeight, int price, int age, float height, float weight) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");

        string query = "INSERT INTO member(phonenumber,password,name,gender,memberShipTypeString,BMI,statusWeight,price,age,weight,height) VALUES(?, ?,?,?,?,?,?,?,?,?,?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, phonenumber);
        pstmt->setString(2, pass);
        pstmt->setString(3, name);
        pstmt->setString(4, gender );
        pstmt->setString(5, memberShipTypeString);
        pstmt->setDouble(6, BMI );
        pstmt->setString(7, statusWeight);
        pstmt->setInt(8, price);
        pstmt->setInt(9, age);
        pstmt->setDouble(10, weight);
        pstmt->setDouble(11, height);
        pstmt->execute();

        //cout << "Data inserted into " << "user" << " table." << endl;

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
            cout << "\n PhoneNumber : " << result->getString("phonenumber");
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

bool DbConnect::getFromDB(string& phonenumber, string& pass) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT COUNT(*) FROM admin WHERE phonenumber = ? AND password = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, phonenumber);
        pstmt->setString(2, pass);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int userCount = result->getInt(1);

        if (userCount > 0) {
            cout << "Login Successful!" << endl;
        }
        else {
            cout << "Login unsuccessful" << endl;
            cout << "Give correct credentials" << endl;
            return false;
        }

        delete result;
        delete pstmt;
        delete con;
        return true;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}
    
bool DbConnect::checkMember(string& phonenumber, string& pass) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT COUNT(*) FROM member WHERE phonenumber = ? AND password = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, phonenumber);
        pstmt->setString(2, pass);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int userCount = result->getInt(1);

        if (userCount > 0) {
            cout << "Login Successful!" << endl;
        }
        else {
            cout << "Login unsuccessful" << endl;
            return false;
        }

        delete result;
        delete pstmt;
        delete con;
        return true;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}

void DbConnect::getOneMemberDetails(string& phonenumber, string& pass) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);

        con->setSchema("prathik");

        string query = "SELECT * FROM  member WHERE phonenumber = ? AND password = ?";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setString(1, phonenumber);
        pstmt->setString(2, pass);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        
            cout << "\n PhoneNumber : " << result->getString("phonenumber");
            cout << "\t name :" << result->getString("name") << endl;
            cout << "\t BMI :" << result->getDouble("BMI") << endl;
            cout << "\t Status Weight:" << result->getString("statusWeight") << endl;
            cout << "\t Plan :" << result->getString("memberShipTypeString") << endl;
            cout << "\t Price :" << result->getString("price") << endl;
        
        delete pstmt;
        delete con;

    }
    catch (sql::SQLException& e) {
        cout << "Error checking data: " << e.what() << endl;
        system("pause");
        exit(1);
    }
}

int DbConnect::getTotalMembers() {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT COUNT(*) FROM member";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
        int userCount = result->getInt(1);

        delete result;
        delete pstmt;
        delete con;
        return userCount;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}

double DbConnect::getBMIAverage() {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        con->setSchema("prathik");

        // Construct the SQL query to check if the user exists based on both username and password
        string query = "SELECT BMI FROM member";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);

        // Execute the query
        sql::ResultSet* result = pstmt->executeQuery();
        result->next();
       
        double total = 0.0;
        int num_rows = getTotalMembers();
        
        while (result->next()) {
            total += result->getDouble("BMI");
        }
        
        double avg = total / num_rows;
        delete result;
        delete pstmt;
        delete con;
        return avg;
    }
    catch (sql::SQLException& e) {
        cout << "Error checking user data: " << e.what() << endl;
        system("pause");
    }
}