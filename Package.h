#pragma once
#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
#include <vector>
#include "DBConnection.h"

class Package
{
public :
	int packageID;
	double price;
	std::string package_name, Duration;

	Package();
	Package(int packageID, double price, std::string package_name, std::string Duration);
	Package(sql::ResultSet* data);

	void insert();
	void update();
	void remove();

	~Package();

	static Package selectPackage(int packageID);

	static std::vector<Package> findPackage(std::string package_name, bool ascending);

};

#endif