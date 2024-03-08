#include "DbConnect.h"
#include "Member.h"
#include "Admin.h"

const string server = "localhost:3306";
const string username = "root";
const string password = "prathik";

void DbConnect::addToDB(string& email, string& name, int age, string& gender, int memberShipType, float height, float weight) {
    try {
        sql::Driver* driver = get_driver_instance();
        sql::Connection* con = driver->connect(server, username, password);
        cout << "Dabase connected";
        con->setSchema("prathik");

        //string table = "user";
        // Adjust the SQL query based on the table parameter
        string query = "INSERT INTO member(phoneNumber,name,password,bmi,email) VALUES(?, ?,?,?,?)";
        sql::PreparedStatement* pstmt = con->prepareStatement(query);
        pstmt->setInt(1, 455);
        pstmt->setString(2, name);
        pstmt->setString(3, "asd");
        pstmt->setDouble(4,2.4 );
        pstmt->setString(5,email);
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