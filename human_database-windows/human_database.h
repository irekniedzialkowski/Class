#ifndef HUMAN_DATABASE
#define HUMAN_DATABASE
#include <iostream>
using namespace std;

class date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
	public:
	friend istream& operator>>(istream&, date&);
	friend ostream& operator<<(ostream&, date&);
};

class Person
{
	string first_name;
	string last_name;
	string login;
	string password;
	char sex;
	date birth;
	public:
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, Person&);
};
#endif
