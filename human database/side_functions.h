#ifndef SIDE_FUNCTIONS
#define SIDE_FUNCTIONS
#include <cctype>
#include <string>

string getFirstName(){
	string first_name;
	cout << "Please input first name: ";
	cin >> first_name;
	first_name[0] = toupper(first_name[0]);
	for(int i=1; i<first_name.size(); ++i) first_name[i] = tolower(first_name[i]);
	return first_name;
}

string getLastName(){
	string last_name;
	cout << "Please input last name: ";
	cin >> last_name;
	last_name[0] = toupper(last_name[0]);
	for(int i=1; i<last_name.size(); ++i) last_name[i] = tolower(last_name[i]);
	return last_name;
}


char getSex(){
	char ch;
	do{
		check = 0;
		cout << "PLease input type of sex (M/F): ";
		cin >> ch;
		if(ch != 'M' && ch != 'F'){
			cout << "Error! I haven't detected M or F...\n";
			check = 1;
		}
	}while(check);
	return ch;
}

string getLogin(){
	string login;

	return login;
}

string getPassword(){
	string password;

	return password;
}
#endif