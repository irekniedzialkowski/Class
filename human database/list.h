#ifndef LIST_H
#define LIST_H
#include <string>
#include <iostream>
#include <fstream>
#include "human_operator.h"
#include "human_object.h"
#include "side_functions.h"
using namespace std;
class listOD{
	class listEL{
	public:
		Person value;
		listEL *next;
		listEL();
	};
	listEL *head;
public:
	listOD();
	listEL* checkLogin(string);
	int checkPassword(string, listEL*);
	bool loginFun();
	~listOD();
	listEL* append(Person&);
	listEL* search(string&);
	fstream& load(fstream&);
	friend ostream& operator<<(ostream&, listOD&);
	friend istream& operator>>(istream&, listOD&);
	friend ostream& operator>>(fstream&, listOD&);
};

listOD::listEL::listEL(){
	next = NULL;
}

listOD::listOD(){
	head = new listEL;
}

listOD::~listOD(){
	listEL *help;
	if(head->next){
		while(head->next->next){
			help = head->next->next;
			delete head->next;
			head->next = help;
		}
		delete head->next;
	}
	delete head;
}

listOD::listEL* listOD::append(Person &pattern){  //for indirect input (with Person object ready)
	listEL *newel = new listEL;
	newel->value = pattern;
	newel->next = head->next;
	head->next = newel;
	return newel;
}

ostream& operator<<(ostream &out, listOD &element){ //output - whole list
	listOD::listEL *help = element.head->next;
	while(help){
		out << help->value;
		help = help->next;
	}
	return out;
}

fstream& listOD::load(fstream &file){ //getting data from non-empty file
	listEL *help;
	while(!file.eof()){
		getline(file, help->value.first_name);
		getline(file, help->value.last_name);
		file >> help->value.sex;
		getline(file, help->value.login);
		getline(file, help->value.password);
		file >> help->value.birth.day;
		file >> help->value.birth.month;
		file >> help->value.birth.year;
		help->next = head->next;
		head->next = help;
		help = new listEL;
	}
	return file;
}

istream& operator>>(istream &in, listOD &element){  //for direct input (through the console)
	listOD::listEL *newel = new listOD::listEL;
	getFirstName(in, newel->value);
	getLastName(in, newel->value);
	getSex(in, newel->value);
	getLogin(in, newel->value);
	getPassword(in, newel->value);
	getDate(in, newel->value);
	newel->next = element.head->next;
	element.head->next = newel;
	return in;
}

#endif