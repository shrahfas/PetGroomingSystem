#include "Package.h"
#include <vector> 
using namespace std;

Package::Package()
{

	packageID = 0;
	price = 0;
	package_name = "";
	Duration = "";

}

Package::Package(sql::ResultSet* data) {

	packageID = data->getInt("packageID");
	price = data->getDouble("price");
	package_name = data->getString("package_name");
	Duration = data->getString("Duration");
	
}

Package::Package (int packageID, double price, std::string package_name, std::string Duration) {
	this->packageID = packageID;
	this->price = price;
	this->package_name = package_name;
	this->Duration = Duration;
}

void Package::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into package ( price, package_name, Duration) VALUES (?,?,?)");
	db.stmt->setDouble(1, price);
	db.stmt->setString(2, package_name);
	db.stmt->setString(3, Duration);
	db.QueryStatement();
	db.~DBConnection();
}
void Package::update() {

	DBConnection db;
	db.prepareStatement("UPDATE package SET price=?, package_name=?, Duration=? WHERE packageID=?");
	db.stmt->setDouble(1, price);
	db.stmt->setString(2, package_name);
	db.stmt->setString(3, Duration);
	db.stmt->setInt(4, packageID);
	db.QueryStatement();
	db.~DBConnection();

}
void Package::remove() {
	DBConnection db;
	db.prepareStatement("DELETE FROM package WHERE packageID=?");
	db.stmt->setInt(1, packageID);
	db.QueryStatement();
	db.~DBConnection();
}

vector<Package> Package::findPackage(std::string package_name, bool ascending)
{
	string query = "SELECT * FROM package WHERE "
		"(packageID LIKE ?) "
		"ORDER BY packageID";
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
	db.stmt->setString(1, "%" + package_name + "%");

	vector<Package> packages;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{

		while (db.res->next())
		{
			Package tmpPackage(db.res);
			packages.push_back(tmpPackage);

		}
	}
	db.~DBConnection();
	return packages;

}

Package::~Package() {

}