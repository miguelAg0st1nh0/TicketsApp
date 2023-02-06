

#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>

using namespace std;

class show
{
//acessible anywhere in the program, from any class
public:
	show();
	~show();
	void selectShow(string &showName, string &showDate);
	string selectTime();
	bool canLeaveMenu = false;
//acessible from objects that derive from this class

protected:
	string showName;
	string showDate;
	string showTime;
	int showChoice;
};

//constructor
show::show()
{
	showName = "";
	showDate = "";
	showTime = "";
	
}

//deconstructor
show::~show()
{

}

void show::selectShow(string &showName, string &showDate)
{
	char terminator;
	int showChoice = 0;
	cout << "--------------------------SHOWS MENU------------------------------" << endl;
	cout << "1: Les Miserables!--------------------------------------(18/03/23)" << endl;
	cout << "2: Avatar 2 --------------------------------------------(21/03/23)" << endl;
	cout << "3: Star Wars !------------------------------------------(26/03/23)" << endl;
	cout << "4: Go Back to Main Menu" << endl;
	cout << "Enter show choice: ";
	cin >> showChoice;
	cin.get(terminator);


	switch (showChoice)
	{
	case 1:
		showName = "Les Miserables";
		showDate = "18/03/23";
		canLeaveMenu = false;
		break;
	case 2:
		showName = "Avatar 2";
		showDate = "21/03/23";
		canLeaveMenu = false;
		break;
	case 3:
		showName = "Star Wars";
		showDate = "26/03/23";
		canLeaveMenu = false;
		break;
	case 4:
		canLeaveMenu = true;
		break;
	default:
		break;
	}
	
	this->showName = showName;
	this->showDate = showDate;
	if (!canLeaveMenu)
	{
		//Deals with the show time input
		char charInput;
		cout << "Select a Time (1pm/4pm/7pm): " << endl;
		cin.get(charInput);
		cin.get(terminator);
		while (charInput != '1' && charInput != '4' && charInput != '7')
		{
			cout << "Please select one of the following hours: 1pm/4pm/7pm!";
			cin.get(charInput);
			cin.get(terminator);
		}
		showTime = charInput;
	}

}

string show::selectTime()
{
	return showTime + "pm";
}
