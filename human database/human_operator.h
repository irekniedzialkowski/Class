#ifndef HUMAN_OPERATOR
#define HUMAN_OPERATOR
#include "side_functions.h"
#include "human_object.h"
#include <iostream>
#include <fstream>

using namespace std;

ostream& operator<<(ostream &out, Person &human){
	out << "First Name: " << human.first_name << endl <<
	"Last Name: " << human.last_name << endl <<
	"Sex: " << human.sex << endl <<
	"Login: " << human.login << endl <<
	"Password: PROTECTED" << endl <<
	"Date: " << human.birth.day << '.' << human.birth.month << '.' << human.birth.year << endl;
	return out;
}

istream& operator>>(istream &in, Person &human){
	getFirstName(in, human);
	getLastName(in, human);
	getSex(in, human);
	getLogin(in, human);
	getPassword(in, human);
	getDate(in, human);
	return in;
}

#endif