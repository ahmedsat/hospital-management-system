#include <iostream>
#include <string>
#include "doctor.h"
#include "../helperFunctions.h"
using namespace std;

// controller class for user input and output
class Controller
{
  string message;

public:
  Controller();
  ~Controller();
  string getMessage();
  void setMessage(string);
  void mainMenu();
  void doctorsMenu();
  void patientsMenu();
};

Controller::Controller()
{
}

Controller::~Controller()
{
  clearScreen();
  cout << message << endl;
}

string Controller::getMessage()
{
  return message;
}

void Controller::setMessage(string m)
{
  message = m;
}

void Controller::mainMenu()
{
  int input;
  do
  {
    clearScreen();
    // chick if message is empty
    if (message.empty())
    {
      cout << "Welcome to the Hospital Management System" << endl;
      cout << "main menu" << endl;
      cout << "Please select an option" << endl;
    }
    else
    {
      cout << message << endl;
    }
    cout << "1. Doctors" << endl;
    cout << "2. Patients" << endl;
    cout << "0. Exit" << endl;
    message = "";
    // get user input
    cout << "Enter your selection: ";
    cin >> input;

    switch (input)
    {
    case 1:
      doctorsMenu();
      break;
    case 2:
      patientsMenu();
      break;
    case 0:
      message = "Goodbye";
      break;
    default:
      message = "Invalid selection";
    }
  } while (input != 0);
}

void Controller::doctorsMenu()
{
  int input;
  do
  {
    clearScreen();
    // chick if message is empty
    if (message.empty())
    {
      cout << "Welcome to the Hospital Management System" << endl;
      cout << "doctors menu" << endl;
      cout << "Please select an option" << endl;
    }
    else
    {
      cout << message << endl;
    }
    cout << "1. Add a doctor" << endl;
    cout << "2. Remove a doctor" << endl;
    cout << "3. List all doctors" << endl;
    cout << "4. Search for a doctor" << endl;
    cout << "5. Update a doctor" << endl;
    cout << "0. Return to main menu" << endl;

    message = "";

    // get user input
    cout << "Enter your selection: ";
    cin >> input;

    // set message
    switch (input)
    {
    case 1:
      message = "You have selected to add a doctor";
      break;
    case 2:
      message = "You have selected to remove a doctor";
      break;
    case 3:
      message = "You have selected to list all doctors";
      break;
    case 4:
      message = "You have selected to search for a doctor";
      break;
    case 5:
      message = "You have selected to update a doctor";
      break;
    case 0:
      message = "You have selected to return to the main menu";
      break;
    default:
      message = "Invalid selection";
    }
  } while (input != 0);
}

void Controller::patientsMenu()
{
  int input;
  do
  {
    clearScreen();
    // chick if message is empty
    if (message.empty())
    {
      cout << "Welcome to the Hospital Management System" << endl;
      cout << "patients menu" << endl;
      cout << "Please select an option" << endl;
    }
    else
    {
      cout << message << endl;
    }
    cout << "1. Add a patient" << endl;
    cout << "2. Remove a patient" << endl;
    cout << "3. List all patients" << endl;
    cout << "4. Search for a patient" << endl;
    cout << "5. Update a patient" << endl;
    cout << "0. Return to main menu" << endl;

    message = "";

    // get user input
    cout << "Enter your selection: ";
    cin >> input;

    // set message
    switch (input)
    {
    case 1:
      message = "You have selected to add a patient";
      break;
    case 2:
      message = "You have selected to remove a patient";
      break;
    case 3:
      message = "You have selected to list all patients";
      break;
    case 4:
      message = "You have selected to search for a patient";
      break;
    case 5:
      message = "You have selected to update a patient";
      break;
    case 0:
      message = "You have selected to return to the main menu";
      break;
    default:
      message = "Invalid selection";
    }
  } while (input != 0);
}
