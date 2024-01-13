#include "Admin.h"
#include <ctime>
#include "DBConnection.h" 
using namespace std;

Admin::Admin() {

	AdminID = 0;
	Admin_Username = "";
	Admin_Password = "";
	Admin_Email = "";
	Admin_Fname = "";
	Admin_Add = "";

}


Admin::Admin (int AdminID, std::string Admin_Username, std::string Admin_Password, std::string Admin_Email, std::string Admin_Fname, std::string Admin_Add)
{
	this->AdminID = AdminID;
	this->Admin_Username = Admin_Username;
	this->Admin_Password = Admin_Password;
	this->Admin_Email = Admin_Email;
	this->Admin_Fname = Admin_Fname;
	this->Admin_Add = Admin_Add;
	
}
bool Admin::login() {

	DBConnection db;
	db.prepareStatement("SELECT * FROM admin WHERE Admin_Username=? AND Admin_Password=?");
	db.stmt->setString(1, Admin_Username);
	db.stmt->setString(2, Admin_Password);
	db.QueryResult();
	if (db.res->rowsCount() == 1) {
		while (db.res->next()) {
			AdminID = db.res->getInt("AdminID");
			Admin_Username = db.res->getString("Admin_Username");
			Admin_Password = db.res->getString("Admin_Password");
			Admin_Email = db.res->getString("Admin_Email");
			Admin_Fname = db.res->getString("Admin_Fname");
			Admin_Add = db.res->getString("Admin_Add");
		}
		db.~DBConnection();
		return true;
	}
	else {

		db.~DBConnection();
		return false;
	}
}
void Admin::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into admin (Admin_Username,Admin_Password,Admin_Fname, Admin_Email, Admin_Add) VALUES (?,?,?,?,?)");
	db.stmt->setString(1, Admin_Username);
	db.stmt->setString(2, Admin_Password);
	db.stmt->setString(3, Admin_Fname);
	db.stmt->setString(4, Admin_Email);
	db.stmt->setString(5, Admin_Add);
	db.QueryStatement();
	db.~DBConnection();
}
void Admin::update() {

	DBConnection db;
	db.prepareStatement("UPDATE admin SET Admin_Username=?, Admin_Password=?, Admin_Fname=?, Admin_Email=?,Admin_Add=? WHERE AdminID=?");
	db.stmt->setString(1, Admin_Username);
	db.stmt->setString(2, Admin_Password);
	db.stmt->setString(3, Admin_Fname);
	db.stmt->setString(4, Admin_Email);
	db.stmt->setString(5, Admin_Add);
	db.stmt->setInt(6, AdminID);
	db.QueryStatement();
	db.~DBConnection();

}
void Admin::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM admin WHERE AdminID=?");
	db.stmt->setInt(1, AdminID);
	db.QueryStatement();
	db.~DBConnection();
}




Admin::~Admin() {

}

