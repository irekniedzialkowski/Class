#ifndef HUMAN_OPERATOR
#define HUMAN_OPERATOR
#include <iostream>
#include <fstream>
#include "side_functions.h"
#include "human_object.h"
using namespace std;

ostream& operator<<(ostream &out, Person &human){
	out << human.first_name << endl <<
	human.last_name << endl <<
	human.sex << endl <<
	human.login << endl <<
	human.password << endl <<
	human.birth.day << endl << human.birth.month << endl << human.birth.year << endl;
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