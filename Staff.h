#pragma once
#ifndef STAFF_H
#define STAFF_H
//using namespace sql;
#include <string>
#include <vector>
#include "DBConnection.h"

class Staff
{
public://access specifier
	int StaffID, AdminID; //numerical attributes
	std::string Staff_Username, Staff_Password, Staff_Email, Staff_Fname, Staff_Add, Staff_PNum;


	Staff(); // constructor method
	Staff(int StaffID,int AdminID, std::string Staff_Username, std::string Staff_Password, std::string Staff_Email, std::string Staff_Fname, std::string Staff_Add, std::string Staff_PNum);
	/*Staff(int StaffID, std::string Staff_Username, std::string Staff_Password, std::string Staff_Email, std::string Staff_Fname, std::string Staff_Add, std::string Staff_PNum);*/
	
	Staff(sql::ResultSet* data);

	bool login();
	void insert();
	void update();
	void remove();

	~Staff(); //destructor method

	static Staff selectStaff(int StaffID);

	static std::vector<Staff> findStaff(std::string Staff_Fname, bool ascending );

};

#endif