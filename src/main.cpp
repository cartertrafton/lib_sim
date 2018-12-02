/*
 * main.cpp
 * 
 * This is the main function of this program. 
 * A continuous loop runs while the program is open, and offers users a choice 
 * of accessing mulitple different funcitons. 
 *
 */ 

#include "user.h"
#include "library.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * Function prototyping
 */
void optionMenu();
void welcomeMenu();
// TODO: Add rest of functions

/*
 * Test media instantiation
 */
// TODO: Add media instatiation  



/*
 * Test user creation
 */
// TODO: Add user instatiation and populate collections with media



/*
 * Library/list creation and population
 */
// TODO: Create library list and populate with media
// TODO: Create user list and populate with users



/*
 * Main loop
 */
int main()
{
	int choice = 0;
	welcomeMenu();

	while(1)
	{
		optionMenu();
		cin >> choice;
		switch(choice)		// TODO: Add choices -> functions
		{
			case 0: break;	// EXIT
			case 1: 		// NEW USER
				break;
			case 2: 		// USER SEARCH
				break;
			case 3: 		// ISSUE BOOK TO USER
				break;
			case 4: 		// MEDIA SEARCH
				break;
			case 5: 		// RETURN BOOK
				break;
			case 6: 		// CHECK DUE DATES
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