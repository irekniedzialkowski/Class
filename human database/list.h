#ifndef LIST_H
#define LIST_H
#include <string>
#include <iostream>
#include "human_operator.h"
#include "human_object.h"
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
	~listOD();
	listEL* append(Person&);
	listEL* search(string&);
	class spectralPointer{

	};
	friend ostream& operator<<(ostream&, listOD&);
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

listOD::listEL* listOD::append(Person &pattern){
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

#endif