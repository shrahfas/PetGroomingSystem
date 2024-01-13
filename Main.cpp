#include <iostream>  
#include <conio.h>
#include <iomanip>
#include <sstream>
#include <vector>
#include <regex>
#include <chrono>
//// advanced
//// include our custom class
#include "Customer.h"
#include "Admin.h"
#include "Staff.h"
#include "Pet.h"
#include "Menu.h"
#include "ArrowMenu.h"
#include "Package.h"
#include "Appointment.h"
#include "Payment.h"
#include "Sale.h"
using namespace std;

//

void custPage();
void registerCust();
void loginCust();
void custhome(Customer cuser, Package pack, Payment pay, Pet puser);
Customer custprofile(Customer cuser, Package pack, Payment pay, Pet puser);
Customer appointmentMenu(Customer cuser, Package pack, Payment pay, Pet puser);
Customer bookAppt(Customer cuser, Package pack, Payment pay, Pet puser);
Customer viewAppt(Customer cuser, Pet puser, Package pack, Payment pay);
//Customer bookAppointment(Customer cuser);
//void cartAppt(Customer cuser);
void pethome(Pet puser, Customer cuser, Package pack, Payment pay);
//void AppointmentBook();
Pet addPet(Pet puser, Customer cuser);
Package package(Package pack, Customer cuser, Payment pay, Pet puser);
Pet viewsPet(Pet puser, Customer cuser, Package pack, Payment pay);
bool validateDate(const std::string& date);
int packageSelection();
Pet profilePet(Customer cuser);
//Payment paybill(Customer cuser, Package pack, Payment pay, Pet puser);

//Package packDetail(Customer cuser, std::string package_name);
//void viewPet(Pet puser);
//void Appointment(Customer cuser);

//string hiddenInput(string prevValue);

void adminPage();
void registerAdmin();
void loginAdmin();
void adminhome(Admin auser);
Admin adminprofile(Admin auser);
Staff ManageStaff(Staff suser);
void packageMenu(Admin auser);
void addpackage(Admin auser);
void SaleReportMenu(Admin auser,Customer cuser,Payment pay,Package pack);
//void SaleReportMenu(Admin auser);
//void Adminhome(Admin auser);
//Admin adminprofile(Admin auser);
//void adminHome();

void staffPage();
void registerStaff();
void loginStaff();
void staffhome(Staff suser);
Staff staffprofile(Staff suser);
int viewStaff();
int viewPet();
Staff viewAppoint(Staff suser);
//Pet addpet(Pet puser);


//Account profile(Account user);
//void shop(Account user);
//Transaction products(Account user, int category, Transaction cart);
//
//Transaction productDetail(Account user, int productId, Transaction cart);
//Transaction cartMenu(Account user, Transaction cart);

//void SaleReportMenu(Account user);
//
//int productCategorySelection();


////utility functions
//bool isNumeric(string input);
//
//// extras
//bool toInteger(string* input, int* valueholder);
//

//Front page
int main()
{
	Menu mainmenu;
	mainmenu.header = "\n\t\t\t\t\t ----------------------------------- \n\t\t\t\t\t ----------------------------------- \n \n\t\t\t\t\t\t       WELCOME \n\t\t\t\t\t\t         to \n\t\t\t\t\t\tPET GROOMING SERVICES\n \n\t\t\t\t\t ----------------------------------- \n\t\t\t\t\t -----------------------------------\n";
	mainmenu.addOption("  Customer");
	mainmenu.addOption("  Admin");
	mainmenu.addOption("  Staff");
	mainmenu.addOption("  Exit ");

	while (1)
	{
		switch (mainmenu.prompt())
		{
		case 1:
			custPage();
			break;
		case 2:
			adminPage();
			break;
		case 3:
			staffPage();
			break;
		case 4:
			exit(0);
		}

	}
}

//customer front page
void custPage()
{
	Menu Rolemenu;
	Rolemenu.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tCUSTOMER PAGE\n \t\t\t\t\t--------------------------\n";
	Rolemenu.addOption("  Register");
	Rolemenu.addOption("  Login");
	Rolemenu.addOption("  Back");
	Rolemenu.footer = "\n\t\t\t\t\t--------------------------- \n\t\t\t\t\t---------------------------";

	while (1) {
		switch (Rolemenu.prompt())
		{
		case 1:
			registerCust();
			break;
		case 2:
			loginCust();
			break;
		case 3:
			main();
			break;
		}
	}
}

//Admin front page
void adminPage()
{
	Menu Rolemenu;
	Rolemenu.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tADMIN PAGE\n \t\t\t\t\t--------------------------";
	/*Rolemenu.addOption("Register");*/
	Rolemenu.addOption("Login");
	Rolemenu.addOption("Back");
	Rolemenu.footer = "\n\t\t\t\t\t--------------------------- \n\t\t\t\t\t---------------------------";

	while (1) {
		switch (Rolemenu.prompt())
		{
		/*case 1:
			registerAdmin();
			break;*/
		case 1:
			loginAdmin();
			break;
		case 2:
			main();
			break;
		}
	}
}

//staff front page
void staffPage()
{
	Menu Rolemenu;
	Rolemenu.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tSTAFF PAGE\n \t\t\t\t\t--------------------------";
	/*Rolemenu.addOption("Register");*/
	Rolemenu.addOption("Login");
	Rolemenu.addOption("Back");
	Rolemenu.footer = "\n\t\t\t\t\t--------------------------- \n\t\t\t\t\t---------------------------";


	while (1) {
		switch (Rolemenu.prompt())
		{
		///*case 1:
		//	cout << " \n\t\t\t\t\tStaff can't register by themselve. \n\t\t\t\t\tPlease ask Admin for staff registration ! ";
		//	_getch();*/
		//	break;
		case 1:
			loginStaff();
			break;
		case 2:
			main();
			break;
		}
	}
}

//register Customer
void registerCust()
{
	Customer newacc;

	Menu rcMenu;
	rcMenu.header = " \t\t\t\t\t------------------------------ \n\t\t\t\t\t\tRegistration\n \t\t\t\t\t------------------------------";
	rcMenu.addOption("Username");
	rcMenu.addOption("Password");
	rcMenu.addOption("Fullname");
	rcMenu.addOption("Email");
	rcMenu.addOption("Number Phone");
	rcMenu.addOption("Address");
	rcMenu.addOption("Register");
	rcMenu.addOption("Back");
	rcMenu.footer = "\n\t\t\t\t\t------------------------------- \n\t\t\t\t\t-------------------------------";

	string tmpinput;
	bool valid = true;
	while (1) {

		switch (rcMenu.prompt())
		{
		case 1 :
			cout << " Insert Username : ";
			cin >> newacc.username;
			rcMenu.setValue(0, newacc.username);
			break;

		case 2 :
			cout << " Insert Password : ";
			cin >> tmpinput;

			if (tmpinput.length() < 6) {
				cout << " Password must be at least 6 character long. ";
				_getch();
			}
			else {
				newacc.password = tmpinput;
				rcMenu.setValue(1, newacc.password);
			}
			break;

		case 3 :
			cout << "Insert Fullname : ";
			getline(cin, newacc.fullname);
			rcMenu.setValue(2, newacc.fullname);
			break;

		case 4 :
			cout << "Insert Email : ";
			cin >> newacc.email;
			rcMenu.setValue(3, newacc.email);
			break;

		case 5 :
			cout << "Insert Number Phone : ";
			cin >> newacc.numphone;
			rcMenu.setValue(4, newacc.numphone);
			break;

		case 6 :
			cout << "Insert Address : ";
			getline(cin, newacc.address);
			rcMenu.setValue(5, newacc.address);
			break;

		case 7 :

			if (newacc.fullname.empty() || newacc.email.empty() || newacc.numphone.empty() || newacc.password.empty() || newacc.username.empty() || newacc.address.empty())
			{
				cout << "\nPlease complete all fields before registering. Please Enter to continue registration\n";
				_getch();
				break;
			}

			cout << "\nAre sure to proceed the registeration ? (y/n)\n\n\n";
			char confirm;
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				valid = true;
				newacc.insert();
				cout << "\n\t\t\t\t--------- You have been Registered ! ----------";
				_getch();
			}
			break;

		case 8 :
			return;
		default :
			break;

		}
	}


}

//register admin
void registerAdmin()
{
	Admin newacc;

	Menu raMenu;
	raMenu.header = " \t\t\t\t\t------------------------------ \n\t\t\t\t\t\tRegistration\n \t\t\t\t\t------------------------------";
	raMenu.addOption("Username");
	raMenu.addOption("Password");
	raMenu.addOption("Fullname");
	raMenu.addOption("Email");
	raMenu.addOption("Address");
	raMenu.addOption("Register");
	raMenu.addOption("Back");
	raMenu.footer = "\n\t\t\t\t\t------------------------------- \n\t\t\t\t\t-------------------------------";

	string tmpinput;
	bool valid = true;
	while (1) {

		switch (raMenu.prompt())
		{
		case 1:
			cout << " Insert Username : ";
			cin >> newacc.Admin_Username;
			raMenu.setValue(0, newacc.Admin_Username);
			break;

		case 2:
			cout << " Insert Password : ";
			cin >> tmpinput;

			if (tmpinput.length() < 6) {
				cout << " Password must be at least 6 character long. ";
				_getch();
			}
			else {
				newacc.Admin_Password = tmpinput;
				raMenu.setValue(1, newacc.Admin_Password);
			}
			break;

		case 3:
			cout << "Insert Fullname : ";
			cin >> newacc.Admin_Fname;
			raMenu.setValue(2, newacc.Admin_Fname);
			break;

		case 4:
			cout << "Insert Email : ";
			cin >> newacc.Admin_Email;
			raMenu.setValue(3, newacc.Admin_Email);
			break;

		case 5:
			cout << "Insert Address : ";
			cin >> newacc.Admin_Add;
			raMenu.setValue(4, newacc.Admin_Add);
			break;

		case 6:
			cout << "\nAre sure to proceed the registeration ? (y/n)\n\n\n";
			char confirm;
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				valid = true;
				newacc.insert();  
				cout << "\n\t\t\t\t--------- You have been Registered ! ----------";
				_getch();
			}
			break;

		case 7:
			return;
		default:
			break;

		}
	}
}

