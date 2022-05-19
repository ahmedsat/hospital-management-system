#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
  vector<Doctor> getAllDoctors();
  void printDoctor(Doctor);
  void printDoctor(vector<Doctor>);
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

Doctor Doctor::addDoctor(Doctor d)
{
  ofstream file;
  file.open(DoctorPath, ios::app);
  if (file.is_open())
  {
    file
        << d.getId()
        << "|"
        << d.getName()
        << "|"
        << d.getSpecialization()
        << "|"
        << d.getExperience()
        << "|"
        << d.getPhone()
        << "|"
        << d.getEmail()
        << "|"
        << d.getAddress()
        << endl;
    file.close();
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  return d;
}

Doctor Doctor::removeDoctor(int id)
{
  ifstream file;
  file.open(DoctorPath);
  if (file.is_open())
  {
    ofstream temp;
    temp.open("temp.txt");
    if (temp.is_open())
    {
      string line;
      while (getline(file, line))
      {
        string idStr = to_string(id);
        if (line.find(idStr) == string::npos)
        {
          temp << line << endl;
        }
      }
      temp.close();
      file.close();
      remove("Doctors.txt");
      rename("temp.txt", "Doctors.txt");
    }
    else
    {
      cout << "Unable to open temp file" << endl;
    }
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  return Doctor();
}

Doctor Doctor::updateDoctor(int id, Doctor d)
{
  ifstream file;
  file.open(DoctorPath);
  if (file.is_open())
  {
    ofstream temp;
    temp.open("temp.txt");
    if (temp.is_open())
    {
      string line;
      while (getline(file, line))
      {
        string idStr = to_string(id);
        if (line.find(idStr) == string::npos)
        {
          temp << line << endl;
        }
        else
        {
          temp << d.getId()
               << "|"
               << d.getName()
               << "|"
               << d.getSpecialization()
               << "|"
               << d.getExperience()
               << "|"
               << d.getPhone()
               << "|"
               << d.getEmail()
               << "|"
               << d.getAddress()
               << endl;
        }
      }
      temp.close();
      file.close();
      remove("Doctors.txt");
      rename("temp.txt", "Doctors.txt");
    }
    else
    {
      cout << "Unable to open temp file" << endl;
    }
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  return Doctor();
}

Doctor Doctor::searchDoctorById(int id)
{
  ifstream file;
  file.open(DoctorPath);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      string idStr = to_string(id);
      if (line.find(idStr) != string::npos)
      {
        string id, name, specialization, experience, phone, email, address;
        int i = 0;
        while (line[i] != '|')
        {
          id += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          name += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          specialization += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          experience += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          phone += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          email += line[i];
          i++;
        }
        i++;
        while (line[i] != '|')
        {
          address += line[i];
          i++;
        }
        Doctor d(stoi(id), name, specialization, experience, phone, email, address);
        return d;
      }
    }
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  return Doctor();
}

vector<Doctor> Doctor::getAllDoctors()
{
  vector<Doctor> doctors;
  ifstream file;
  file.open(DoctorPath);
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      string id, name, specialization, experience, phone, email, address;
      int i = 0;
      while (line[i] != '|')
      {
        id += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        name += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        specialization += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        experience += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        phone += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        email += line[i];
        i++;
      }
      i++;
      while (line[i] != '|')
      {
        address += line[i];
        i++;
      }
      Doctor d(stoi(id), name, specialization, experience, phone, email, address);
      doctors.push_back(d);
    }
  }
  else
  {
    cout << "Unable to open file" << endl;
  }
  return doctors;
}

void Doctor::printDoctor(Doctor d)
{
  cout << "ID: " << d.getId() << endl;
  cout << "Name: " << d.getName() << endl;
  cout << "Specialization: " << d.getSpecialization() << endl;
  cout << "Experience: " << d.getExperience() << endl;
  cout << "Phone: " << d.getPhone() << endl;
  cout << "Email: " << d.getEmail() << endl;
  cout << "Address: " << d.getAddress() << endl;
}

void Doctor::printDoctor(vector<Doctor> doctors)
{
  for (int i = 0; i < doctors.size(); i++)
  {
    cout << "ID: " << doctors[i].getId() << endl;
    cout << "Name: " << doctors[i].getName() << endl;
    cout << "Specialization: " << doctors[i].getSpecialization() << endl;
    cout << "Experience: " << doctors[i].getExperience() << endl;
    cout << "Phone: " << doctors[i].getPhone() << endl;
    cout << "Email: " << doctors[i].getEmail() << endl;
    cout << "Address: " << doctors[i].getAddress() << endl;
  }
}