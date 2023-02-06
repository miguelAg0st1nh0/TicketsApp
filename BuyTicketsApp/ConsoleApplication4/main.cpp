

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "customer.h"
#include "show.h"
#include "showSeats.h"

using namespace std;

//Function declarations
void displayMainMenu();
void menuTransitioningHandler();


//Global variables declaration, this is to be accessed in functions out of main scope. Refactoring code.
string a, b;
int menuChoice;
char terminator;
//different objects that inherit from the same class, A.K.A polymorphism
customer cust;
customer otherCust;
show showObject;
showSeat showSeatObject;

int main()
{
    //Program always starts with login.
    cust.initialiseLogin();
    //After a valid login, display Main Menu
    displayMainMenu();
    //Handles menu switching
    menuTransitioningHandler();
    showSeatObject.initialiseFloorPlan();
    showSeatObject.getNumOfSeats();
    showSeatObject.getSeatSelection();
    
    return 0;
}

//Functions prototyping
void displayMainMenu()
{
    
    cout << "-------------------------Main Menu-----------------------" << endl;
    cout << "1.Buy Tickets for upcoming shows! " << endl;
    cout << "2.Edit Profile Information! " << endl;
    cout << "3.Logout!" << endl;
    cout << "Enter a menu choice: ";
    cin >> menuChoice;
    cin.get(terminator);

    while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3)
    {
        cout << "Please enter a valid input, choices numbers range from 1 to 3! " << endl;
        cout << "Enter a menu choice: ";
        cin >> menuChoice;
        cin.get(terminator);
    }
}
 
void menuTransitioningHandler()
{

    /*
    * MenuChoices
    * 0 = MainMenu
    * 1 = BuyTickets
    * 2 = CustomerProfileMenu
    * 3 = Exit Application
    * 
    */
    
    do
    {
        if (menuChoice == 0)
        {
            //Everytime a new menu is entered, system clears screen, displaying only relevant information
            system("CLS");
            displayMainMenu();
        }
        else if (menuChoice == 1)
        {
            system("CLS");
            string answer = "";
            while(answer != "yes" && menuChoice != 0)
            {
                //The menu that displays shows also display an option to go back to main menu
                showObject.selectShow(a, b);
                if (showObject.canLeaveMenu) menuChoice = 0;
                else
                {
                    showObject.selectTime();
                    cout << "You selected " << a << " which will be performed on " << b << " at " << showObject.selectTime() << endl;
                    cout << "Are you Happy with your choice? (Yes/No)" << endl;
                    getline(cin, answer);
                }
            }
            //If user finished selecting show, show time and date, leave the whole loop, 
            //else, he goes back to main menu, might want to edit profile information before proceeding
            if (menuChoice != 0) break;
            
        }
        else if (menuChoice == 2)
        {
            system("CLS");
            cust.customerProfileMenu();
            if (cust.canLeaveMenu) menuChoice = 0;
        }
        else if (menuChoice == 3)
        {
            exit(3);
        }
    } while (menuChoice != 3);
}