//register staff
void registerStaff()
{
	Staff newacc;

	Menu rsMenu;
	rsMenu.header = " \t\t\t\t\t------------------------------ \n\t\t\t\t\t       Staff Registration\n \t\t\t\t\t------------------------------";
	rsMenu.addOption("Admin ID :");
	rsMenu.addOption("Username :");
	rsMenu.addOption("Password :");
	rsMenu.addOption("Fullname :");
	rsMenu.addOption("Phone Number :");
	rsMenu.addOption("Email :");
	rsMenu.addOption("Address :");
	rsMenu.addOption("Register");
	rsMenu.addOption("Back");
	rsMenu.footer = "\n\t\t\t\t\t------------------------------- \n\t\t\t\t\t-------------------------------";



	string tmpinput;
	bool valid = true;
	
	string tmpPassword = "";

	while (1) {

		switch (rsMenu.prompt())
		{
		case 1:
			cout << " Insert Admin ID : ";
			cin >> newacc.AdminID;
			rsMenu.setValue(0, to_string(newacc.AdminID));
			break;

		case 2:
			cout << " Insert Username : ";
			cin >> newacc.Staff_Username;
			rsMenu.setValue(1, newacc.Staff_Username);
			break;

		case 3:
			cout << " Insert Password (more than 6 character): ";
			cin >> tmpinput;

			if (tmpinput.length() < 6) {
				cout << " Password must be at least 6 character long. ";
				_getch();
			}
			else {
				newacc.Staff_Password = tmpinput;
				rsMenu.setValue(2, newacc.Staff_Password);
			}
			break;

		case 4:
			cout << "Insert Fullname : ";
			getline(cin, newacc.Staff_Fname);
			rsMenu.setValue(3, newacc.Staff_Fname);
			break;

		case 5:
			cout << "Insert Phone Number (Exp:0108312954) : ";
			cin >> newacc.Staff_PNum;
			rsMenu.setValue(4, newacc.Staff_PNum);
			break;

		case 6:
			cout << "Insert Email : ";
			cin >> newacc.Staff_Email;
			rsMenu.setValue(5, newacc.Staff_Email);
			break;

		case 7:
			cout << "Insert Address : ";
			getline(cin, newacc.Staff_Add);
			rsMenu.setValue(6, newacc.Staff_Add);
			break;

		case 8:
			cout << "\nAre sure to proceed the registeration ? (y/n)\n\n\n";
			char confirm;
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
				valid = true;
				newacc.insert();
				cout << "\n\t\t\t\t--------- You have been Registered ! ----------";
				_getch();
			}
			break;

		case 9:
			return;
		default:
			break;

		}
	}
}

//string hiddenInput(string prevValue)
//{
//	string input = "";
//	char tmp = '\0';
//	while (1) {
//		tmp = _getch();
//		switch (tmp)
//		{
//		case 13:
//			return input;
//			break;
//		case 27:
//			return prevValue;
//			break;
//		case 8:
//			if (input.length() > 0) {
//				input.erase(input.size() - 1);
//				cout << "\b \b";
//			}
//			break;
//		default:
//			if (tmp >= 32 && tmp <= 126) {
//				input += tmp;
//				cout << "*";
//
//			}
//			break;
//
//		}
//	}
//}

