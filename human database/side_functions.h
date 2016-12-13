#ifndef SIDE_FUNCTIONS
#define SIDE_FUNCTIONS
#include <iostream>
#include <cctype>
#include <string>
#include <termios.h>
#include <unistd.h>
#include "human_object.h"
// http://okolovich.info/convert-__date__-to-unsigned-int/
#define YEAR ((((__DATE__ [7] - '0') * 10 + (__DATE__ [8] - '0')) * 10 \
              + (__DATE__ [9] - '0')) * 10 + (__DATE__ [10] - '0'))

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

using namespace std;

bool leapYear(unsigned year) // https://pl.wikibooks.org/wiki/Kody_%C5%BAr%C3%B3d%C5%82owe/Rok_przest%C4%99pny
{
    return (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
}

// http://stackoverflow.com/questions/13694170/how-do-i-hide-user-input-with-cin-in-c
void HideStdinKeystrokes(){
    termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    /* we want to disable echo */
    tty.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}

void ShowStdinKeystrokes(){
   termios tty;

    tcgetattr(STDIN_FILENO, &tty);

    /* we want to reenable echo */
    tty.c_lflag |= ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &tty);
}


void getFirstName(istream &in, Person &human){
	cout << "Please input first name: ";
	in >> human.first_name;
	human.first_name[0] = toupper(human.first_name[0]);
	for(int i=1; i<human.first_name.size(); ++i) human.first_name[i] = tolower(human.first_name[i]);
}

void getLastName(istream &in, Person &human){
	cout << "Please input last name: ";
	in >> human.last_name;
	human.last_name[0] = toupper(human.last_name[0]);
	for(int i=1; i<human.last_name.size(); ++i) human.last_name[i] = tolower(human.last_name[i]);
}

void getSex(istream &in, Person &human){
	short check;
	char x;
	do{
		check = 0;
		cout << "Please input type of sex (M/F): ";
		in >> x;
		x = toupper(x);
		if(x != 'M' && x != 'F'){
			cout << "Error! I haven't detected M or F...\n";
			check = 1;
		}
	}while(check);
	human.sex = x;
}

void getLogin(istream &in, Person &human){
	cout << "Please type in your login: ";
	in >> human.login;
}

void getPassword(istream &in, Person &human){
	cout << "Please type in your password: ";
	HideStdinKeystrokes();
	in >> human.password;
	ShowStdinKeystrokes();
}

void getDate(istream &in, Person &human){
	short check;
	unsigned short number;
	cout << "\nPlease input birth date: \n";
	do{
		check = 0;
		cout << "Year (YYYY): ";
		in >> number;
		if(number < 1900 || number > YEAR){
			cout << "Wrong year!\n";
			check = 1;
		}
	}while(check);
	human.birth.year = number;

	do{
		check = 0;
		cout << "Month (MM): ";
		in >> number;
		if(human.birth.year == YEAR && number > MONTH) check =1;
		else if(number < 1 || number > 12) check = 1;
		if(check) cout << "Wrong month!\n";
	}while(check);
	human.birth.month = number;

	do{
		check = 0;
		cout << "Day (DD): ";
		in >> number;
		if(human.birth.year == YEAR && human.birth.month == MONTH)
			if(number > DAY) check = 1;
		else if(number < 1 || number > 31) check = 1;
		else switch(human.birth.month){
			case 4:
			case 6:
			case 9:
			case 11:
				if(number == 31) check = 1;
				break;
			case 2:
				if(number > 29) check = 1;
				if(!leapYear(human.birth.year) && number == 29) check = 1;
				break;
			}
		if(check) cout << "Wrong day!\n";
	}while(check);
	human.birth.day = number;
}
#endif