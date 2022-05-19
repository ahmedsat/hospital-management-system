#include <iostream>
#include <string>
using namespace std;

string DoctorPath = "/home/ahmedsat/c++/hospital/Doctors.txt";

class Doctor
{
private:
  int id;
  string name;
  string specialization;
  string experience;
  string phone;
  string email;
  string address;

public:
  Doctor();
  Doctor(int, string, string, string, string, string, string);
  ~Doctor();
  int getId();
  string getName();
  string getSpecialization();
  string getExperience();
  string getPhone();
  string getEmail();
  string getAddress();
  void setId(int);
  void setName(string);
  void setSpecialization(string);
  void setExperience(string);
  void setPhone(string);
  void setEmail(string);
  void setAddress(string);
  Doctor addDoctor(Doctor);
  Doctor removeDoctor(int);
  Doctor updateDoctor(int, Doctor);
  Doctor searchDoctorById(int);
  Doctor *getAllDoctors();
  void printDoctor(Doctor);
  void printDoctor(Doctor *);
};

Doctor::Doctor()
{
  id = 0;
  name = "";
  specialization = "";
  experience = "";
  phone = "";
  email = "";
  address = "";
}

Doctor::Doctor(int id, string name, string specialization, string experience, string phone, string email, string address)
{
  this->id = id;
  this->name = name;
  this->specialization = specialization;
  this->experience = experience;
  this->phone = phone;
  this->email = email;
  this->address = address;
}

Doctor::~Doctor()
{
}

int Doctor::getId()
{
  return id;
}

string Doctor::getName()
{
  return name;
}

string Doctor::getSpecialization()
{
  return specialization;
}

string Doctor::getExperience()
{
  return experience;
}

string Doctor::getPhone()
{
  return phone;
}

string Doctor::getEmail()
{
  return email;
}

string Doctor::getAddress()
{
  return address;
}

void Doctor::setId(int id)
{
  this->id = id;
}

void Doctor::setName(string name)
{
  this->name = name;
}

void Doctor::setSpecialization(string specialization)
{
  this->specialization = specialization;
}

void Doctor::setExperience(string experience)
{
  this->experience = experience;
}

void Doctor::setPhone(string phone)
{
  this->phone = phone;
}

void Doctor::setEmail(string email)
{
  this->email = email;
}

void Doctor::setAddress(string address)
{
  this->address = address;
}
