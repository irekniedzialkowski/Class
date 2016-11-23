#include <iostream>
#include <fstream>
#include "human_database.h"
using namespace std;

main()
{
    Person Albert;
    fstream plik;
    plik.open("dane.txt",ios::out);
    cin>>Albert;
    plik<<Albert;
}
