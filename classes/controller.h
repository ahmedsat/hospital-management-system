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
  void addDoctor();
  // void removeDoctor();
  // void updateDoctor();
  // void searchDoctor();
  // void printDoctor();
  // void printAllDoctors();
  // void addPatient();
  // void removePatient();
  // void updatePatient();
  // void searchPatient();
  // void printPatient();
  // void printAllPatients();
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
      addDoctor();
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

void Controller::addDoctor()
{
  clearScreen();
  Doctor d;
  int id;
  string name, specialization, experience, phone, email, address;
  do
  {
    cout << message << endl;
    cout << "Enter doctor id: ";
    cin >> id;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (id <= 0)
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Id must be an integer greater than 0";
      continue;
    }
    if (d.isDoctorExist(id))
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Doctor id already in use";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor name: ";
    cin >> name;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (name.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Name cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor specialization: ";
    cin >> specialization;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (specialization.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Specialization cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor experience: ";
    cin >> experience;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (experience.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Experience cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor phone: ";
    cin >> phone;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (phone.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Phone cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor email: ";
    cin >> email;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (email.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Email cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  do
  {
    cout << message << endl;
    cout << "Enter doctor address: ";
    cin >> address;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Invalid input, please try again";
      continue;
    }
    if (address.empty())
    {
      cin.clear();
      cin.ignore(10000, '\n');
      clearScreen();
      message = "Address cannot be empty";
      continue;
    }
    cin.clear();
    message = "";
    break;
  } while (true);

  d.setId(id);
  d.setName(name);
  d.setSpecialization(specialization);
  d.setExperience(experience);
  d.setPhone(phone);
  d.setEmail(email);
  d.setAddress(address);
  d.addDoctor(d);
  clearScreen();
  message = "Doctor added successfully";
}