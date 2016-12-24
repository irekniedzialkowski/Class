#ifndef LIST_OBJECT
#define LIST_OBJECT
#include <fstream>
#include <iostream>
#include <string>
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
	listEL* checkLogin(string);
	int checkPassword(string, listEL*);
	bool loginFun();
	~listOD();
	listEL* append(Person&);
	listEL* append();
	listEL* search(string&);
	fstream& load(fstream&, string&);
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

fstream& listOD::load(fstream &file, string &dir){ //getting data from non-empty file
	string str;
	listEL *help = new listEL;
	file.open(dir, ios::in);
	while(!file.eof()){
		getline(file, help->value.first_name);
		getline(file, help->value.last_name);
		file.get(help->value.sex);
		file.get();
		getline(file, help->value.login);
		getline(file, help->value.password);
		getline(file, str);
		help->value.birth.day = stoi(str,nullptr,10);
		getline(file, str);
		help->value.birth.month = stoi(str,nullptr,10);
		getline(file, str);
		help->value.birth.year = stoi(str,nullptr,10);
		help->next = head->next;
		head->next = help;
		help = new listEL;
	}
	file.close();
	return file;
}

/*ostream& operator<<(ostream &out, listOD &element){ //output - whole list
	listOD::listEL *help = element.head->next;
	while(help){
		out << help->value;
		help = help->next;
	}
	return out;
}*/
#endif