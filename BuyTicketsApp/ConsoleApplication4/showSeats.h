#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

class showSeat
{

public:
	showSeat();
	~showSeat();
	void initialiseFloorPlan();
	int getNumOfSeats();
	double getSeatSelection();

private:
	void displayFloorPlan(int r, int c);
	void calculatePrice(double& price);

protected:
	char floorPlan[7][6];
	int numOfSeats;
	int rNumber;
	double price;

};

showSeat::showSeat()
{
	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			floorPlan[r][c] = '0';
		}	
	}

	numOfSeats = 0;
	rNumber = 0;
	price = 0.0;
		
}

showSeat::~showSeat()
{

}

void showSeat::initialiseFloorPlan()
{
	cout << "-------------------------------Floor Map----------------------------" << endl; 
	cout << "--------------------------------_______------------------------------" << endl;
	cout << "--------------------------------|STAGE|-----------------------------" << endl;
	cout << "-----------------------------------------------------------------" << endl;

	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			
			floorPlan[r][c] = 'A';
			cout << '\t' << floorPlan[r][c];
			
		}
		cout << '\n';
		
	}
	cout << "--------------------------------------------------------------------" << endl;

}

int showSeat::getNumOfSeats()
{
	while (numOfSeats > 5 || numOfSeats <=0)
	{
		cout << "How many seats would you like to purchase? (Max. 5 seats) " << endl;
		cin >> numOfSeats;
	}
	return numOfSeats;
}

double showSeat::getSeatSelection()
{
	//foreach number of seats bought, ask for a row and for a column.
	int row = 0;
	int column = 0;

	for (int i = 1; i <= numOfSeats; i++)
	{
		cout << "Pick a row: (0-7) " << endl;
		cin >> row;
		cout << "Pick a column: (0-6) " << endl;
		cin >> column;
		//if seat is available and not being held, allow it to be taken.
		if (floorPlan[row][column] == 'A' && floorPlan[row][column] != 'H')
		{
			floorPlan[row][column] = 'T';
		}
	}
	displayFloorPlan(row, column);
	return 0;
}

void showSeat::displayFloorPlan(int r, int c)
{
	cout << "-------------------------------Floor Map----------------------------" << endl;
	cout << "--------------------------------_______------------------------------" << endl;
	cout << "--------------------------------|STAGE|-----------------------------" << endl;
	cout << "-----------------------------------------------------------------" << endl;

	for (int r = 0; r < 7; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			cout << '\t' << floorPlan[r][c];
		}
		cout << '\n';
	}
	cout << "--------------------------------------------------------------------" << endl;
}

void showSeat::calculatePrice(double& price)
{
	//check later

}

