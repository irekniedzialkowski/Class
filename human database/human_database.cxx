#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unistd.h>
#include "human_operator.h"
#include "human_object.h"
#include "list_object.h"
#include "list_login.h"
using namespace std;

main(){
	bool login;
	Person A; //my person class object
	char check = 'N', ch;
	listOD database; //my list class list
	fstream myFile;
	string directory;
	cout << "\nPlease type in the directory of your file (to save output or/and to load data from it): ";
	cin >> directory;
	myFile.open(directory, fstream::app); //creating the file if not existing or just opening it
	if(myFile.is_open()){
		myFile.close();
		myFile.open(directory, ios::in);
		myFile >> ch;
		if(myFile.eof()){
			myFile.close(); //file is empty
			myFile.open(directory, fstream::app);
			cin >> A; //obligatory registering a person
			myFile << A;
			database.append(A);
			myFile.close();
		}
		else{
			myFile.close(); //file is not empty
			cout << "\nLoading data...\n";
			usleep(3000000); //wait 3 seconds (from <unistd.h> library)
			database.load(myFile, directory);
			cout << "Loaded.\n";
		}
		myFile.open(directory, fstream::app);
		do{
			do{
				cout << "Register another person? (Y/N): ";
				cin >> check;
				check = toupper(check);
			}while(check != 'Y' && check != 'N');
			if(check == 'N') break;
			cin >> A;
			myFile << A;
			database.append(A);
		}while(true);
		myFile.close();
		do{
			login = database.loginFun(); //LOGIN function
		}while(login);
	}
	else cout << "\nCannot open the file!!!";
}