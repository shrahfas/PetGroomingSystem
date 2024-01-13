#pragma once
#ifndef ADMIN_H
#define ADMIN_H

#include <string>

class Admin
{
public://access specifier
	int AdminID;//numerical attributes 
	std::string Admin_Username, Admin_Password, Admin_Email, Admin_Fname, Admin_Add;


	Admin(); // constructor method
	Admin(int AdminID, std::string Admin_Username, std::string Admin_Password, std::string Admin_Email, std::string Admin_Fname, std::string Admin_Add);

	bool login();
	void insert();
	void update();
	void remove();

	~Admin(); //destructor method

};

#endif

