#include "Pet.h"
#include <ctime>
#include "DBConnection.h" 
#include <vector>
using namespace std;
using namespace sql;

Pet::Pet() {
	//initialize
	PetID = 0;
	CustomerID = 0;
	Pet_Name = "";
	Pet_Species = "";
	Pet_Gender = "";
	Pet_Breed = "";
	Pet_Age = "";
	Pet_Colour = "";
	Pet_Weight = "";
}

//
Pet::Pet(sql::ResultSet* data)
{
	PetID = data->getInt("PetID");
	CustomerID = data->getInt("CustomerID");
	Pet_Name = data->getString("Pet_Name");
	Pet_Species = data->getString("Pet_Species");
	Pet_Gender = data->getString("Pet_Gender");
	Pet_Breed = data->getString("Pet_Breed");
	Pet_Age = data->getString("Pet_Age");
	Pet_Colour = data->getString("Pet_Colour");
	Pet_Weight = data->getString("Pet_Weight");

}


Pet::Pet(int PetID, int CustomerID, std::string Pet_Name, std::string Pet_Species, std::string Pet_Gender, std::string Pet_Breed, std::string Pet_Age, std::string Pet_Colour, std::string Pet_Weight) {
	this->PetID = PetID;
	this->CustomerID = CustomerID;
	this->Pet_Name = Pet_Name;
	this->Pet_Species = Pet_Species;
	this->Pet_Gender = Pet_Gender;
	this->Pet_Breed = Pet_Breed;
	this->Pet_Age = Pet_Age;
	this->Pet_Colour = Pet_Colour;
	this->Pet_Weight = Pet_Weight;
}

//bool Customer::login() {
//
//	DBConnection db;
//	db.prepareStatement("SELECT * FROM customer WHERE username=? AND password=?");
//	db.stmt->setString(1, username);
//	db.stmt->setString(2, password);
//	db.QueryResult();
//	if (db.res->rowsCount() == 1) {
//		while (db.res->next()) {
//			CustomerID = db.res->getInt("CustomerID");
//			username = db.res->getString("username");
//			password = db.res->getString("password");
//			email = db.res->getString("email");
//			fullname = db.res->getString("fullname");
//			numphone = db.res->getString("numphone");
//			address = db.res->getString("address");
//		}
//		db.~DBConnection();
//		return true;
//	}
//	else {
//
//		db.~DBConnection();
//		return false;
//	}
//}
void Pet::insert() {

	DBConnection db;//instantiate
	db.prepareStatement("Insert into pet (CustomerID,Pet_Name,Pet_Species,Pet_Gender, Pet_Breed, Pet_Age, Pet_Colour, Pet_Weight) VALUES (?,?,?,?,?,?,?,?)");
	db.stmt->setInt(1, CustomerID);
	db.stmt->setString(2, Pet_Name);
	db.stmt->setString(3, Pet_Species);
	db.stmt->setString(4, Pet_Gender);
	db.stmt->setString(5, Pet_Breed);
	db.stmt->setString(6, Pet_Age);
	db.stmt->setString(7, Pet_Colour);
	db.stmt->setString(8, Pet_Weight);
	db.QueryStatement();
	db.~DBConnection();
}
void Pet::update() {

	DBConnection db;
	db.prepareStatement("UPDATE pet SET /* CustomerID=?,*/ Pet_Name=?, Pet_Species=?, Pet_Gender=?, Pet_Breed=?, Pet_Age=?, Pet_Colour=?, Pet_Weight=? WHERE PetID=?");
	/*db.stmt->setInt(1, CustomerID);*/
	db.stmt->setString(1, Pet_Name);
	db.stmt->setString(2, Pet_Species);
	db.stmt->setString(3, Pet_Gender);
	db.stmt->setString(4, Pet_Breed);
	db.stmt->setString(5, Pet_Age);
	db.stmt->setString(6, Pet_Colour);
	db.stmt->setString(7, Pet_Weight);
	db.stmt->setInt(8, PetID);
	db.QueryStatement();
	db.~DBConnection();

}
void Pet::removePet() {
	DBConnection db;
	db.prepareStatement("DELETE FROM pet WHERE PetID=?");
	db.stmt->setInt(1, PetID);
	db.QueryStatement();
	db.~DBConnection();
}

//vector<Pet> Pet::listPet(int CustomerID, bool ascending)
//{
//	string query = "SELECT * FROM pet WHERE "
//		"(CustomerID LIKE ?) "
//		"ORDER BY Pet_Name";
//	if (ascending)
//	{
//		query += " ASC ";
//	}
//	else
//	{
//		query += " DESC ";
//	}
//
//	DBConnection db;
//	db.prepareStatement(query);
//	db.stmt->setString(1, "%" + CustomerID + "%");
//
//	vector<Pet> pets;
//
//	db.QueryResult();
//
//	if (db.res->rowsCount() > 0)
//	{
//
//		while (db.res->next())
//		{
//			Pet tmpPet(db.res);
//			pets.push_back(tmpPet);
//
//		}
//	}
//	db.~DBConnection();
//	return pets;
//
//}


Pet::~Pet() {}

std::vector<Pet> Pet::ourPet(int CustomerID, string Pet_Name, string Pet_Species, string Pet_Breed)
{
	string query = "SELECT * FROM pet WHERE "
		" CustomerID LIKE ? "
		" ORDER BY CustomerID ";

	DBConnection db;
	db.prepareStatement(query);
	db.stmt->setInt(1, CustomerID);


	vector<Pet> pets;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{
		while (db.res->next())
		{
			Pet tmpPet(db.res);
			pets.push_back(tmpPet);

		}
		db.~DBConnection();
		return pets;
	}
}

std::vector<Pet> Pet::findPet(std::string Pet_Name, bool ascending)
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

	vector<Pet> pets;

	db.QueryResult();

	if (db.res->rowsCount() > 0)
	{

		while (db.res->next())
		{
			Pet tmpPet(db.res);
			pets.push_back(tmpPet);

		}
	}
	db.~DBConnection();
	return pets;
}

