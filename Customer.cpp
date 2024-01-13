#include "Customer.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

Customer::Customer() {
	//initialize
	CustomerID = 0;
	username = "";
	password = "";
	fullname = "";
	email = "";
	numphone = "";
	address = "";
}
Customer::Customer(int CustomerID, std::string username, std::string password, std::string email, std::string fullname, std::string numphone, std::string address){
	this->CustomerID = CustomerID;
	this->username = username;
	this->password = password;
	this->email = email;
	this->fullname = fullname;
	this->numphone = numphone;
	this->address = address;
}
bool Customer::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM customer WHERE username=? AND password=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			CustomerID = db.res->getInt("CustomerID");
			username = db.res->getString("username");
			password = db.res->getString("password");
			email = db.res->getString("email");
			fullname = db.res->getString("fullname");
			numphone = db.res->getString("numphone");
			address = db.res->getString("address");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Customer::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into customer (username,password,fullname, email, numphone,  address) VALUES (?,?,?,?,?,?)");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setString(3, fullname);
	db.stmt->setString(4, email);
	db.stmt->setString(5, numphone);
	db.stmt->setString(6, address);
	db.QueryStatement();
	db.~DBConnection();
}
void Customer::update() {

	DBConnection db;
	db.prepareStatement("UPDATE customer SET username=?, password=?, fullname=?, email=?, numphone=?, address=? WHERE CustomerID=?");
	db.stmt->setString(1, username);
	db.stmt->setString(2, password);
	db.stmt->setString(3, fullname);
	db.stmt->setString(4, email);
	db.stmt->setString(5, numphone);
	db.stmt->setString(6, address);
	db.stmt->setInt(7, CustomerID);
	db.QueryStatement();
	db.~DBConnection();

}
void Customer::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM account WHERE CustomerID=?");
	db.stmt->setInt(1, CustomerID);
	db.QueryStatement();
	db.~DBConnection();
}

//string Customer::encrypt(string input) {
//	string ciphertext = "";
//	for (int i = 0; i < input.length(); i++) {
//		ciphertext += toChar(input[i] + ((i ^ 2 + 1) * input.length()));
//	}
//	return ciphertext;
//
//}
//
//char Customer::toChar(int asciDecimal) {
//	while (asciDecimal < 33) {
//		asciDecimal = asciDecimal + asciDecimal + 1;
//	}
//	while (asciDecimal > 125) {
//		asciDecimal = (asciDecimal % 125) + 32;
//	}
//	return (char)asciDecimal;
//}
//
//void Customer::setPassword(string pass) {
//	password = encrypt(pass);
//}
//
//string Customer::getPassword() {
//	return password;
//}

Customer::~Customer() {

}

//void Customer::setPassword(string pass) {
//	password = encrypt(pass);
//
//}
//string Customer::getPassword() {
//	return password;
//}
//
//// to check if a string matches with the encrypted password
//bool Customer::MatcPasswordWith(string plainText) {
//	return isMatch(password, plainText);
//}
//
//
//// simple shifting encryption where the character are shifted by its ASCII decimal code depending on its index
//string Customer::encrypt(string input) {
//	string ciphertext = "";
//	for (int i = 0; i < input.length(); i++) {
//		ciphertext += toChar(input[i] + ((i ^ 2 + 1) * input.length()));
//	}
//	return ciphertext;
//}
//
//// since we are using our own simple encryption, just re ecnrypt the target plain text and compare with the encrypted text
//bool Customer::isMatch(string encrypted, string testText) {
//	return (bool)(encrypt(testText) == encrypted);
//}
//
//char Customer::toChar(int asciDecimal) {
//	// convert int to reeadbale char based on ASCII
//	// characters in ASCII decimal are 32 (space) ~ 125 (~)
//	while (asciDecimal < 33) {
//		asciDecimal = asciDecimal + asciDecimal + 1;
//	}
//	while (asciDecimal > 125) {
//		asciDecimal = (asciDecimal % 125) + 32;
//	}
//	return (char)asciDecimal;
//}
