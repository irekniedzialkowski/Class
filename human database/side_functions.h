#ifndef SIDE_FUNCTIONS
#define SIDE_FUNCTIONS
#include <cctype>
#include <string>
#include <ncurses.h>
// http://okolovich.info/convert-__date__-to-unsigned-int/
#define YEAR ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
              + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))
/*
#define MONTH (__DATE__ [2] == 'n' ? 1 \
               : __DATE__ [2] == 'b' ? 2 \
               : __DATE__ [2] == 'r' ? (__DATE__ [0] == 'M' ? 3 : 4) \
               : __DATE__ [2] == 'y' ? 5 \
               : __DATE__ [2] == 'n' ? 6 \
               : __DATE__ [2] == 'l' ? 7 \
               : __DATE__ [2] == 'g' ? 8 \
               : __DATE__ [2] == 'p' ? 9 \
               : __DATE__ [2] == 't' ? 10 \
               : __DATE__ [2] == 'v' ? 11 : 12)

#define DAY ((__DATE__ [4] == ' ' ? 0 : __DATE__ [4] - '0') * 10 + (__DATE__ [5] - '0'))
*/
bool leapYear(unsigned year) // https://pl.wikibooks.org/wiki/Kody_%C5%BAr%C3%B3d%C5%82owe/Rok_przest%C4%99pny
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

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
	cout << "Please type in your login: ";
	cin >> login;
	return login;
}

string getPassword(){
	string password;
	char ch;
	const char ENTER = 13;
	cout << "Please type in your password: ";
	ch = getch();
	while(ch != ENTER){
		password.append(ch);
		ch = getch();
	}
	return password;
}

date getDate(){
	date myDate;
	short check;
	cout << "Please input birth date: \n";
	do{
		check = 0;
		cout << "Year (YYYY): ";
		cin >> myDate.year;
		if(myDate.year < 1900 || myDate.year >= YEAR){
			cout << "Wrong year!\n";
			check = 1;
		}
	}while(check);

	do{
		check = 0;
		cout << "Month (MM): ";
		cin >> myDate.month;
		if(myDate.month < 1 || myDate.month > 12){
			cout << "Wrong month!\n";
			check = 1;
		}
	}while(check);

	do{
		check = 0;
		cout << "Day (DD): ";
		cin >> myDate.day;
		if(myDate.day < 1 || myDate.day > 31) check = 1;
		else switch(myDate.month){
			case 4:
			case 6:
			case 9:
			case 11:
				if(myDate.day == 31) check = 1;
				break;
			case 2:
				if(myDate.day > 29) check = 1;
				if(!leapYear(myDate.year) && myDate.day == 29) check = 1;
				break;

		if(check) cout << "Wrong day!\n";
	}while(check);


	return myDate;
}
#endif