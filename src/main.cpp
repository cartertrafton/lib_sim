/*
 * main.cpp
 * 
 * This is the main function of this program. 
 * A continuous loop runs while the program is open, and offers users a choice 
 * of accessing mulitple different funcitons. 
 *
 */ 

#include "user.h"
//#include "library.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Function prototyping
 */
void optionMenu();
void welcomeMenu();



/*
 * Media instantiation
 */

int main()
{
	int choice = 0;


	welcomeMenu();

	while(1)
	{
		/*
		 * Main loop
		 */

		optionMenu();
		cin >> choice;

		switch(choice)
		{
			case 0: break;
			case 1: 
				break;
			case 2: 
				break;
			case 3: 
				break;
			case 4: 
				break;
			case 5: 
				break;
			case 6: 
				break;

		}

		if (choice == 0)
		{
			cout << "Exiting...\n";
			exit(0);
		}

	}

	return 0;
}
 
void welcomeMenu()
{
	cout << "---------------------------------------------\n";
	cout << "\t WELCOME TO\n";
	cout << "\t  _ _ _         _           \n";
	cout << "\t | (_) |       (_)          \n";
	cout << "\t | |_| |__  ___ _ _ __ ___  \n";
	cout << "\t | | | '_ \\/ __| | '_ ` _ \\ \n";
	cout << "\t | | | |_) \\__ \\ | | | | | |\n";
	cout << "\t |_|_|_.__/|___/_|_| |_| |_|\n";
	cout << "\n\tLibrary Management Software\n";
	cout << "---------------------------------------------\n";
}

void optionMenu()
{
	cout << " PRESS: \n";
	cout << "\t[ 1 ] to Registering a new user\n";
	cout << "\t[ 2 ] to Look up user information\n";
	cout << "\t[ 3 ] to Issue a book to a user\n";
	cout << "\t[ 4 ] to Search for media / check quantity\n";
	cout << "\t[ 5 ] to Return book from user\n";
	cout << "\t[ 6 ] to Check for up-coming due-dates\n";
	cout << "\t[ 0 ] to EXIT\n";
}




