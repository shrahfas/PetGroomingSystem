#include "Appointment.h"
#include <vector> 
#include "Customer.h"
using namespace std;


Appointment::Appointment() {
	AppointmentID = 0;
	PetID = 0;
	packageID = 0;
	App_Date = "";
	App_Time = "";
}

Appointment::Appointment(int AppointmentID, int PetID, int packageID, std::string App_Date, std::string App_Time)
{
	this->AppointmentID = AppointmentID;
	this->PetID = PetID;
	this->packageID = packageID;
	this->App_Date = App_Date;
	this->App_Time = App_Time;
}

Appointment::Appointment(sql::ResultSet* data) {
	AppointmentID = data->getInt("AppointmentID");
	PetID = data->getInt("PetID");
	packageID = data->getInt("packageID");
	App_Date = data->getString("App_Date");
	App_Time = data->getString("App_Time");
}

void Appointment::insertAppointment()
{
	DBConnection db;//instantiate
	db.prepareStatement("INSERT into appointment (PetID, packageID, App_Date, App_Time) VALUES (?,?,?,?)");
	db.stmt->setInt(1, PetID);
	db.stmt->setInt(2, packageID);
	db.stmt->setString(3, App_Date);
	db.stmt->setString(4, App_Time);
	db.QueryStatement();
	db.~DBConnection();
}

void Appointment::updateAppointment()
{
	DBConnection db;//instantiate
	db.prepareStatement("UPDATE appointment SET PetID=?, packageID=?, App_Date=?, App_Time=? WHERE AppointmentID=?");
	db.stmt->setInt(1, PetID);
	db.stmt->setInt(2, packageID);
	db.stmt->setString(3, App_Date);
	db.stmt->setString(4, App_Time);
	db.stmt->setInt(5, AppointmentID);
	db.QueryStatement();
	db.~DBConnection();
}

bool Appointment::App_DateExists(const string& App_Date) {
	DBConnection db;
	db.prepareStatement("SELECT * FROM Appointment WHERE App_Date=?");
	db.stmt->setString(1, App_Date);
	db.QueryResult();

	return (db.res->rowsCount() > 0);
}

bool Appointment::App_TimeExists(const string& App_Time) {
	DBConnection db;
	db.prepareStatement("SELECT * FROM Appointment WHERE App_Time=?");
	db.stmt->setString(1, App_Time);
	db.QueryResult();

	return (db.res->rowsCount() > 0);
}

vector<Appointment> Appointment::findBook(int PetID, bool ascending) 
{

	string query = "SELECT * FROM Appointment WHERE "
		" ( PetID LIKE ? )"
		" ORDER BY App_Date";

	if (ascending) {
		query += " ASC";
	}
	else {
		query += " DESC";
	}
	// 
	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setInt(1, PetID );

	vector<Appointment> book;

	db.QueryResult();

	if (db.res->rowsCount() > 0) {

		while (db.res->next()) {
			Appointment tmpBook(db.res);
			book.push_back(tmpBook);

		}
	}

	db.~DBConnection();
	return book;
}

vector<Appointment> Appointment::listBook(string Pet_Name, bool ascending)
{
	string query = "SELECT * FROM pet WHERE "
		"(Pet_Name LIKE ?) "
		"ORDER BY Pet_Name";
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
	db.stmt->setString(1, "%" + Pet_Name + "%");

	vector<Appointment> appointments;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{

		while (db.res->next())
		{
			Appointment tmpAppointment(db.res);
			appointments.push_back(tmpAppointment);

		}
	}
	db.~DBConnection();
	return appointments;

}

//Appointment Appointment::findAppointment(int AppointmentID) {
//	DBConnection db;
//	db.prepareStatement("SELECT * FROM Appointment WHERE (AppointmentID=?)");
//	db.stmt->setInt(1, AppointmentID);
//	db.QueryResult();
//
//	Appointment result;
//	if (db.res->rowsCount() == 1) {
//		while (db.res->next()) {
//			Appointment found(db.res);
//			result = found;
//		}
//	}
//	db.~DBConnection();
//	return result;
//}

//void Appointment::insert()
//{
//	//DBConnection db;//instantiate
//	//db.prepareStatement("Insert into appoinment (PetID,packageID,App_Date, App_Time) VALUES (?,?,?,?)");
//	//db.stmt->setInt(1, PetID);
//	//db.stmt->setInt(2, packageID);
//	//db.stmt->setString(3, App_Date);
//	//db.stmt->setString(4, App_Time);
//	//db.QueryStatement();
//	//db.~DBConnection();
//
//
//	//Customer custs;
//	DBConnection db;
//	db.prepareStatement("INSERT INTO Appointment(cuser) VALUES (?)");
//	db.stmt->setInt(1, AppointmentID);
//	db.QueryStatement();
//	AppointmentID = db.getGeneratedId();
//
//	string query = "INSERT INTO package(packageID, CustomerID) VALUES ";
//	for (int i = 0; i < items.size(); i++)
//	{
//		query += "(? , ? , ? ), ";
//	}
//	query.erase(query.size() - 1);
//	db.prepareStatement(query);
//
//	for (int i = 0; i < items.size(); i++)
//	{
//		db.stmt->setInt(i * 3 + 1, AppointmentID);
//	}
//	db.QueryStatement();
//	db.~DBConnection();
//}

//double Appointment::total()
//{
//	double total = 0;
//	for (int i = 0; i < items.size(); i++)
//	{
//		//total += items[i].first.value * items[i].second;
//	}
//	return total;
//}
//
//int Appointment::count()
//{
//	double count = 0;
//	for (int i = 0; i < items.size(); i++)
//	{
//		count += items[i].second;
//	}
//	return count;
//}



//void Appointment::addAppt(Appointment appt, int TreatmentID)
//{
//	items.push_back({ appt, TreatmentID });
//}



Appointment::~Appointment() {

}
