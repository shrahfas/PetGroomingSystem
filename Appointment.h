#pragma once
#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <vector>
#include "DBConnection.h"

class Appointment
{
public:
	int AppointmentID, packageID, PetID;
	std::string App_Date, App_Time;

	Appointment();
	Appointment(int AppointmentID, int PetID, int packageID, std::string App_Date, std::string App_Time);
	Appointment(sql::ResultSet* data);
	void insertAppointment();
	void updateAppointment();

	bool App_DateExists(const std::string& App_Date);
	bool App_TimeExists(const std::string& App_Time);
	/*static Appointment findAppointment(int AppointmentID);*/

	static std::vector<Appointment> findBook(int PetID, bool ascending);

	static std::vector<Appointment> listBook(std::string Pet_Name, bool ascending);


	/*std::vector<std::pair<Appointment, int>> items;*/

	//void Appointment::addAppt(Appointment appt, int packageID);
	
	/*double total();
	int count();*/

	~Appointment();
};


#endif

