/*
 * functions.cpp
 * 
 * This file contains all of the functions for the program, not including
 * the main() function or the object specific functions, such as constructors.
 *
 */ 

#include <iostream>
#include <string>
#include <list>
#include "library.h"
#include "user.h"

using namespace std;

/*
 * Function definitions
 */ 

// welcomeMenu: for printing the welcome menu, called once on startup
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

// optionMenu: for printing the options menu, called after every command completes
void optionMenu()
{
	cout << " PRESS: \n";
	cout << "\t[ 1 ] to Registering a new user\n";
	cout << "\t[ 2 ] to Look up user information\n";
	cout << "\t[ 3 ] to Search for media / check quantity\n";
	cout << "\t[ 4 ] to Issue a book to a user\n";
	cout << "\t[ 5 ] to Return a book to the library\n";
	cout << "\t[ 6 ] to Check for up-coming due-dates\n";
	cout << "\t[ 0 ] to EXIT\n";
}



/* 
 * registerNewUser: creates a new user prompts for input of data , then and adds them to the user list
 * @param: none.
 * @return: none.
 */
void registerNewUser(list <user> &UsersList)
{
	int uID;
	string un;
	cout << "Enter the new userID and username: ";
	cin >> uID >> un;
	user newUser;
	newUser.setUserID(uID);
	newUser.setUserName(un);
	UsersList.push_back(newUser);
	return;
}



/* 
 * userSearch: searches through the user list and prints user info if inputName matches userName
 * @param: inputName: the name of the user you are trying to search.
 * @return: none.
 */
void userSearch(string un, list<user> &UsersList)
{
    int found = 0;
    list<user>::iterator i = UsersList.begin();
    for (i; i != UsersList.end(); i++){
        if ((*i).getUserName() == un){
            cout << "User ID: " << (*i).getUserID() << endl;
            cout << "Username: " << (*i).getUserName() << endl;
            found = 1;
        }
    }
    if (found == 0){
        cout << "No results." << endl;
    }
	return;
}



/* 
 * mediaSearch: searches through media list and prints quantity and info if inputTitle matches media title
 * @param: inputTitle: the title of the media you are searching for
 * @return: none.
 */
void mediaSearch(string t, list <media> LibraryList)
{
	int found = 0;
	list<media>::iterator i = LibraryList.begin();
	for (i; i != LibraryList.end(); i++){
		if ((*i).getTitle() == t){
			cout << "Title: " << (*i).getTitle() << endl;
			cout << "Quantity: " << (*i).getQuantity() << endl;
			found = 1;
		}
	}
	if (found == 0){
		cout << "No results." << endl;
	}
	return;
}



/* 
 * issueBook: adds a specific media object to a user's collection and adjusts quantity of media in library.
 * @param: 
 * @return: none.
 */
void issueBook(int inputID, string inputTitle, list <media> LibraryList, list <user> UsersList)
{
	list<media>::iterator i = LibraryList.begin();
	list<user>::iterator j = UsersList.begin();
	for (j; j != UsersList.end(); j++){
		if ((*j).getUserID() == inputID){
			for (i; i != LibraryList.end(); i++){
				if ((*i).getTitle() == inputTitle){
					(*i).setQuantity((*i).getQuantity()-1);
					(*j).addToCollection((*i));
				}
			}
		}
	}
	return;
}



/* 
 * returnBook: removes a book from a users collection and adjusts quantity in media list
 * @param: inputUserName, inputMedia: the userName of user who borrowed book, and the title of the media borrowed
 * @return: none.
 */
void returnBook(int inputID, string inputTitle, list <media> LibraryList, list <user> UsersList)
{
	list<media>::iterator i = LibraryList.begin();
	list<user>::iterator j = UsersList.begin();
	for (j; j != UsersList.end(); j++){
		if ((*j).getUserID() == inputID){
			for (i; i != LibraryList.end(); i++){
				if ((*i).getTitle() == inputTitle){
					(*i).setQuantity((*i).getQuantity()+1);
					(*j).removeFromCollection((*i));
				}
			}
		}
	}
	return;
}



/* 
 * checkDueDates: loops through media list and looks for match of due date to input due date
 * @param: inputDate
 * @return: none.
 */
void checkDueDates()
{
	return;
}
