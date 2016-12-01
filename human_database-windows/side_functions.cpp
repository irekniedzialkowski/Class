#include <cctype>
#include <string>
#include <iostream>
#include "human_database.h"
//#include <ncurses.h>
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
using namespace std;

bool leapYear(unsigned year) // https://pl.wikibooks.org/wiki/Kody_%C5%BAr%C3%B3d%C5%82owe/Rok_przest%C4%99pny
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

istream& operator>>(istream &in, date &myDate){
	short check;
	do{
        check=0;
        cout << "DAY (DD): ";
        in >> myDate.day;
        if(myDate.day < 1 || myDate.day > 31) check = 1;
        if(check) cout << "Wrong day!"<<endl;
	}while(check);

	do{
		check = 0;
		cout << "Month (MM): ";
		in >> myDate.month;
		if(myDate.month < 1 || myDate.month > 12){
			cout << "Wrong month!\n";
			check = 1;
		}
	}while(check);

    cout << "Please input birth date: \n";
	do{
		check = 0;
		cout << "Year (YYYY): ";
		in >> myDate.year;
		if(myDate.year < 1900 || myDate.year >= YEAR){
			cout << "Wrong year!\n";
			check = 1;
		}
	}while(check);

        do{
		check = 0;
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
		}
		if(check)
        {
            cout << "Wrong day!\n";
            cout << "Day (DD): ";
            in >> myDate.day;
        }
	}while(check);


	return in;
}

istream& operator>>(istream &in, Person &d)
{
	cout << "Please type in your login: ";
	in >> d.login;
	//char ch;
	//const char ENTER = 13;
	cout << "Please type in your password: ";
	//ch = getch();
	/*while(ch != ENTER){
		in>>(ch);
		ch = getch();
	}
	return password;*/
	in>>d.password;
	cout << "Please input first name: ";
	in >> d.first_name;
	cout << "Please input last name: ";
	in >> d.last_name;
		short check;
	do{
		check = 0;
		cout << "PLease input type of sex (M/F): ";
		in >> d.sex;
		if(d.sex != 'M' && d.sex!= 'F' && d.sex !='m' && d.sex !='f'){
			cout << "Error! I haven't detected M or F...\n";
			check = 1;
		}
	}while(check);
    in >> d.birth;

return in;
}

ostream& operator<<(ostream &out, date &myDate)
{
    if(myDate.day<10) out<<'0';
    out<<myDate.day<<" ";
    if(myDate.month<10) out<<'0';
    out<<myDate.month<<" "<<myDate.year<<endl;
    return out;
}
ostream& operator<<(ostream &out, Person &d)
{
    out<<"login : "<<d.login<<" password : "<<d.password<<endl;
	d.first_name[0] = toupper(d.first_name[0]);
	for(int i=1; i<d.first_name.size(); ++i)
        d.first_name[i] = tolower(d.first_name[i]);
		d.last_name[0] = toupper(d.last_name[0]);
	for(int i=1; i<d.last_name.size(); ++i)
        d.last_name[i] = tolower(d.last_name[i]);
    out<<"Name : "<<d.first_name<<" "<<d.last_name<<endl;
    out<<d.sex<<endl;
    out<<"Date of birth : "<<d.birth;
    return out;
}


