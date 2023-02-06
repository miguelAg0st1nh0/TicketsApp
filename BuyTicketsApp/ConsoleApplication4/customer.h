#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>

using namespace std;

class customer
{
public:

	customer();
	void customerProfileMenu();
	void initialiseLogin();
	void getCustomerProfile(string &customerName, string &customerAddress);
	void getPaymentDetails();
	bool canLeaveMenu = false;
protected:
	string customerName, customerPassword, customerAddress;
private:
	
};

customer::customer()
{
	customerName = "";
	customerPassword = "";
	customerAddress = "";
	void customerProfileMenu();
}

void customer::customerProfileMenu()
{
	char terminator;
	int choice = 0;
	cout << "--------------------------PROFILE_MENU------------------------------" << endl;
	cout << "Press 1: to edit profile!----------------------------------" << endl;
	cout << "Press 2: to edit Payment Details!--------------------------" << endl;
	cout << "Press 3: to leave profile menu!----------------------------" << endl;
	cout << "Enter Menu choice: ";
	cin >> choice;
	cin.get(terminator);

	switch (choice)
	{	
	case 1:
		cout << "CUSTOMER PROFILE MENU " << endl;
		getCustomerProfile(customerName, customerAddress);
		break;
	case 2:
		cout << "PAYMENT DETAILS MENU" << endl;
		getPaymentDetails();
		break;
	case 3:
		canLeaveMenu = true;
		break;
	default:
		break;
	}
}
//Program always starts with login in the class constructor

void customer::initialiseLogin()
{
	string username = "";
	string password = "";

	cout << "------------------------------LOGIN--------------------------------" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Welcome to the Bucks Centre for the performing arts ticket purschasing!" << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Enter Username: ";
	getline(cin, username);

	while (username.length() > 10)
	{
		cout << "Your name should be less than 10 characters long!" << endl;
		cout << "Enter Username: ";
		getline(cin, username);
	}
	cout << "Enter password: ";
	getline(cin, password);

	while (password.length() > 10)
	{
		cout << "Your password should be less than 10 characters long!" << endl;
		cout << "Enter Password: ";
		getline(cin, password);
	}
	system("CLS");

	cout << "--------Welcome back " << username << "!-----------" << endl;
	cout << "---------------------------------------------------" << endl;
}

void customer::getCustomerProfile(string &customerName, string &customerAddress)
{
	string input = "";

	do
	{
		cout << "------Edit your Profile Information------" << endl;
		cout << "Enter your name: ";
		getline(cin, customerName);
		cout << "Enter your Address: ";
		getline(cin, customerAddress);

		cout << "----Does the information look right?--------" << endl;
		cout << "Name: " << customerName << endl;
		cout << "Address: " << customerAddress << endl;
		cout << "Enter Yes(yes) to proceed or No(no) to change details!";
		getline(cin, input);
		if (input == "Yes" || input == "YES")
		{
			input = "yes";
		}

	} while (input != "yes");
	//goes back to profile menu after edditing information
	system("CLS");
	customerProfileMenu();

}

void customer::getPaymentDetails()
{
	string cardNumber = "";
	string cvv = "";
	string input = "";

	cout << "------Edit your Payment Information------" << endl;

	while (cardNumber.length() != 16)
	{
		cout << "Card Number must have 16 digits!" << endl;
		cout << "Enter Credit Card number: ";
		getline(cin, cardNumber);
	}

	while (cvv.length() != 3)
	{
		cout << "Card Verification Value must have 3 digits!" << endl;
		cout << "Enter CVV number: ";
		getline(cin, cvv);
	}

	do
	{
		cout << "----Does the information look right?--------" << endl;
		cout << "Card Number: " << cardNumber << endl;
		cout << "CVV: " << cvv << endl;
		cout << "Enter Yes(yes) to proceed or No(no) to change details!";
		getline(cin, input);

		if (input == "Yes" || input == "YES")
		{
			input = "yes";
			
		}

	} while (input != "yes");
	//Goes back to edit profile
	system("CLS");
	customerProfileMenu();
	
}




