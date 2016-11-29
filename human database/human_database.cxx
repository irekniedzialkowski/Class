#include <iostream>
#include <fstream>
#include <string>
#include "human_database.h"

using namespace std;

main(){
	Person A;
	cout << A;
	fstream myFile;
	string directory;
	cout << "\nPlease type in the directory of a file to save output: ";
	cin >> directory;
	myFile.open(directory,ios::out);
	if(myFile.is_open()) myFile << A;
	myFile.close();
}