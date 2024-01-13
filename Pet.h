#pragma once
#ifndef PET_H
#define PET_H

#include <string>
#include <vector>
#include "DBConnection.h" 

using namespace std;
using namespace sql;

class Pet
{
public://access specifier
	int PetID , CustomerID; //numerical attributes
	std::string Pet_Name, Pet_Species, Pet_Gender, Pet_Breed, Pet_Age, Pet_Colour, Pet_Weight;


	Pet(); // constructor method
	Pet(int PetID, int CustomerID, std::string Pet_Name, std::string Pet_Species, std::string Pet_Gender, std::string Pet_Breed, std::string Pet_Age, std::string Pet_Colour, std::string Pet_Weight);
	
	Pet(sql::ResultSet* data);

	void insert();
	void update();
	void removePet();
	/*string encrypt();
	char toChar();
	void setPassword();
	string getPassword();*/

	~Pet(); //destructor method

	//static Pet selectPet(int PetID); 

	static std::vector<Pet> ourPet(int CustomerID, string Pet_Name, string Pet_Species, string Pet_Breed);
	static std::vector<Pet>findPet(std::string Pet_Name, bool ascending);
};

#endif
