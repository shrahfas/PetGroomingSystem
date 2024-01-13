#include "Payment.h"
#include <string>

using namespace std;

Payment::Payment() {
	paymentID = 0;
	PetID = 0;
	packageID = 0;
	/*AppointmentID = 0;*/
	dateTime = "";
	/*App_Date = "";
	App_Time = "";*/
	Total_Payment = 0.0;
	payment = 0.0;
	paym = 0.0;
}

void Payment::insertPayment()
{
	DBConnection db;//instantiate
	db.prepareStatement("INSERT into payment (PetID, packageID, /*AppointmentID,*/  /*App_Date, App_Time,*/ Total_Payment) VALUES (?,?,?)");
	db.stmt->setInt(1, PetID);
	db.stmt->setInt(2, packageID);
	/*db.stmt->setInt(3, AppointmentID);*/
	/*db.stmt->setString(3, App_Date);
	db.stmt->setString(4, App_Time);*/
	db.stmt->setInt(3, Total_Payment);
	db.QueryStatement();
	db.~DBConnection();
}

//void Payment::insert() {
//
//	DBConnection db;
//	db.prepareStatement("INSERT INTO payment(cuser) VALUES (?)");
//	db.stmt->setInt(1, cuser);
//	db.QueryStatement();
//	paymentID = db.getGeneratedId();
//
//	string query = "INSERT INTO payment_package(paymentID,packageID) VALUES ";
//	for (int i = 0; i < items.size(); i++) {
//		query += "(?,?),";
//
//	}
//	query.erase(query.size() - 1);
//	db.prepareStatement(query);
//
//	for (int i = 0; i < items.size(); i++) {
//		db.stmt->setInt(i * 3 + 1, paymentID);
//		db.stmt->setInt(i * 3 + 2, items[i].first.packageID);
//		db.stmt->setInt(i * 3 + 3, items[i].second);
//	}
//	db.QueryStatement();
//	db.~DBConnection();
//}
