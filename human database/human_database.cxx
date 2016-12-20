#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "human_operator.h"
#include "human_object.h"
#include "list.h"
#include "list_side_functions.h"

using namespace std;

main(){
	bool login;
	Person A;
	char check = 'N';
	listOD database;
	/*fstream myFile;
	string directory;
	cout << "\nPlease type in the directory of a file to save output: ";
	cin >> directory;*/
	do{
		cin >> A;
		/*if(myFile.is_open()) myFile << A;
		myFile.close();
		myFile.open(directory,ios::in);*/
		database.append(A);
		do{
			cout << "Register another person? (Y/N): ";
			cin >> check;
			check = toupper(check);
		}while(check != 'Y' && check != 'N');
	}while(check == 'Y');
	//myFile.close();
	do{
		login = database.loginFun();
	}while(login);
}