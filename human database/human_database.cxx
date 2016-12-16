#include <iostream>
#include <fstream>
#include <string>
#include "human_operator.h"
#include "human_object.h"
#include "list.h"
#include "list_side_functions.h"

using namespace std;

main(){
	Person A;
	cin >> A;
	cout << "\nYou have typed in following data:\n" << A;
	listOD database;
	/*fstream myFile;
	string directory;
	cout << "\nPlease type in the directory of a file to save output: ";
	cin >> directory;
	myFile.open(directory,ios::out);
	if(myFile.is_open()) myFile << A;
	myFile.close();
	myFile.open(directory,ios::in);
	if(myFile.is_open()) database.append(A);
	myFile.close();*/
	cout << "Insert the data into your database: \n";
	cin >> database;
	cout << "\nYour database overview: \n" << database;
	database.loginFun();
}