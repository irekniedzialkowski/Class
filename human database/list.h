#ifndef LIST_H
#define LIST_H
#include <string>
#include <iostream>
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
	void loginFun();
	~listOD();
	listEL* append(Person&);
	listEL* search(string&);
	friend ostream& operator<<(ostream&, listOD&);
	friend istream& operator>>(istream&, listOD&);
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

listOD::listEL* listOD::append(Person &pattern){  //for indirect input (though created file)
	listEL *newel = new listEL;
	newel->value = pattern;
	newel->next = head->next;
	head->next = newel;
	return newel;
}

ostream& operator<<(ostream &out, listOD &element){
	listOD::listEL *help = element.head->next;
	while(help){
		out << help->value;
		help = help->next;
	}
	return out;
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