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
#include <list>

using namespace std;

/*
 * Function prototyping
 */
void optionMenu();
void welcomeMenu();
void registerNewUser();
void userSearch(int);
void mediaSearch(string);
void issueBook();
void returnBook();
void checkDueDates();


/*
 * Example media instantiation for testing
 */
book *exampleBook_0 = new book("Annihilation", 			2, NULL, 	9780374104092, 		"Jeff VanderMeer");
book *exampleBook_1 = new book("DUNE", 					3, NULL, 	9783641173081, 		"Frank Herbert");
book *exampleBook_2 = new book("The Hobbit", 			1, NULL, 	9789402306538, 		"J.R.R. Tolkien");
book *exampleBook_3 = new book("A Clash of Kings", 		2, NULL, 	9780553579901, 		"George R.R. Martin");

movie *exampleMovie_0 = new movie("The Departed", 		3, 	NULL, 	"Martin Scorsese",	2006);
movie *exampleMovie_1 = new movie("First Man", 			1, 	NULL, 	"Damien Chazelle",	2018);
movie *exampleMovie_2 = new movie("Blade Runner", 		4, 	NULL, 	"Ridley Scott",		1982);
movie *exampleMovie_3 = new movie("Get Out", 			2, 	NULL, 	"Jordan Peele",		2017);

music *exampleMusic_0 = new music("Led Zeppelin IV", 	2, 	NULL, 	"Led Zeppelin",			"Rock");
music *exampleMusic_1 = new music("Pet Sounds", 		2, 	NULL, 	"Beach Boys", 			"Pop");
music *exampleMusic_2 = new music("Electric Ladyland", 	1, 	NULL, 	"Jimi Hendrix",			"Rock");
music *exampleMusic_3 = new music("Midnight Marauders", 3, 	NULL, 	"A Tribe Called QUest",	"Hip-hop");




/*
 * Example user creation and person collection population
 */
user *userExample_0 = new user(1003, "Rachel Green");
user *userExample_1 = new user(1001, "Chandler Bing");
user *userExample_2 = new user(1002, "Ross Geller");
user *userExample_3 = new user(1003, "Monica Geller");

// userExample_0.addToCollection(exampleBook_0);
// userExample_1.addToCollection(exampleBook_1);
// userExample_2.addToCollection(exampleMovie_0);
// userExample_3.addToCollection(exampleMusic_0);





/*
 * Library/list creation and population
 */
list<user> UsersList;
list<media> LibraryList;

/*
LibraryList.push_back(exampleBook_0);
LibraryList.push_back(exampleBook_1);
LibraryList.push_back(exampleBook_2);
LibraryList.push_back(exampleBook_3);
LibraryList.push_back(exampleMovie_0);
LibraryList.push_back(exampleMovie_1);
LibraryList.push_back(exampleMovie_2);
LibraryList.push_back(exampleMovie_3);
LibraryList.push_back(exampleMusic_0);
LibraryList.push_back(exampleMusic_1);
LibraryList.push_back(exampleMusic_2);
LibraryList.push_back(exampleMusic_3);

UsersList.push_back(userExample_0);
UsersList.push_back(userExample_1);
UsersList.push_back(userExample_2);
UsersList.push_back(userExample_3);
*/


/*
 * Main loop
 */
int main()
{
	int choice = 0;
	int inputID;
	string searchMedia, inputName, inputTitle, inputDate;
	string searchName;

	welcomeMenu();

	while(1)
	{
		optionMenu();
		cin >> choice;
		switch(choice)		// TODO: Add choices -> functions
		{
			case 0: break;										// EXIT

			case 1: 											// NEW USER
				registerNewUser();
				break;

			case 2: 											// USER SEARCH
				cout << "Enter a User ID to search: ";
				cin >> inputID;
				userSearch(inputID);
				break;

			case 3: 											// ISSUE BOOK TO USER
				cout << "Enter user ID: ";
				cin >> inputID;
				cout << "Enter title of media: ";
				cin >> inputTitle;
				//issueBook(inputID, inputTitle);
				break;

			case 4: 											// MEDIA SEARCH
				cout << "Enter a Title to search: ";
				cin >> inputTitle;
				mediaSearch(inputTitle);
				break;

			case 5: 											// RETURN BOOK
				cout << "Enter user ID: ";
				cin >> inputID;
				cout << "Enter title of media: ";
				cin >> inputTitle;
				//returnBook(inputID, inputTitle);
				break;

			case 6: 											// CHECK DUE DATES
				cout << "Enter a date: ";
				cin >> inputDate;
				//checkDueDates(inputDate);
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