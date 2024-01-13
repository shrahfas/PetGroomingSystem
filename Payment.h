#pragma once
#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <vector>
#include "Package.h"

class Payment
{
public:
	std::string dateTime /*App_Date, App_Time*/;
	int paymentID, PetID, packageID,/* AppointmentID,*/ Total_Payment, payment, paym;

	std::vector<std::pair<Package, int>> items;

	Payment();
	/*void addPackage(Package package);*/
	void insertPayment();
	double total();
	int count();

};

#endif