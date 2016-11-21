#ifndef HUMAN_DATABASE
#define HUMAN_DATABASE
#include "side_functions.h"

struct date{
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

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
	this.first_name = getFirstName();
	this.last_name = getLastName();
	this.sex = getSex();
	this.login = getLogin();
	this.password = getPassword();
}
#endif