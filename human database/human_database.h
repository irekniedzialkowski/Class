#ifndef HUMAN_DATABASE
#define HUMAN_DATABASE
#include "side_functions.h"
#include "date.h"
#include <iostream>
#include <fstream>

using std::string;

class Person{
	string first_name;
	string last_name;
	string login;
	string password;
	char sex;
	date birth;
public:
	Person();
	friend ostream& operator <<(ostream&, Person&);
	friend fstream& operator <<(fstream&, Person&);
};

Person::Person(){
	first_name = getFirstName();
	last_name = getLastName();
	sex = getSex();
	login = getLogin();
	password = getPassword();
	birth = getDate();
}

ostream& operator<<(ostream &out, Person &human){
	out << "\nFirst Name: " << human.first_name << endl <<
	"Last Name: " << human.last_name << endl <<
	"Sex: " << human.sex << endl <<
	"Login: " << human.login << endl <<
	"Date: " << human.birth.day << '.' << human.birth.month << '.' << human.birth.year << endl;
	return out;
}

fstream& operator<<(fstream &out, Person &human){
	out << "\nFirst Name: " << human.first_name << endl <<
	"Last Name: " << human.last_name << endl <<
	"Sex: " << human.sex << endl <<
	"Login: " << human.login << endl <<
	"Date: " << human.birth.day << '.' << human.birth.month << '.' << human.birth.year << endl;
	return out;
}

#endif