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
	char check = 'N', ch;
	listOD database;
	fstream myFile;
	string directory;
	cout << "\nPlease type in the directory of your file (to save output or/and to load data from it): ";
	cin >> directory;
	myFile.open(directory, ios::out);
	myFile.close();
	myFile.open(directory, ios::out | ios::in);
	if(myFile.is_open()){
		myFile.get(ch);
		if(myFile.eof()){
			myFile.seekp(0, ios_base::beg);
			myFile.seekg(-1, ios_base::cur);
			myFile >> A;
			database.append(A);
		}
		else{
			myFile.seekp(0, ios_base::end);
			myFile.seekg(0, ios_base::beg);
			database.load(myFile);
		}
		do{
			do{
				cout << "Register another person? (Y/N): ";
				cin >> check;
				check = toupper(check);
			}while(check != 'Y' && check != 'N');
			if(check == 'N') break;
			myFile >> A;
			database.append(A);
		}while(true);
		myFile.close();
		do{
			login = database.loginFun();
		}while(login);
	}
	else cout << "\nCannot open the file!!!";
}