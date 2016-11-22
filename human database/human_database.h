#ifndef HUMAN_DATABASE
#define HUMAN_DATABASE
#include "side_functions.h"
#include "date.h"

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
};

Person::Person(){
	first_name = getFirstName();
	last_name = getLastName();
	sex = getSex();
	login = getLogin();
	password = getPassword();
	birth = getDate();
}

#endif