WARNING: This program was written in Linux. Therefore it contains libraries (e.g. unistd.h) used ONLY under Linux systems.

Here I have created a Person class containing some data.

I believe it would prove useful while creating example user database.

side_functions.h library contains multiple functions used in human_database.h.
human_database.h library contains Person class and its constructors.

I used special functions found on the internet (links are given in comments) to cause no-echo when typing in the password. I can't use conio.h to use getch(), because it was implemented by Borland in Windows. Besides it is not the best solution.