//login Customer
void loginCust()
{
	Menu loginCustomer;
	loginCustomer.header = "\n\t\t\t\t\t-----------------------------------\n\t\t\t\t\t\t  LOGIN OPTION\t\n\t\t\t\t\t-----------------------------------\n";
	loginCustomer.addOption("  username");
	loginCustomer.addOption("  password");
	loginCustomer.addOption("  Login");
	loginCustomer.addOption("  Back");
	loginCustomer.footer = "\n\t\t\t\t\t-----------------------------------\n";

	Customer cuser ;
	Payment pay;
	Package pack;
	Pet puser;

	char ch;

	string tmpinput = "";
	string tmpPassword = "";

	while (1) {
		switch (loginCustomer.prompt())
		{
		case 1 :
			cout << "Insert Username :";
			cin >> cuser.username;
			loginCustomer.setValue(0, cuser.username);
			break;

		case 2 :
			/*cout << "Insert Password : ";
			cin >> cuser.password;*/
			/*loginCustomer.setValue(1, cuser.password);*/
			cout << "Enter password: ";
			ch = _getch();
			while (ch != 13) {
				cuser.password.push_back(ch);
				cout << '*';
				ch = _getch();
				
			}
			loginCustomer.setValue(1, cuser.password);
			break;

		case 3 :
			if (cuser.login()) {
				custhome(cuser,pack,pay, puser);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;

		case 4 :
			custPage();
			break;
		}

		/*char ch;
		while ((ch = _getch()) != 13)
		{
			if (ch == '\b') {
				if (cuser.password.size() > 0)
				{
					cuser.password.erase(cuser.password.size() - 1, 1);
					cout << "\b \b";
				}
			}
		}*/
	}
		
}

//login Admin
void loginAdmin()
{
	Menu loginAdmin;
	loginAdmin.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tLOGIN OPTION\t\n\t\t\t\t----------------------------------------\n";
	loginAdmin.addOption("username");
	loginAdmin.addOption("password");
	loginAdmin.addOption("Login");
	loginAdmin.addOption("Back");

	Admin auser;

	while (1) {
		switch (loginAdmin.prompt())
		{
		case 1:
			cout << "Insert Username :";
			cin >> auser.Admin_Username;
			loginAdmin.setValue(0, auser.Admin_Username);
			break;

		case 2:
			cout << "Insert Password : ";
			cin >> auser.Admin_Password;
			loginAdmin.setValue(1, auser.Admin_Password);
			break;

		case 3:
			if (auser.login()) {
				adminhome(auser);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;

		case 4:
			adminPage();
			break;
		}
	}

}

//login staff
void loginStaff()
{
	Menu loginStaff;
	loginStaff.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tLOGIN OPTION\t\n\t\t\t\t----------------------------------------\n";
	loginStaff.addOption("username");
	loginStaff.addOption("password");
	loginStaff.addOption("Login");
	loginStaff.addOption("Back");

	Staff suser;

	while (1) {
		switch (loginStaff.prompt())
		{
		case 1:
			cout << "Insert Username :";
			cin >> suser.Staff_Username;
			loginStaff.setValue(0, suser.Staff_Username);
			break;

		case 2:
			cout << "Insert Password : ";
			cin >> suser.Staff_Password;
			loginStaff.setValue(1, suser.Staff_Password);
			break;

		case 3:
			if (suser.login()) {
				staffhome(suser);
			}
			else {
				cout << "Invalid Login";
				_getch();
			}
			break;

		case 4:
			staffPage();
			break;
		}
	}

}


// CUSTOMER PART 

// customer home 
void custhome(Customer cuser, Package pack, Payment pay, Pet puser) {


	ArrowMenu custhomeMenu;
	system("cls");

	custhomeMenu.header = "\n\t\t\t\t--------------------------------\n\t\t\t\t\tWelcome " + cuser.username + "\t\n\t\t\t\t-------------------------------- \n\t";
	custhomeMenu.addOption("Customer Profile");
	custhomeMenu.addOption("Pet");
	custhomeMenu.addOption("Appointment");
	custhomeMenu.addOption("Logout");
	while (1) {
		
		switch (custhomeMenu.prompt())
		{
		case -1 :
			loginCust;
			break;
		case 0:
			cuser = custprofile(cuser, pack, pay, puser);
			system("cls");
			break;
		case 1:
			pethome(puser, cuser, pack, pay);
			system("cls");
			break;
		case 2:
			appointmentMenu(cuser, pack, pay, puser);
			system("cls");
			break;
		case 3:
			loginCust();
			break;
		default:
			break;
		
		}
	}
} 

//Customer profile
Customer custprofile(Customer cuser, Package pack, Payment pay, Pet puser) {

	Customer temp = cuser;

	Menu CustMenu;
	CustMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tYour profile\t\n\t\t\t\t----------------------------------------";
	CustMenu.addOption("CustomerID");
	CustMenu.addOption("username");
	CustMenu.addOption("password");
	CustMenu.addOption("Fullname");
	CustMenu.addOption("email");
	CustMenu.addOption("Address");
	CustMenu.addOption("Save");
	CustMenu.addOption("Back");

	string tmpInput;
	while (1) {

		CustMenu.setValue(0, to_string(temp.CustomerID));
		CustMenu.setValue(1, temp.username);
		CustMenu.setValue(2, temp.password);
		CustMenu.setValue(3, temp.fullname);
		CustMenu.setValue(4, temp.email);
		CustMenu.setValue(5, temp.address);


		switch (CustMenu.prompt())
		{

		case 1:
			cout << " You cannot change the ID";
			_getch();
			break;
		case 2:
			cout << "Insert Username :";
			cin >> temp.username;
			break;
		case 3:
			cout << "Insert password";
			cin >> temp.password;
			break;
		case 4:
			cout << "Insert fullname";
			getline(cin, temp.fullname);
			break;
		case 5:
			cout << "Insert email";
			cin >> temp.email;
			break;
		case 6:
			cout << "Inser Address";
			getline(cin, temp.address);
			break;
		case 7:
			cuser = temp;
			cuser.update();
			cout << "Updated ! ";
			_getch();
		case 8 :
			return cuser;
			break;
		default:
			break;
		}

	}

}

//pet home ( pet section )
void pethome(Pet puser, Customer cuser, Package pack, Payment pay) {


	ArrowMenu pethomeMenu;
	system("cls");
	pethomeMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tPET MENU\t\n\t\t\t\t----------------------------------------";
	pethomeMenu.addOption("Add Pet");
	pethomeMenu.addOption("View Pet ");
	pethomeMenu.addOption("back");

	/*Pet puser;*/

	while (1) {

		switch (pethomeMenu.prompt())
		{
		case -1:
			custhome(cuser,pack,pay,puser);
			break;
		case 0 :
			puser = addPet(puser,cuser);
			system("cls");
			break;
		case 1 :
			profilePet(cuser);
			system("cls");
			break;
		case 2 :
			custhome(cuser, pack, pay, puser);
			break;
		default:
			break;
		}
	}
}

//add pet (more than 1 boleh)
Pet addPet(Pet puser, Customer cuser) {

	Pet newpet = puser;
	newpet.CustomerID = cuser.CustomerID;
	Menu petinformation;
	system("cls");

	petinformation.header = "\n\t\t\t\t----------------------------------------\n\t\t\t\t\t      PET INFORORMATION\t\n\t\t\t\t----------------------------------------";
	/*petinformation.addOption("  Customer ID");*/
	petinformation.addOption("  Pet Name");
	petinformation.addOption("  Pet Species");
	petinformation.addOption("  Pet Gender");
	petinformation.addOption("  Pet Breed");
	petinformation.addOption("  Pet Colour");
	petinformation.addOption("  Pet Weight");
	petinformation.addOption("  Add");
	petinformation.addOption("  Back");



	string tmpInput;
	while (1) {

		/*petinformation.header = */
		/*petinformation.setValue(0, to_string(newpet.CustomerID));*/
		petinformation.setValue(0, newpet.Pet_Name);
		petinformation.setValue(1, newpet.Pet_Species);
		petinformation.setValue(2, newpet.Pet_Gender);
		petinformation.setValue(3, newpet.Pet_Breed);
		petinformation.setValue(4, newpet.Pet_Colour);
		petinformation.setValue(5, newpet.Pet_Weight);


		switch (petinformation.prompt())
		{

		/*case 1 :
			cout << "Customer ID : ";
			cin >> tmpInput;
		    newpet.CustomerID = stoi(tmpInput);
			break;*/
		case 1:
			cout << "Pet Name :";
			getline(cin, newpet.Pet_Name);
			break;
		case 2:
			cout << "Pet Species : ";
			cin >> newpet.Pet_Species;
			break;
		case 3:
			cout << "Pet Gender : ";
			cin >> newpet.Pet_Gender;
			break;
		case 4:
			cout << "Pet Breed : ";
			getline(cin, newpet.Pet_Breed);
			break;
	
		case 5:
			cout << "Pet Colour : ";
			getline(cin, newpet.Pet_Colour);
			break;
		case 6:
			cout << "Pet Weight : ";
			getline(cin, newpet.Pet_Weight);
			break;
		case 7:
			puser = newpet;
			puser.insert();
			cout << "Pet has been added! ";
			_getch();


		case 8:
			return puser;
			break;

		
		}

	}

}

Pet viewsPet(Pet puser, Customer cuser, Package pack, Payment pay)
{

	vector<Pet> pets;
	Package selP;
	string dispP = "";

	int PetID = 0;
	string Pet_Name = "";
	bool asc = true;

	Menu PList;
	PList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tPackage Detail : \n \t\t\t\t\t--------------------------";
	PList.addOption("Pet Name");
	PList.addOption("Ordering");
	PList.addOption("List Pet");
	PList.addOption("Back ");

	while (1)
	{
		if (asc)
		{
			PList.setValue(1, "Ascending");
		}
		else
		{
			PList.setValue(1, "Descending");
		}

		if (dispP == "")
		{
			dispP = "\nPet List:\n\n";
			stringstream tmpP;
			tmpP << setw(4) << "Pet ID" << "|" << setw(20) << "Pet Name" << "|" << setw(17) << "Pet Gender" << "|" << setw(24) << "Pet Breed" << "|" << endl;
			tmpP << "__________________________________________________________________________" << endl;

			for (int i = 0; i < pets.size(); i++)
			{
				tmpP << setw(6) << pets[i].PetID << "|" << setw(20) << pets[i].Pet_Name << "|" << setw(17) << pets[i].Pet_Gender << "|" << setw(24) << pets[i].Pet_Breed << "|" << endl;
				tmpP << "__________________________________________________________________________" << endl;
			}
			dispP += tmpP.str();
		}
		PList.footer = dispP;

		switch (PList.prompt())
		{
		case 1:
			cout << " Insert Pet Name : ";
			getline(cin, Pet_Name);
			PList.setValue(0, Pet_Name);
			break;
		case 2:
			asc = !asc;
			break;
		case 3:
			pets = Pet::findPet(Pet_Name, asc);
			dispP = "";
			break;
		case 4:
			pethome(puser, cuser, pack, pay);
			break;
			/*cout << "Insert Package ID to select : ";
			int packageID;
			cin >> packageID;*/
			/*packDetail(cuser, package_name);*/
			/*break;*/
		//case 5:
		//	appointmentMenu(cuser);
		//	break;
		//	/*case 4 :
		//		cout << "Insert Staff ID : ";
		//		cin >> StaffID;
		//		selS=Staff::*/
		}
	}

}

//void Appoint(Customer cuser) {
//
//	Payment cart;
//	cart.cuser = cuser.CustomerID;
//
//	Menu ChMenu;
//	ChMenu.footer = " Select Package for Detail ";
//	ChMenu.addOption("Package 1");
//	ChMenu.addOption("Package 2");
//	ChMenu.addOption("Package 3");
//	ChMenu.addOption("Package 4");
//	ChMenu.addOption("Payment");
//	ChMenu.addOption("Back");
//
//	while (1) {
//		ChMenu.header = " Total Price :  " + to_string(cart.total());
//		switch (ChMenu.prompt())
//		{
//		case 1:
//			cart = package(cuser, 1, cart);
//			break;
//		case 2:
//			cart = package(cuser, 2, cart);
//
//		}
//	}
//}
//appointment page
Customer appointmentMenu(Customer cuser, Package pack, Payment pay, Pet puser) {
	 
	ArrowMenu appointmentMenu;
	appointmentMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\tAPPOINTMENT PAGE\t\n\t\t\t\t-----------------------------------";
	appointmentMenu.addOption("Booking Appointment");
	appointmentMenu.addOption("Appointment list");
	appointmentMenu.addOption("Back");


	while (1) {

		switch (appointmentMenu.prompt())
		{
		case -1:
			custhome(cuser, pack, pay, puser);
			break;
		case 0:
			package(pack,cuser,pay, puser);
			break;
		case 1:
			viewAppt(cuser, puser, pack, pay);
			break;
		case 2:
			custhome(cuser, pack, pay, puser);
			break;
		default:
			break;
		}
	}
}

//void AppointmentBook()
//{
//	Appointment newAppt;
//	Menu apptMenu;
//	apptMenu.header = "\n\t\t\t\t\t --------------------------------- \n\t\t\t\t\t |           Package             |\n\t\t\t\t\t --------------------------------- \n\n\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t |  Package 1 : Basic Grooming    |\t\t\t\t |  Package 2 : Fleas Treatment   |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t | * Nail Trim                    |\t\t\t\t | * Basic Groom                  |\n\t | * Ear Cleaning                 |\t\t\t\t | * Bath with anti-Flea          |\n\t | * Bath with specially          |\t\t\t\t |   Shampoo                      |\n\t |   Formulated Shampoo           | \t\t\t\t |                                |\n\t | * Brush Out                    |\t\t\t\t |                                |\n\t | * Blow Dray                    |\t\t\t\t | Price    : RM 60               |\n\t | Price    : RM 45               |\t\t\t\t | Duration : 2.5 hours           |\n\t | Duration : 2 hours             |\t\t\t\t |                                |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\n\n\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t |  Package 3 : Fungus Treatment  |\t\t\t\t |  Package 4 : Full Body Trim    |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t | * Basic groom                  |\t\t\t\t | * Basic groom                  |\n\t | * Bath with medicated          |\t\t\t\t | * Trim your long-haired        |\n\t |   Shampoo for skin             |\t\t\t\t |   Cat and made tidy, short     |\n\t |                                | \t\t\t\t |  and Clean                     |\n\t |                                |\t\t\t\t |                                |\n\t | Price    : RM 62               |\t\t\t\t | Price    : RM 100              |\n\t | Duration : 2.5 hours           |\t\t\t\t | Duration : 4 hours             |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\n";
//	apptMenu.addOption("Enter PetID");
//	apptMenu.addOption("Select PackageID");
//	apptMenu.addOption("Set Date (yyyy/mm/dd)");
//	apptMenu.addOption("Set Time (in format 24h. Eg: HHMM (1430)");
//	apptMenu.addOption("Book");
//	//apptMenu.addOption("Proceed ");
//	apptMenu.addOption("Done");
//
//	bool valid = true;
//
//	while (1)
//	{
//		switch (apptMenu.prompt())
//		{
//		case 1:
//			cout << "Enter Pet ID: ";
//			cin >> newAppt.PetID;
//			apptMenu.setValue(0, to_string(newAppt.PetID));
//			break;
//		case 2:
//			cout << "Select Package ID: ";
//			cin >> newAppt.packageID;
//			apptMenu.setValue(1, to_string(newAppt.packageID));
//			break;
//		case 3:
//			cout << "Set Date For Booking (yyyy/mm/dd): ";
//			cin >> newAppt.App_Date;
//			apptMenu.setValue(2, newAppt.App_Date);
//			break;
//		case 4:
//
//			cout << "Set Time For Booking (in 24h format): ";
//			cin >> newAppt.App_Time;
//			apptMenu.setValue(3, newAppt.App_Time);
//			break;
//		case 5:
//			cout << "Proceed the booking? (y/n): ";
//			char confirm;
//			confirm = _getch();
//			if (confirm == 'Y' || confirm == 'y')
//			{
//				newAppt.insertAppointment();
//				cout << " Booking successful.";
//				_getch();
//				/*cartAppt(cuser);*/
//			}
//			//else (confirm == 'N' || confirm == 'n');
//			//{
//			//	cout << " Booking was cancelled.";
//			//	_getch();
//			//	/*cartAppt(cuser);*/
//			//}
//			break;
//		case 6:
//			custhome;
//			break;
//
//		default:
//			break;
//		}
//	}
//
//
//}

Customer bookAppt(Customer cuser, Package pack, Payment pay, Pet puser)
{

	int PetID = 0, packagetID = 0, CustomerID = 0, AppointmentID = 0;
	Appointment book ;
	/*vector<Appointment> appointment;*/
	double paym = 0.0;
	double payment = 0.0;
	double Total_Payment = 0.0;
	string dateTime = "";
	string displayString = " ", App_Date = "", App_Time = "";
	pay.paymentID = book.packageID;

	Menu apptMenu;
	apptMenu.header = "\n\t\t\t\t\t----------------------------------------\n\t\t\t\t\t\tBook Appointment\n\t\t\t\t\t----------------------------------------";
	apptMenu.addOption(" Enter PetID");
	apptMenu.addOption(" Select PackageID");
	apptMenu.addOption(" Set Date (yyyy/mm/dd)");
	apptMenu.addOption(" Set Time (in format 24h. Eg: HHMM (1430)");
	apptMenu.addOption(" Book");
	apptMenu.addOption(" Procedd to Payment");
	apptMenu.addOption(" Back");
	bool valid = true;
	char confirm;
	while (1)
	{
		switch (apptMenu.prompt())
		{
		case 1:
			cout << "Enter Pet ID: ";
			cin >> book.PetID;
			apptMenu.setValue(0, to_string(book.PetID));
			break;
		case 2:

			/*AppointmentList();*/
			cout << "Select Package ID: ";
			cin >> book.packageID;
			apptMenu.setValue(1, to_string(book.packageID));
			break;
		case 3:
				cout << "Set Date For Booking (yyyy-mm-dd): ";
				cin.ignore();  
				cin >> book.App_Date;
				if (book.App_TimeExists(book.App_Date))
				{
					cout << "\n\t\tDate for this appointment is already htaken by another appointment. Please choose a different Date. \n";
					_getch();
					cout << "\n\t\tInsert different Date : ";
					cin >> book.App_Date;
				}
				apptMenu.setValue(2, book.App_Date);
				break;
		case 4:
			/*slotTime();*/
			cout << "Set Time For Booking (in 24h format): ";
			cin >> book.App_Time;
			/*if (book.App_TimeExists(book.App_Time))
			{
				cout << "\n\t\tTime slot for this appointment is already htaken by another appointment. Please choose a different Time slot. \n";
				_getch();
				cout << "\n\t\tInsert different Date : ";
				cin >> book.App_Time;
			}*/
			apptMenu.setValue(3, book.App_Time);
			break;
		case 5:
			cout << "Proceed the booking? (y/n): ";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y')
			{
				book.insertAppointment();
				cout << "\nBooking successful.";
				_getch();
			}
			else
				cout << "\nBooking cancelled. ";
			_getch();
			break;
		case 6:
			//paybill(cuser, pack, pay, puser);
			system("cls");
			cout << "\n\t\tYour appointment details : \n\n\tPet ID : " + to_string(book.PetID) + "\n\tpackage ID : " + to_string(book.packageID)
				+ "\n\tBooking Date : " + book.App_Date + "\n\tBooking Time : " + book.App_Time;
			_getch();


			while (book.packageID != 0)
			{
				if (book.packageID == 1)
				{
					cout << "\n\n\t----------------------------------\n\t  | Package 1 : Basic Grooming \t | \n\t----------------------------------\n\n\t  * Nail Trim \t\t\t \n\t  * Ear Cleaning \t\t \n\t  * Bath with specially \t \n\t  Formulated Shampoo \t\t   \n\t  * Brush Out \t\t\t \n\t  * Blow Dray \t\t\t \n\t  Price : RM 70 \t\t   \n\t  Duration : 2 hours \t\   \n\n\t----------------------------------";
					pay.paym = 30;
					pay.payment = 70 * 1;
					pay.Total_Payment = 70 + 30;
					cout << "\n\t Total : RM " + to_string(pay.payment);
					break;
				}
				else if (book.packageID == 2)
				{
					cout << "\n\n\t----------------------------------\n\t  | Package B : Fleas Treatment | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Bath with anti-Flea \t \n\t  Shampoo \t\t   \n\n\t  Price    : RM 120 \t\t   \n\t  Duration : 3 hours \t\   \n\n\t----------------------------------";
					pay.paym = 30;
					pay.payment = 120 * 1;
					pay.Total_Payment = 120 + 30;
					cout << "\n\t Total : RM " + to_string(pay.payment) + "\n\n\t----------------------------------";
					break;
				}
				else if (book.packageID == 3)
				{
					cout << "\n\n\t----------------------------------\n\t | Package C : Fungus Treatment | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Bath with medicated \t \n\t  Shampoo for skin \t\t   \n\n\t  Price    : RM 150 \t\t   \n\t  Duration : 3 hours \t\   \n\n\t----------------------------------";
					pay.paym = 30;
					pay.payment = 150 * 1 ;
					pay.Total_Payment = 150 + 30;
					cout << "\n\t Total : RM " + to_string(pay.payment) + "\n\n\t----------------------------------";
					break;
				}
				else if (book.packageID == 4)
				{
					cout << "\n\n\t----------------------------------\n\t | Package D : Full Body Trim | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Trim your long-haired \t \n\t  Cat and made tidy, short \t \n\t  & Clean \t\t   \n\t Price    : RM 200 \t\t   \n\t  Duration : 4 hours \t\   \n\n\t----------------------------------\n";
					pay.paym = 30;
					pay.payment = 200 * 1 ;
					pay.Total_Payment = 200 + 30;
					cout << "\n\t Price : RM " + to_string(pay.payment) + "\n\n\t----------------------------------";
					break;
				}
			}
			/*book.AppointmentID = pay.AppointmentID;*/
			book.packageID = pay.packageID;
			book.PetID = pay.PetID;

			cout << "\n\n\n\t\t***************************************************************************";
			cout << "\n\t\t\tDo you want to proceed the payment ?  (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y')
			{
				cout << "\n\t\t\tRe-enter Your Package ID : ";
				cin >> pay.packageID;
				cout << " \n\t\t\tRe-enter Your Pet ID : ";
				cin >> pay.PetID;

				pay.insertPayment();
				cout << "\n\t\t\tPayment succesfull. ";
				cout << "\n\n\n\t\t ****************************** YOUR RECEIPT ****************************** \n\n\t\t\t Your booking for package " + to_string(pay.packageID)
					+ "has been assigned. \n\n\t\t\tDate : " + book.App_Date
					+ "\n\n\t\t\tTime Slot : " + book.App_Time
					/*+ "\n\n\t\t\tAppointment ID : " + to_string(book.AppointmentID)*/
					+ "\n\n\t\t\tPackage Price : RM" + to_string(pay.payment)
					+ "\n\n\t\t\tTax and Service : RM" + to_string(pay.paym)
					+ "\n\n\n\t\t\tTotal Payment : RM" + to_string(pay.Total_Payment)
					+ "\n\n\t\t\tBooking made on : " + pay.dateTime 
					+ "\n\n\t\t\tShow the receipt at the reception for you appointment . Thank You :) \n"
					+ "**************************************************************************";
			}
			else
				cout << "\n\n\t\tPayment cancelled. ";
			_getch();
			break;

		case 7:
			custhome(cuser,pack,pay, puser);
			break;
		default:
			break;
		}
	}

}

//Payment paybill(Customer cuser, Package pack, Payment pay, Pet puser)
//{
//
//	int PetID = 0, packagetID = 0, CustomerID = 0, AppointmentID = 0;
//	Appointment book;
//	vector<Appointment> appointment;
//	double paym = 0.0;
//	double payment = 0.0;
//	double Total_Payment = 0.0;
//	string dateTime = "";
//	string displayString = " ", App_Date = "", App_Time = "";
//	pay.paymentID = book.packageID;
//	Payment newpayment = pay;
//	pay.AppointmentID = book.AppointmentID;
//	bool valid = true;
//	char confirm;
//
//	Menu payMenu;
//
//	payMenu.addOption(" Payment ");
//	payMenu.addOption(" Back");
//
//	while (1)
//	{
//		switch (payMenu.prompt())
//		{
//
//		case 1:
//			cout << "\n\t\tYour appointment details : \n\n\tPet ID : " + to_string(book.PetID) + "\n\tpackage ID : " + to_string(book.packageID)
//				+ "\n\tAppointmentID : " + to_string(book.AppointmentID) + "\n\tBooking Date : " + book.App_Date + "\n\tBooking Time : " + book.App_Time;
//			_getch();
//
//
//			while (book.packageID != 0)
//			{
//				if (book.packageID == 1)
//				{
//					cout << "\n\n\t----------------------------------\n\t  | Package 1 : Basic Grooming \t | \n\t----------------------------------\n\n\t  * Nail Trim \t\t\t \n\t  * Ear Cleaning \t\t \n\t  * Bath with specially \t \n\t  Formulated Shampoo \t\t   \n\t  * Brush Out \t\t\t \n\t  * Blow Dray \t\t\t \n\t  Price : RM 45 \t\t   \n\t  Duration : 2 hours \t\   \n\n\t----------------------------------";
//					pay.paym = 30;
//					pay.payment = 70 * 1;
//					pay.Total_Payment = 70 + 30;
//					cout << "\n\t Total : RM " + to_string(pay.payment);
//					break;
//				}
//				else if (book.packageID == 2)
//				{
//					cout << "\n\n\t----------------------------------\n\t  | Package B : Fleas Treatment | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Bath with anti-Flea \t \n\t  Shampoo \t\t   \n\n\t  Price    : RM 60 \t\t   \n\t  Duration : 2.5 hours \t\   \n\n\t----------------------------------";
//					pay.Total_Payment = 120 * 1;
//					cout << "\n\t Total : RM " + to_string(pay.Total_Payment);
//					break;
//				}
//				else if (book.packageID == 3)
//				{
//					cout << "\n\n\t----------------------------------\n\t | Package C : Fungus Treatment | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Bath with medicated \t \n\t  Shampoo for skin \t\t   \n\n\t  Price    : RM 62 \t\t   \n\t  Duration : 2.5 hours \t\   \n\n\t----------------------------------";
//					pay.Total_Payment = 150 * 1;
//					cout << "\n\t Total : RM " + to_string(pay.Total_Payment);
//					break;
//				}
//				else if (book.packageID == 4)
//				{
//					cout << "\n\n\t----------------------------------\n\t | Package D : Full Body Trim | \n\t----------------------------------\n\n\t  *Basic Groom \t\t\t \n\t  *Trim your long-haired \t \n\t  Cat and made tidy, short \t \n\t  & Clean \t\t   \n\t Price    : RM 100 \t\t   \n\t  Duration : 4 hours \t\   \n\n\t----------------------------------\n";
//					pay.Total_Payment = 200 * 1;
//					cout << "\n\t Total : RM " + to_string(pay.Total_Payment);
//					break;
//				}
//			}
//			book.AppointmentID = pay.AppointmentID;
//			book.packageID = pay.packageID;
//			book.PetID = pay.PetID;
//
//			cout << "\n\n\n\t***************************************************************************";
//			cout << "\n\t\tDo you want to proceed the payment ?  (y/n)";
//			confirm = _getch();
//			if (confirm == 'Y' || confirm == 'y')
//			{
//				cout << "\n\t\tRe-enter Your Package ID : ";
//				cin >> pay.packageID;
//				cout << " \n\t\tRe-enter Your Pet ID : ";
//				cin >> pay.PetID;
//				pay.insertPayment();
//				cout << "\n\t\tPayment succesfull. ";
//				cout << "\n\n\t\t\t ******************** YOUR RECEIPT ******************** \n\n\t Your booking for package " + to_string(pay.packageID) + " has been assigned. \nDate : " + book.App_Date
//					+ "\n\n\t\t\tTime Slot : " + book.App_Time
//					+ "\n\n\t\t\tPackage Price : RM" + to_string(pay.payment)
//					+ "\n\n\t\t\tTax and Service : RM" + to_string(pay.paym)
//					+ "\n\n\n\t\t\ttotal Payment : RM" + to_string(pay.Total_Payment)
//					+ "\n\n\t\t\t Booking made on : " + dateTime
//					+ "\n\n\t\t\tShow the receipt at the reception for you appointment . Thank You :) ";
//			}
//			else
//				cout << "\n\n\t\tPayment cancelled. ";
//			_getch();
//			break;
//
//		case 2:
//			custhome(cuser, pack, pay, puser);
//			break;
//		default:
//			break;
//		}
//	}
//}

//View package & booking slot

Package package(Package pack, Customer cuser, Payment pay, Pet puser)
{
	Package temp;
	vector<Package> packages;
	Package selP;
	string dispP = "";

	int packageID = 0;
	string package_name = "";
	bool asc = true;

	Menu PList;
	PList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tPackage Detail : \n \t\t\t\t\t--------------------------";
	PList.addOption("Package Name");
	PList.addOption("Sort");
	PList.addOption("List Package");
	PList.addOption("Booking ");
	PList.addOption("Back ");

	while (1)
	{
		if (asc)
		{
			PList.setValue(1, "Ascending");
		}
		else
		{
			PList.setValue(1, "Descending");
		}

		if (dispP == "")
		{
			dispP = "\nPackage List:\n\n";
			stringstream tmpP;
			tmpP << setw(4) << "\tPackage ID" << "|" << setw(20) << "Price" << "|" << setw(25) << "Package Name" << "|" << setw(15) << "Duration" << "|" << endl;
			tmpP << "\t__________________________________________________________________________" << endl;

			for (int i = 0; i < packages.size(); i++)
			{
				tmpP << "\t" << setw(6) << packages[i].packageID << "|" << setw(25) << packages[i].price << "|" << setw(24) << packages[i].package_name << "|" << setw(15) << packages[i].Duration << "|" << endl;
				tmpP << "\t__________________________________________________________________________" << endl;
			}
			dispP += tmpP.str();
		}
		PList.footer = dispP;

		switch (PList.prompt())
		{
		case 1:
			cout << " Insert Package Name : ";
			getline(cin, package_name);
			PList.setValue(0, package_name);
			break;
		case 2:
			asc = !asc;
			break;
		case 3:
			packages = Package::findPackage(package_name, asc);
			dispP = "";
			break;
		case 4:
			bookAppt(cuser, pack, pay, puser);
			break;
			/*cout << "Insert Package ID to select : ";
			int packageID;
			cin >> packageID;*/
			/*packDetail(cuser, package_name);*/
			break;
		case 5:
			appointmentMenu(cuser, pack, pay, puser);
			break;
			/*case 4 :
				cout << "Insert Staff ID : ";
				cin >> StaffID;
				selS=Staff::*/
		}
	}

}

Customer viewAppt(Customer cuser, Pet puser, Package pack, Payment pay)
{

	vector<Appointment> appointments;
	Appointment selA;
	string dispA = "";

	int AppointmentID = 0;
	int PetID = 0;
	string Pet_Name = "";
	bool asc = true;

	Menu AList;
	AList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tPackage Detail : \n \t\t\t\t\t--------------------------";
	AList.addOption("Pet ID ");
	AList.addOption("Ordering");
	AList.addOption("List Pet");
	AList.addOption("Back ");

	while (1)
	{
		if (asc)
		{
			AList.setValue(1, "Ascending");
		}
		else
		{
			AList.setValue(1, "Descending");
		}

		if (dispA == "")
		{
			dispA = "\n\tPet List:\n\n";
			stringstream tmpA;
			tmpA << setw(4) << "\t\tAppointment ID" << "|" << setw(15) << "Pet ID" << "|" << setw(17) << "Package ID" << "|" << setw(24) << "App Date" << "|" << setw(24) << "App Time" << "|" << endl;
			tmpA << "\t\t___________________________________________________________________________________________________" << endl;

			for (int i = 0; i < appointments.size(); i++)
			{
				tmpA << "\t\t" << setw(8) << appointments[i].AppointmentID << "|" << setw(20) << appointments[i].PetID << "|" << setw(17) << appointments[i].packageID << "|" << setw(24) << appointments[i].App_Date << "|" << setw(24) << appointments[i].App_Time << "|" << endl;
				tmpA << "\t\t___________________________________________________________________________________________________" << endl;
			}
			dispA += tmpA.str();
		}
		AList.footer = dispA;

		switch (AList.prompt())
		{
		case 1:
			cout << " Insert Pet ID : ";
			cin >> PetID;
			AList.setValue(0,to_string (PetID));
			break;
		case 2:
			asc = !asc;
			break;
		case 3:
			appointments = Appointment::findBook(PetID, asc);
			dispA = "";
			break;
		case 4:
			pethome(puser, cuser, pack, pay);
			break;
			/*cout << "Insert Package ID to select : ";
			int packageID;
			cin >> packageID;*/
			/*packDetail(cuser, package_name);*/
			/*break;*/
		//case 5:
		//	appointmentMenu(cuser);
		//	break;
		//	/*case 4 :
		//		cout << "Insert Staff ID : ";
		//		cin >> StaffID;
		//		selS=Staff::*/
		}
	}

}


//Customer bookAppointment(Customer cuser)
//{
//	int PetID = 0, packageID = 0, CustomerID = 0;
//
//	Appointment book ;
//	/*Payment pay;*/
//	vector<Package> package;
//	string displayString = " ", App_Date = "", App_Time = "";
//
//	Menu apptMenu;
//	apptMenu.header = "\n\t\t\t\t\t --------------------------------- \n\t\t\t\t\t |           Package             |\n\t\t\t\t\t --------------------------------- \n\n\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t |  Package 1 : Basic Grooming    |\t\t\t\t |  Package 2 : Fleas Treatment   |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t | * Nail Trim                    |\t\t\t\t | * Basic Groom                  |\n\t | * Ear Cleaning                 |\t\t\t\t | * Bath with anti-Flea          |\n\t | * Bath with specially          |\t\t\t\t |   Shampoo                      |\n\t |   Formulated Shampoo           | \t\t\t\t |                                |\n\t | * Brush Out                    |\t\t\t\t |                                |\n\t | * Blow Dray                    |\t\t\t\t | Price    : RM 60               |\n\t | Price    : RM 45               |\t\t\t\t | Duration : 2.5 hours           |\n\t | Duration : 2 hours             |\t\t\t\t |                                |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\n\n\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t |  Package 3 : Fungus Treatment  |\t\t\t\t |  Package 4 : Full Body Trim    |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\t | * Basic groom                  |\t\t\t\t | * Basic groom                  |\n\t | * Bath with medicated          |\t\t\t\t | * Trim your long-haired        |\n\t |   Shampoo for skin             |\t\t\t\t |   Cat and made tidy, short     |\n\t |                                | \t\t\t\t |  and Clean                     |\n\t |                                |\t\t\t\t |                                |\n\t | Price    : RM 62               |\t\t\t\t | Price    : RM 100              |\n\t | Duration : 2.5 hours           |\t\t\t\t | Duration : 4 hours             |\n\t ----------------------------------\t\t\t\t ----------------------------------\n\n";
//	apptMenu.addOption("Enter PetID");
//	apptMenu.addOption("Select PackageID");
//	apptMenu.addOption("Set Date (yyyy/mm/dd)");
//	apptMenu.addOption("Set Time (in format 24h. Eg: HHMM (1430)");
//	apptMenu.addOption("Book");
//	apptMenu.addOption("Proceed ");
//	apptMenu.addOption("Done");
//
//	bool valid = true;
//	char confirm;
//	while (1)
//	{
//		switch (apptMenu.prompt())
//		{
//		case 1:
//			cout << "Enter Pet ID: ";
//			cin >> book.PetID;
//			apptMenu.setValue(0, to_string(book.PetID));
//			break;
//		case 2:
//			cout << "Select Package ID: ";
//			cin >> book.packageID;
//			apptMenu.setValue(1, to_string(book.packageID));
//			break;
//		case 3:
//			cout << "Set Date For Booking (yyyy/mm/dd): ";
//			cin >> book.App_Date;
//			apptMenu.setValue(2, book.App_Date);
//			break;
//		case 4:
//
//			cout << "Set Time For Booking (in 24h format): ";
//			cin >> book.App_Time;
//			apptMenu.setValue(3, book.App_Time);
//			break;
//		case 5:
//			cout << "Proceed the booking? (y/n): ";
//			confirm = _getch();
//			if (confirm == 'Y' || confirm == 'y')
//			{
//				book.insertAppointment();
//				cout << " Booking successful.";
//				_getch();
//				/*cartAppt(cuser);*/
//			}
//			else (confirm == 'N' || confirm == 'n');
//			{
//				cout << " Booking was cancelled.";
//				_getch();
//				/*cartAppt(cuser);*/
//			}
//			break;
//		case 6:
//			custhome(cuser);
//			break;
//
//		default:
//			break;
//		}
//	}
//}

//void cartAppt(Customer cuser)
//{
//
//	Appointment book;
//
//	book.PetID = cuser.CustomerID;
//
//	Menu packageMenu;
//
//	packageMenu.header = "\n\t\t\t ------------------------------------------------------------------\n\t\t\t\t\t            APPOINTMENT\n\t\t\t ------------------------------------------------------------------\n\n\n\n\t\t\t\t\t ---------------------------------\n\t\t\t\t\t |           Package             |\n\t\t\t\t\t --------------------------------- \n\n ";
//	packageMenu.addOption("\t----------------------------------\n\t \t\t\t\t\t| Package A : Basic Grooming \t| \n\t\t\t\t\t\t----------------------------------\n\n\t \t\t\t\t\t *Nail Trim \t\t\t \n\t \t\t\t\t\t *Ear Cleaning \t\t \n\t   \t\t\t\t\t *Bath with specially \t \n\t \t\t\t\t\t Formulated Shampoo \t\t   \n\t \t\t\t\t\t *Brush Out \t\t\t \n\t \t\t\t\t\t *Blow Dray \t\t\t \n\t \t\t\t\t\t Price    : RM 45 \t\t   \n\t \t\t\t\t\t Duration : 2 hours \t\   \n\n\t\t\t\t\t\t----------------------------------\n");
//	packageMenu.addOption("\t----------------------------------\n\t \t\t\t\t\t| Package B : Fleas Treatment \t| \n\t\t\t\t\t\t----------------------------------\n\n\t \t\t\t\t\t *Basic Groom \t\t\t \n\t \t\t\t\t\t *Bath with anti-Flea \t \n\t \t\t\t\t\t Shampoo \t\t   \n\t \t\t\t\t\t Price    : RM 60 \t\t   \n\t \t\t\t\t\t Duration : 2.5 hours \t\   \n\n\t\t\t\t\t\t----------------------------------\n");
//	packageMenu.addOption("\t----------------------------------\n\t \t\t\t\t\t| Package C : Fungus Treatment \t| \n\t\t\t\t\t\t----------------------------------\n\n\t \t\t\t\t\t *Basic Groom \t\t\t \n\t \t\t\t\t\t *Bath with medicated \t \n\t \t\t\t\t\t Shampoo for skin \t\t   \n\t \t\t\t\t\t Price    : RM 62 \t\t   \n\t \t\t\t\t\t Duration : 2.5 hours \t\   \n\n\t\t\t\t\t\t----------------------------------\n");
//	packageMenu.addOption("\t----------------------------------\n\t \t\t\t\t\t| Package D : Full Body Trim \t| \n\t\t\t\t\t\t----------------------------------\n\n\t \t\t\t\t\t *Basic Groom \t\t\t \n\t \t\t\t\t\t *Trim your long-haired \t \n\t \t\t\t\t\t Cat and made tidy, short \t \n\t \t\t\t\t\t & Clean \t\t   \n\t \t\t\t\t\t Price    : RM 100 \t\t   \n\t \t\t\t\t\t Duration : 4 hours \t\   \n\n\t\t\t\t\t\t----------------------------------\n");
//
//	packageMenu.addOption("View your booking:");
//	packageMenu.addOption("Back");
//
//	while (1)
//	{
//		packageMenu.header = "Package\n\n\n\n\t\t Your Booking: " + to_string(book.count()) + " \n\n\tTotal Price: " + to_string(book.total());
//		switch (packageMenu.prompt())
//		{
//		case 1:
//			//book = bookAppt(custs, 1, book);
//			break;
//		case 2:
//			//book = bookAppt(custs, 2, book);
//			break;
//		case 3:
//			//book = bookAppt(custs, 3, book);
//			break;
//		case 4:
//			//book = bookAppt(custs, 4, book);
//			break;
//		case 5:
//			//book = bookMenu(custs, book);
//			break;
//		case 6:
//			return;
//			break;
//
//		}
//	}
//}

//Customer bookAppt(Customer cuser)
//{
//	int PetID = 0, packageID = 0, CustomerID = 0;
//	Appointment book;
//	vector<Package> package;
//	string displayString = " ", Booking_Date = "", Booking_Time = "";
//
//	Menu apptMenu;
//
//	cout << "\n\t\t\t ------------------------------------------------------------------";
//		cout << "\n\t\t\t\t\t            APPOINTMENT ";
//		cout << "\n\t\t\t ------------------------------------------------------------------\n\n\n";
//	
//		cout << "\n\t\t\t\t\t --------------------------------- ";
//		cout << "\n\t\t\t\t\t |           Package             |";
//		cout << "\n\t\t\t\t\t --------------------------------- \n\n";
//	
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------";
//		cout << "\n\t |  Package A : Basic Grooming    |" << "\t\t\t\t |  Package B : Fleas Treatment   |";
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------";
//		cout << "\n\t | * Nail Trim                    |" << "\t\t\t\t | * Basic Groom                  |";
//		cout << "\n\t | * Ear Cleaning                 |" << "\t\t\t\t | * Bath with anti-Flea          |";
//		cout << "\n\t | * Bath with specially          |" << "\t\t\t\t |   Shampoo                      |";
//		cout << "\n\t |   Formulated Shampoo           | " << "\t\t\t\t |                                |";
//		cout << "\n\t | * Brush Out                    |" << "\t\t\t\t |                                |";
//		cout << "\n\t | * Blow Dray                    |" << "\t\t\t\t | Price    : RM 60               |";
//		cout << "\n\t | Price    : RM 45               |" << "\t\t\t\t | Duration : 2.5 hours           |";
//		cout << "\n\t | Duration : 2 hours             |" << "\t\t\t\t |                                |";
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------\n\n\n";
//	
//	
//	
//	
//	
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------";
//		cout << "\n\t |  Package C : Fungus Treatment  |" << "\t\t\t\t |  Package D : Full Body Trim    |";
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------";
//		cout << "\n\t | * Basic groom                  |" << "\t\t\t\t | * Basic groom                  |";
//		cout << "\n\t | * Bath with medicated          |" << "\t\t\t\t | * Trim your long-haired        |";
//		cout << "\n\t |   Shampoo for skin             |" << "\t\t\t\t |   Cat and made tidy, short     |";
//		cout << "\n\t |                                | " << "\t\t\t\t |  and Clean                     |";
//		cout << "\n\t |                                |" << "\t\t\t\t |                                |";
//		cout << "\n\t | Price    : RM 62               |" << "\t\t\t\t | Price    : RM 100              |";
//		cout << "\n\t | Duration : 2.5 hours           |" << "\t\t\t\t | Duration : 4 hours             |";
//		cout << "\n\t ----------------------------------" << "\t\t\t\t ----------------------------------\n\n";
//	
//		cout << " Select your package : \n\n\n";


//admin home
void adminhome(Admin auser) {

	Customer cuser;
	Payment pay;
	Package pack;
	Staff suser;

	Menu adminhomeMenu;
	adminhomeMenu.header = "\n\t\t\t\t\t-------------------------------\n\t\t\t\t\t\tWelcome " + auser.Admin_Username + "\t\n\t\t\t\t\t-------------------------------";
	adminhomeMenu.addOption("Admin Profile");
	adminhomeMenu.addOption("Manage Staff");
	adminhomeMenu.addOption("Package");
	adminhomeMenu.addOption("Sales Report");
	adminhomeMenu.addOption("Logout");
	while (1) {

		switch (adminhomeMenu.prompt())
		{
		case 1:
			auser = adminprofile(auser);
			break;
		case 2 :
			ManageStaff(suser);
			break;
		case 3:
			packageMenu(auser);
			break;
		case 4:
			SaleReportMenu(auser, cuser, pay, pack);
			break;
		case 5:
			loginAdmin();
			break;
		default:
			break;
		}
	}
}

//admin profile (update)
Admin adminprofile(Admin auser) {

	Admin temp = auser;

	Menu adminMenu;
	adminMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tYour profile\t\n\t\t\t\t----------------------------------------";
	adminMenu.addOption("username");
	adminMenu.addOption("password");
	adminMenu.addOption("Fullname");
	adminMenu.addOption("email");
	adminMenu.addOption("Address");
	adminMenu.addOption("Save");
	adminMenu.addOption("Back");
	adminMenu.addOption("Delete Account");

	string tmpInput;
	while (1) {
		adminMenu.setValue(0, temp.Admin_Username);
		adminMenu.setValue(1, temp.Admin_Password);
		adminMenu.setValue(2, temp.Admin_Fname);
		adminMenu.setValue(3, temp.Admin_Email);
		adminMenu.setValue(4, temp.Admin_Add);


		switch (adminMenu.prompt())
		{
		case 1:
			cout << "Insert Username :";
			cin >> temp.Admin_Username;
			break;
		case 2:
			cout << "Insert password";
			cin >> temp.Admin_Password;
			break;
		case 3:
			cout << "Insert fullname";
			getline(cin, temp.Admin_Fname);
			break;
		case 4:
			cout << "Insert email";
			cin >> temp.Admin_Email;
			break;
		case 5:
			cout << "Inser Address";
			getline(cin, temp.Admin_Add);
			break;
		case 6:
			auser = temp;
			auser.update();
			cout << "Update";
			_getch();
		case 7:
			cout << "\nAre you done updating your profile ? (y/n)\n\n\n";
			char confirm;
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
			}
			return auser;
			break;
		default:
			break;
		}

	}

}

//Manage Staff ( admin handle )
Staff ManageStaff(Staff suser) {

	Menu manageStaff;

	manageStaff.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tMANAGE STAFF\n \t\t\t\t\t--------------------------";
	manageStaff.addOption("Register");
	manageStaff.addOption("View Staff List");
	manageStaff.addOption("Delete Staff");
	manageStaff.addOption("Back ");
	manageStaff.footer = "\n\t\t\t\t\t--------------------------- \n\t\t\t\t\t---------------------------";

	while (1) {
		switch (manageStaff.prompt())
		{
		case 1 :
			registerStaff();
			break;
		case 2 :
			viewStaff();
			break;
		case 3 : 
			//deleteStaff();
		case 4 :
			main();
			break;
		}
	}
}

//view staff
int viewStaff() 
{
	vector<Staff> staffs;
	Staff selS;
	string dispS = "";

	int StaffID = 0;
	string Staff_Fname = "";
	bool asc = true;

	Menu SList;
	SList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tSearch Staff : \n \t\t\t\t\t--------------------------";
	SList.addOption("Staff Name");
	SList.addOption("Ordering");
	SList.addOption("Search");
	SList.addOption("Select ");
	
	while (1)
	{
		if (asc)
		{
			SList.setValue(1, "Ascending");
		}
		else
		{
			SList.setValue(1, "Descending");
		}

		if (dispS == "")
		{
			dispS = "\nResult:\n";
			stringstream tmpS;
			tmpS << setw(4) << "Staff ID" << "|" << setw(20) << "Fullname" << "|" << setw(15) << "Phone Number" << "|" << setw(15) << "Staff Address" << "|" << endl;

			for (int i = 0; i < staffs.size(); i++)
			{
				tmpS << setw(4) << staffs[i].StaffID << "|" << setw(20) << staffs[i].Staff_Fname << "|" << setw(15) << staffs[i].Staff_PNum << "|" << setw(15) << staffs[i].Staff_Add << "|" << endl;

			}
			dispS += tmpS.str();
		}
		SList.footer = dispS;

		switch (SList.prompt())
		{
		case 1 :
			cout << " Insert Staff Name : ";
			getline(cin, Staff_Fname);
			SList.setValue(0, Staff_Fname);
			break;
		case 2 :
			asc = !asc;
			break;
		case 3 :
			staffs = Staff::findStaff(Staff_Fname, asc);
			dispS = "";
			break;
		/*case 4 :
			cout << "Insert Staff ID : ";
			cin >> StaffID;
			selS=Staff::*/
		}
	}
	
}

//package menu
void packageMenu(Admin auser) 
{
	Menu packageMenu;

	Admin Auser = auser;

	packageMenu.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tMANAGE STAFF\n \t\t\t\t\t--------------------------";
	packageMenu.addOption("Add Package");
	packageMenu.addOption("Update Package");
	packageMenu.addOption("Delete Package");
	packageMenu.addOption("Back ");
	packageMenu.footer = "\n\t\t\t\t\t--------------------------- \n\t\t\t\t\t---------------------------";

	while (1) {
		switch (packageMenu.prompt())
		{
		case 1:
			addpackage(Auser);
			break;
		case 2:
			/*loginStaff();*/
			break;
		case 3:
			//deleteStaff();
		case 4:
			main();
			break;
		}
	}
}

//Add package
void addpackage(Admin auser) {
	
	Package pack;

	Menu addpackage;
	addpackage.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tYour profile\t\n\t\t\t\t----------------------------------------";
	addpackage.addOption("Price ");
	addpackage.addOption("Package Name");
	addpackage.addOption("Duration");
	addpackage.addOption("Add");
	addpackage.addOption("Back");



	string tmpInput;
	while (1) {

		addpackage.setValue(0, to_string(pack.price));
		addpackage.setValue(1, pack.package_name);
		addpackage.setValue(2, pack.Duration);


		switch (addpackage.prompt())
		{
		case 1:
			cout << "Price : ";
			cin >> pack.price;
			addpackage.setValue(0, to_string(pack.price));
			break;
		case 2:
			cout << "Package Name : ";
			getline(cin, pack.package_name);
			addpackage.setValue(1, pack.package_name);
			break;
		case 3:
			cout << "Duration : ";
			getline(cin, pack.Duration);
			addpackage.setValue(2, pack.Duration);
			break;
		case 4:
			pack.insert();
			cout << "Package has been added! ";
			_getch();
		case 5:
			return ;
			break;
		default:
			break;
		}
	}

}

Pet profilePet(Customer cuser)
{
	Pet puser;
	Payment pay;
	Package pack;
	vector<Pet> pets;
	Pet selPet;
	string displayPet = "";
	Pet temp;
	int CustomerID = 0, PetID = 0;
	string Pet_Name = "", Pet_Species = "", Pet_Breed = "", Pet_Colour = "", Pet_Weight = "", Pet_Gender = "";
	bool asc = true;
	char confirm;
	Menu OPMenu;
	OPMenu.header = "\n\n\t ----------------- Your Pet profile ----------------- \n";
	//OPMenu.addOption("Customer ID   ");
	OPMenu.addOption("  Search by Customer ID ");
	OPMenu.addOption("  Search ");
	OPMenu.addOption("  Delete Pet Profile ");
	OPMenu.addOption("  Back ");

	while (1)
	{
		if (displayPet == "")
		{
			displayPet = "\n\n\t Your Pet: \n\n";
			stringstream tmpPet;
			tmpPet << setw(4) << "\t Customer ID" << "|" << setw(8) << " Pet ID" << "|" << setw(20) << "Pet Name" << "|" << setw(20) << "Pet Species" << "|"
				<< setw(20) << "Pet Breed" << "|" << setw(20) << "Pet Color" << "|" << setw(20) << "Pet Gender" << "|" << setw(20) << "Pet Weight" << "|" << endl;
			tmpPet << "\t -------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

			for (int i = 0; i < pets.size(); i++)
			{
				tmpPet << "\t" << setw(12) << pets[i].CustomerID << "|" << setw(8) << pets[i].PetID << "|" << setw(20) << pets[i].Pet_Name << "|" << setw(20) << pets[i].Pet_Species
					<< "|" << setw(20) << pets[i].Pet_Breed << "|" << setw(20) << pets[i].Pet_Colour << "|" << setw(20) << pets[i].Pet_Gender << "|" << setw(20) << pets[i].Pet_Weight << "|" << endl;
			    
				tmpPet << "\t --------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			}

			displayPet += tmpPet.str();
		}
		OPMenu.footer = displayPet;

		switch (OPMenu.prompt())
		{
		case 1:
			cout << " Search by CustID: ";
			cin >> CustomerID;
			OPMenu.setValue(0, to_string(CustomerID));
			pets = Pet::ourPet(CustomerID, Pet_Name, Pet_Species, Pet_Breed);
			displayPet = "";
			break;
		case 2:
			pets = Pet::ourPet(CustomerID, Pet_Name, Pet_Species, Pet_Breed);
			displayPet = "";
			break;
		case 3:
			cout << " Insert Pet ID: ";
			cin >> PetID;
			OPMenu.setValue(0, to_string(PetID));

			cout << "\n\n\t Are you sure want to delete pet details ? (y/n)";
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y')
			{
				temp.removePet();
				cout << "\n\n\t Pet details deleted.";
				_getch();
			}
			else
			{
				cout << "\n\n\t Pet details saved.";
				_getch();
			}
		case 4:
			pethome(puser, cuser, pack, pay );
		}
	}
}




// STAFF PART

//staff home
void staffhome(Staff suser) {
	Menu staffhomeMenu;
	staffhomeMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tWelcome " + suser.Staff_Username + "\t\n\t\t\t\t----------------------------------------";
	staffhomeMenu.addOption("Staff Profile");
	staffhomeMenu.addOption("Appointment List");
	staffhomeMenu.addOption("Pet List");
	staffhomeMenu.addOption("Logout");
	while (1) {

		switch (staffhomeMenu.prompt())
		{
		case 1 :
			suser = staffprofile(suser);
			break;
		case 2 :
			viewAppoint(suser);
			break;
		case 3 :
			viewPet();
			break;
		case 4 :
			loginStaff();
			break;
		default:
			break;
		}
	}
}

//staff profile (update)
Staff staffprofile(Staff suser) {

	Staff temp = suser;

	Menu staffMenu;
	staffMenu.header = "\n\t\t\t\t-----------------------------------\n\t\t\t\t\t\tYour profile\t\n\t\t\t\t----------------------------------------";
	staffMenu.addOption("username");
	staffMenu.addOption("password");
	staffMenu.addOption("Fullname");
	staffMenu.addOption("email");
	staffMenu.addOption("Address");
	staffMenu.addOption("Save");
	staffMenu.addOption("Back");
	staffMenu.addOption("Delete Account");

	string tmpInput;
	while (1) {
		staffMenu.setValue(0, temp.Staff_Username);
		staffMenu.setValue(1, temp.Staff_Password);
		staffMenu.setValue(2, temp.Staff_Fname);
		staffMenu.setValue(3, temp.Staff_Email);
		staffMenu.setValue(4, temp.Staff_Add);


		switch (staffMenu.prompt())
		{
		case 1:
			cout << "Insert Username :";
			cin >> temp.Staff_Username;
			break;
		case 2:
			cout << "Insert password";
			cin >> temp.Staff_Password;
			break;
		case 3:
			cout << "Insert fullname";
			getline(cin, temp.Staff_Fname);
			break;
		case 4:
			cout << "Insert email";
			cin >> temp.Staff_Email;
			break;
		case 5:
			cout << "Inser Address";
			getline(cin, temp.Staff_Add);
			break;
		case 6:
			suser = temp;
			suser.update();
			cout << "Update";
			_getch();
		case 7:
			cout << "\nAre you done updating your profile ? (y/n)\n\n\n";
			char confirm;
			confirm = _getch();
			if (confirm == 'Y' || confirm == 'y') {
			}
			return suser;
			break;
		default:
			break;
		}

	}

}

int viewPet()
{
	vector<Pet> pets;
	Pet selP;
	string dispP = "";

	int PetID = 0;
	string Pet_Name = "";
	bool asc = true;

	Menu PList;
	PList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tSearch  : \n \t\t\t\t\t--------------------------";
	/*PList.addOption("Staff Name");*/
	PList.addOption("Ordering");
	PList.addOption("List");
	PList.addOption("Select ");

	while (1)
	{
		if (asc)
		{
			PList.setValue(0, "Ascending");
		}
		else
		{
			PList.setValue(0, "Descending");
		}

		if (dispP == "")
		{
			dispP = "\nResult:\n";
			stringstream tmpP;
			tmpP << setw(7) << " Pet ID" << "|" << setw(10) << "Customer ID" << "|" << setw(10) << "Pet Name" << "|" << setw(10) << "Species" << "|" << setw(10) << "Gender" << "|" << setw(10) << "Weight" << "|" << endl;

			for (int i = 0; i < pets.size(); i++)
			{
				tmpP << setw(7) << pets[i].PetID << "|" << setw(11) << pets[i].CustomerID << "|" << setw(10) << pets[i].Pet_Name << "|" << setw(10) << pets[i].Pet_Species << "|" << setw(10) << pets[i].Pet_Gender << "|" << setw(10) << pets[i].Pet_Weight << "|" << endl;

			}
			dispP += tmpP.str();
		}
		PList.footer = dispP;

		switch (PList.prompt())
		{
		/*case 1:
			cout << " Insert Staff Name : ";
			getline(cin, Staff_Fname);
			SList.setValue(0, Staff_Fname);
			break;*/
		case 1:
			asc = !asc;
			break;
		case 2:
			pets = Pet::findPet(Pet_Name, asc);
			dispP = "";
			break;
			/*case 4 :
				cout << "Insert Staff ID : ";
				cin >> StaffID;
				selS=Staff::*/
		}
	}

}

// view appointment List
Staff viewAppoint(Staff suser)
{

	vector<Appointment> appointments;
	Appointment selA;
	string dispA = "";

	int AppointmentID = 0;
	int PetID = 0;
	string Pet_Name = "";
	bool asc = true;

	Menu AList;
	AList.header = "\t\t\t\t\t-------------------------- \n\t\t\t\t\t\tPackage Detail : \n \t\t\t\t\t--------------------------";
	AList.addOption("Pet ID ");
	AList.addOption("Ordering");
	AList.addOption("List Pet");
	AList.addOption("Back ");

	while (1)
	{
		if (asc)
		{
			AList.setValue(1, "Ascending");
		}
		else
		{
			AList.setValue(1, "Descending");
		}

		if (dispA == "")
		{
			dispA = "\nPet List:\n\n";
			stringstream tmpA;
			tmpA << setw(4) << "Appointment ID" << "|" << setw(15) << "Pet ID" << "|" << setw(17) << "Package ID" << "|" << setw(24) << "App Date" << "|" << setw(24) << "App Time" << "|" << endl;
			tmpA << "___________________________________________________________________________________________________" << endl;

			for (int i = 0; i < appointments.size(); i++)
			{
				tmpA << setw(8) << appointments[i].AppointmentID << "|" << setw(20) << appointments[i].PetID << "|" << setw(17) << appointments[i].packageID << "|" << setw(24) << appointments[i].App_Date << "|" << setw(24) << appointments[i].App_Time << "|" << endl;
				tmpA << "___________________________________________________________________________________________________" << endl;
			}
			dispA += tmpA.str();
		}
		AList.footer = dispA;

		switch (AList.prompt())
		{
		case 1:
			cout << " Insert Pet ID : ";
			cin >> PetID;
			AList.setValue(0, to_string(PetID));
			break;
		case 2:
			asc = !asc;
			break;
		case 3:
			appointments = Appointment::listBook(Pet_Name, asc);
			dispA = "";
			break;
		case 4:
			staffhome(suser);
			break;
			/*cout << "Insert Package ID to select : ";
			int packageID;
			cin >> packageID;*/
			/*packDetail(cuser, package_name);*/
			/*break;*/
		//case 5:
		//	appointmentMenu(cuser);
		//	break;
		//	/*case 4 :
		//		cout << "Insert Staff ID : ";
		//		cin >> StaffID;
		//		selS=Staff::*/
		}
	}

}


//HIDDEN PASSWORD

//string hiddenInput(string prevValue) {
//	string input = "";
//	char tmp = '\0';
//	while (1) {
//		tmp = _getch();
//		switch (tmp)
//		{
//		case 13:// ASCII code for enter key
//			return input;
//			break;
//		case 27://ASCII code for escape key
//			return prevValue; //return the previous value insteadd to cancel
//			break;
//		case 8:
//			if (input.length() > 0) {
//				input.erase(input.size() - 1); // erase last index
//				cout << "\b \b";
//				//print  this which will move back caret and replace character with space and move back caret 1 more time to imitate backspace
//			}
//			break;
//		default://for any other key press
//			if (tmp >= 32 && tmp <= 126) {
//				/// 32 until 126 is basically all the printable character in ASCII table,
//				// modify this range if you want to limit input, 
//				// for example 48~57 will only allow number input, 65~90 only uppercase, 97 ~122 only lowercase etc 
//				//when key press is within our acceptable range append the character into string
//				input += tmp;
//				//display a * instead
//				cout << "*";
//			}
//			//if the key press is outside of our allowed range simply skips it to ignore
//			break;
//		}
//	}
//}

// simple hiding string by replacing all character with a specific character *
//string hideString(string tohide) {
//	string hidden = "";
//	for (int i = 0; i < tohide.size(); i++) {
//		hidden += '*';
//	}
//	return hidden;
//}
//
//// simple hiding string by replacing all character with a specific character *
//string hideString(int tohideLenght) {
//	string hidden = "";
//	for (int i = 0; i < tohideLenght; i++) {
//		hidden += '*';
//	}
//	return hidden;
//}



// Sale report

void SaleReportMenu(Admin auser,Customer cuser, Payment pay, Package pack) {

	string start, endDate;

	vector<int> packageID;

	bool sortByDate = true, ascending = true;

	ArrowMenu saleM;
	saleM.addOption("Start");
	saleM.addOption("End");
	saleM.addOption("Package");
	saleM.addOption("Sort By");
	saleM.setValue(3, "Date");
	saleM.addOption("Order");
	saleM.setValue(4, "Ascending");
	saleM.addOption("Generate");

	vector<Sale> result; // vector to store the result

	// we declare it like this so that the index matches their id in the database
	string package_names[] = { "Basic Grooming","Fleas Treatment","Fungus Treatment","Full Body Tream" };

	//declare outside so that we don't unnecesarily declare new variable in each loop iteration
	string selectedpackage_name;
	int tmpSelectedpackageID;

	vector<int>::iterator iterator; //iterator is declare using what we are iterating, in this case it is vector of integer
	int option = 0;

	while (1)
	{

		selectedpackage_name = "";
		if (packageID.empty()) {
			selectedpackage_name = "NONE";
		}
		else {
			for (int i = 0; i < packageID.size(); i++) {
				selectedpackage_name += package_names[packageID[i]] + ", ";
			}
		}
		saleM.setValue(2, selectedpackage_name);



		// report display
		stringstream ss;
		// construct our report header
		ss << endl << "\t\t\t----------------------- SALES REPORT -----------------------\n" << endl << "\t\t\t\t" << "|" << setw(20) << "Date Time" << "|";
		if (!packageID.empty()) {
			// if category id not empty we add category column
			ss << "\t\t\t\t" <<  setw(20) << "Package" << "|";
		}
		ss << setw(20) << "Sale" << "|";

		double totalSale = 0;
		// repeat same structure for content of the report
		for (int i = 0; i < result.size(); i++) {
			ss << endl << "\t\t\t\t" << "|" << setw(20) << result[i].date.substr(0, 7) << "|";
			if (!packageID.empty()) {
				// if category id not empty we add category column
				ss << setw(20) << result[i].package_name << "|";
			}
			ss << setw(20) << result[i].value << "|";
			totalSale += result[i].value;

		}

		ss << endl << "\t\t\t\t" << "|" << setw(20) << "Total Sale" << "|";
		if (!packageID.empty()) {
			// if category id not empty we add category column
			ss << setw(20) << "" << " ";
		}
		ss << setw(20) << totalSale << "|";

		ss << endl << "\n\t\t\t----------------------- END OF REPORT -----------------------" << endl;
		saleM.header = ss.str();

		option = saleM.prompt(option);
		switch (option)
		{
		case -1:
			return;
			break;
		case 0:
			cout << "Inser start date (yyyy-mm-dd): ";
			cin >> start;
			saleM.setValue(0, start);
			break;
		case 1:
			cout << "Inser end date (yyyy-mm-dd): ";
			cin >> endDate;
			saleM.setValue(1, endDate);
			break;
		case 2: //toggle category
			tmpSelectedpackageID = packageSelection();

			//find the selcted category id inside our categoryIds vector
			iterator = find(packageID.begin(), packageID.end(), tmpSelectedpackageID);

			if (iterator == packageID.end()) {//if the iterator reaches the end means not found
				packageID.push_back(tmpSelectedpackageID);
			}
			else {
				packageID.erase(iterator); //if it exist erase it
			}

			break;
		case 3:// sort by
			sortByDate = !sortByDate;
			if (sortByDate)
				saleM.setValue(3, "Date");
			else
				saleM.setValue(3, "Price");
			break;
		case 4:
			ascending = !ascending;
			if (ascending)
				saleM.setValue(4, "Ascending");
			else
				saleM.setValue(4, "Descending");
			break;
		case 5:
			result.clear();
			result = Sale::salesReport(start, endDate, packageID, sortByDate, ascending);
			break;
		}

	}
}

int packageSelection() {
	Menu packageMenu;
	packageMenu.header = " TOGGLE PACKAGE ";
	packageMenu.addOption(" Basic Grooming ");
	packageMenu.addOption(" Fleas Treatment ");
	packageMenu.addOption(" Fungus Treatment ");
	packageMenu.addOption(" Full Body Treatment ");

	while (1)
	{
		return packageMenu.prompt();
	}

}

bool validateDate(const std::string& date) {
	// Define a regex pattern for YYYY-MM-DD format
	std::regex dateRegex(R"(\d{4}-\d{2}-\d{2})");

	// Check if the date matches the format
	return std::regex_match(date, dateRegex);
}