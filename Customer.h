#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer
{
public://access specifier
	int CustomerID; //numerical attributes
	std::string username, password, email, fullname, address, numphone;


	Customer();// constructor method
	Customer(int CustomerID, std::string username, std::string password, std::string email, std::string fullname, std::string numphone, std::string address);

	bool login();
	void insert();
	void update();
	void remove();
	
	~Customer(); //destructor method

	//// getter setter for password
	//void setPassword(std::string pass);
	//std::string getPassword();

	//// to check if a string matches with the encrypted password
	//bool MatcPasswordWith(std::string plainText);

//private:
//	std::string password; //encapsulate password inside private because we want to ensure it is encrypted when set
//	std::string encrypt(std::string input);
//	char toChar(int asciDecimal);
//	bool isMatch(std::string encrypted, std::string testText);
//
//
//	/*string encrypt();
//	char toChar();
//	void setPassword();
//	string getPassword();*/

	
};

#endif
