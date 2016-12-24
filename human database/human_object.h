#ifndef HUMAN_OBJECT
#define HUMAN_OBJECT
#include <iostream>
#include <string>
using namespace std;

class Person{
	string first_name;
	string last_name;
	char sex;
	string login;
	string password;
	class date{
public:
	unsigned short day;
	unsigned short month;
	unsigned short year;
}birth;
public:
	friend ostream& operator <<(ostream&, Person&);
	friend istream& operator >>(istream&, Person&);
	friend void getFirstName(istream&, Person&);
	friend void getLastName(istream&, Person&);
	friend void getSex(istream&, Person&);
	friend void getLogin(istream&, Person&);
	friend void getPassword(istream&, Person&);
	friend void getDate(istream&, Person&);
	friend class listOD;
	string& getLogin();
};

string& Person::getLogin(){
	return login;
}
#endif