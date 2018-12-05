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
#include <vector>
#include <ctime>

using namespace std;

/*
 * Function prototyping
 */
void optionMenu();
void welcomeMenu();
void registerNewUser(string, int, list <user> &UsersList);
void userSearch(string inputUserName, list<user> &UsersList);
void mediaSearch(string inputTitle, list <media *> &LibraryList);
void issueBook(int inputID, string inputTitle, tm inputDate, list <media *> &LibraryList, list <user> &UsersList);
void returnBook(int inputID, string inputTitle, list <media *> &LibraryList, list <user> &UsersList);
void checkDueDates(tm inputDate, list <media *> &LibraryList);



/*
 * Library/list creation 
 */
list<media *> LibraryList;
list<user> UsersList;
vector<media *> LibraryVector;


/*
 * Main loop
 */
int main()
{
	int inputID, uID, choice = 0;
	string searchMedia, inputName, inputTitle, un, searchName;
	tm  inputDate;

	/*
	 * Example media instantiation for testing
	 */
	book *exampleBook_0 = new book("Annihilation", 			2,  	9780374104092, "Jeff VanderMeer");
	book *exampleBook_1 = new book("DUNE", 					3,  	9783641173081, 		"Frank Herbert");
	book *exampleBook_2 = new book("The Hobbit", 			1,  	9789402306538, 		"J.R.R. Tolkien");
	book *exampleBook_3 = new book("A Clash of Kings", 		2,  	9780553579901, 		"George R.R. Martin");

	movie *exampleMovie_0 = new movie("The Departed", 		3, 	 	"Martin Scorsese",	2006);
	movie *exampleMovie_1 = new movie("First Man", 			1, 	 	"Damien Chazelle",	2018);
	movie *exampleMovie_2 = new movie("Blade Runner", 		4, 	 	"Ridley Scott",		1982);
	movie *exampleMovie_3 = new movie("Get Out", 			2, 	 	"Jordan Peele",		2017);

	music *exampleMusic_0 = new music("Led Zeppelin IV", 	2, 	 	"Led Zeppelin",				"Rock");
	music *exampleMusic_1 = new music("Pet Sounds", 		2, 	 	"Beach Boys", 			"Pop");
	music *exampleMusic_2 = new music("Electric Ladyland", 	1, 	 	"Jimi Hendrix",				"Rock");
	music *exampleMusic_3 = new music("Midnight Marauders", 3, 	 	"A Tribe Called QUest",	"Hip-hop");



	/*
	 * Example user creation
	 */
	registerNewUser("rgreen", 	1000, 	UsersList);
	registerNewUser("cbing", 	1001, 	UsersList);
	registerNewUser("rgeller",	1002, 	UsersList);
	registerNewUser("meller", 	1003,	UsersList);


	/*
	 * Library list population 
	 */
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



	welcomeMenu();
	do
	{
		optionMenu();
		cin >> choice;
		switch(choice)		
		{
			case 1: 											// NEW USER
				cout << "Enter the new userID and username: ";
				cin >> uID >> un;
				registerNewUser(un, uID, UsersList);
				break;

			case 2: 											// USER SEARCH

				cout << "Enter a user's name to search: ";
				cin >> searchName;
				userSearch(searchName, UsersList);
				break;

			case 3: 											// ISSUE BOOK TO USER
				cout << "Enter user ID: ";
				cin >> inputID;
				cout << "Enter title of media: ";
				cin >> inputTitle;
				cout << "Enter today's date (mm dd yyyy): ";
				cin >> inputDate.tm_mon >> inputDate.tm_mday >> inputDate.tm_year;
				issueBook(inputID, inputTitle, inputDate, LibraryList, UsersList);
				break;

			case 4: 											// MEDIA SEARCH
				cout << "Enter a Title to search: ";
				cin >> inputTitle;
				mediaSearch(inputTitle, LibraryList);
				break;

			case 5: 											// RETURN BOOK
				cout << "Enter user ID: ";
				cin >> inputID;
				cout << "Enter title of media: ";
				cin >> inputTitle;
				returnBook(inputID, inputTitle, LibraryList, UsersList);
				break;

			case 6: 											// CHECK DUE DATES
				cout << "Enter a date (mm dd yyyy): ";
				cin >> inputDate.tm_mon >> inputDate.tm_mday >> inputDate.tm_year;
				checkDueDates(inputDate, LibraryList);
				break;
			
			default:
				if (choice != 0)
					cout << "Invalid input." << endl;
		}

	} while(choice !=0);

	cout << "Exiting...\n";

	return 0;
}