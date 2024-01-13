#include "Staff.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
using namespace std;

Staff::Staff() {
	//initialize
	StaffID = 0;
	AdminID = 0;
	Staff_Username = "";
	Staff_Password = "";
	Staff_Fname = "";
	Staff_PNum = "";
	Staff_Email = "";
	Staff_Add = "";
}
Staff::Staff(int StaffID,int AdminID, std::string Staff_Username, std::string Staff_Password, std::string Staff_Fname, std::string Staff_PNum, std::string Staff_Email, std::string Staff_Add) {
	this->StaffID = StaffID;
	this->AdminID = AdminID;
	this->Staff_Username = Staff_Username;
	this->Staff_Password = Staff_Password;
	this->Staff_Fname = Staff_Fname;
	this->Staff_PNum = Staff_PNum;
	this->Staff_Email = Staff_Email;
	this->Staff_Add = Staff_Add;
}

Staff::Staff(sql::ResultSet* data) {

	StaffID = data->getInt("StaffID");
	AdminID = data->getInt("AdminID");
	Staff_Username = data->getString("Staff_Username");
	Staff_Password = data->getString("Staff_Password");
	Staff_Fname = data->getString("Staff_Fname");
	Staff_PNum = data->getString("Staff_PNum");
	Staff_Email = data->getString("Staff_Email");
	Staff_Add = data->getString("Staff_Add");
}

bool Staff::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM staff WHERE Staff_Username=? AND Staff_Password=?");
	db.stmt->setString(1, Staff_Username);
	db.stmt->setString(2, Staff_Password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			StaffID = db.res->getInt("StaffID");
			AdminID = db.res->getInt("AdminID");
			Staff_Username = db.res->getString("Staff_Username");
			Staff_Password = db.res->getString("Staff_Password");
			Staff_Fname = db.res->getString("Staff_Fname");
			Staff_Fname = db.res->getString("Staff_PNum");
			Staff_Email = db.res->getString("Staff_Email");
			Staff_Add = db.res->getString("Staff_Add");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Staff::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into staff (AdminID,Staff_Username,Staff_Password,Staff_Fname,Staff_PNum ,Staff_Email, Staff_Add) VALUES (?,?,?,?,?,?,?)");
	db.stmt->setInt(1, AdminID);
	db.stmt->setString(2, Staff_Username);
	db.stmt->setString(3, Staff_Password);
	db.stmt->setString(4, Staff_Fname);
	db.stmt->setString(5, Staff_PNum);
	db.stmt->setString(6, Staff_Email);
	db.stmt->setString(7, Staff_Add);
	db.QueryStatement();
	db.~DBConnection();
}
void Staff::update() {

	DBConnection db;
	db.prepareStatement("UPDATE staff SET AdminID=?, Staff_Username=?, Staff_Password=?, Staff_Fname=?, Staff_PNum=?, Staff_Email=?,Staff_Add=? WHERE StaffID=?");
	db.stmt->setInt(1, AdminID);
	db.stmt->setInt(2, StaffID);
	db.stmt->setString(3, Staff_Username);
	db.stmt->setString(4, Staff_Password);
	db.stmt->setString(5, Staff_Fname);
	db.stmt->setString(6, Staff_PNum);
	db.stmt->setString(7, Staff_Email);
	db.stmt->setString(8, Staff_Add);
	db.QueryStatement();
	db.~DBConnection();

}
void Staff::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM staff WHERE StaffID=?");
	db.stmt->setInt(1, StaffID);
	db.QueryStatement();
	db.~DBConnection();
}

vector<Staff> Staff::findStaff( string Staff_Fname, bool ascending)
{
	string query = "SELECT * FROM staff WHERE "
		"(Staff_Fname LIKE ?) "
		"ORDER BY Staff_Fname";
	if (ascending)
	{
		query += " ASC ";
	}
	else
	{
		query += " DESC ";
	}

	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setString(1, "%" + Staff_Fname + "%");

	vector<Staff> staffs;

	db.QueryResult();

	if (db.res->rowsCount() > 0) 
	{

		while (db.res->next())
		{
			Staff tmpStaff(db.res);
			staffs.push_back(tmpStaff);

		}
	}
	db.~DBConnection();
	return staffs;

}
//int Account::getAge() {
//	if (yearOfBirth == 0) {
//		return 0;
//	}
//	time_t current = time(0); // get time in epoch seconds (since 1900)
//	tm now; // create a struct/object of tm to hold data
//	localtime_s(&now, &current); //populate the now object with data from current
//
//	return (now.tm_year + 1900) // +1900 to the epoch year to get current year
//		- yearOfBirth; // minus user year of birth to get their age
//}



Staff::~Staff() {

}

Staff Staff::selectStaff(int StaffID)
{
	return Staff();
}

