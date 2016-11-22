#include <iostream>
#include <fstream>
#include <string>
#include "human_database.h"

using namespace std;

int main(){
	Person A;
	fstream myFile;
	string directory;
	cout << "Please type in the directory of a file to save output: ";
	cin >> directory;
	myFile.open(directory,ios::in);
	//if(!myFile.is_open()) myFile << A;
	myFile.close();
}