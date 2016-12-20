#ifndef LIST_SIDE_FUNCTIONS_H
#define LIST_SIDE_FUNCTIONS_H
#include "list.h"
#include "side_functions.h"
#include <iostream>
#include <string>
using namespace std;
listOD::listEL* listOD::checkLogin(string loginCheck){
	listEL *pointhelp = head->next;
	do{
		if(pointhelp->value.login == loginCheck) return pointhelp;

		pointhelp = pointhelp->next;
	}while(pointhelp);
	cout << "Login incorrect!\n";
	return NULL;
}

int listOD::checkPassword(string password, listEL *pointer){
	if(pointer)
		if(pointer->value.password == password) return 1;
	return 0;
}

bool listOD::loginFun(){
	string login, password;
	listEL *pointer;
	do{
		cout << "\nType in your login: ";
		cin >> login;
	}while(!(pointer = checkLogin(login)));
	cout << "Type in your password: ";
	HideStdinKeystrokes();
	cin >> password;
	ShowStdinKeystrokes();
	if(!checkPassword(password, pointer)){
		cout << "Incorrect password!\n";
		return true;
	}
	else{
		cout << "\nAccess granted. Welcome " << pointer->value.first_name << "." << endl;
		return false;
	}
}
#endif