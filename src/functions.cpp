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
#include <ctime>
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
	cout << "\n PRESS: \n";
	cout << "\t[ 1 ] to Registering a new user\n";
	cout << "\t[ 2 ] to Look up user information\n";
	cout << "\t[ 3 ] to Issue a book to a user\n";
	cout << "\t[ 4 ] to Search for media / check quantity\n";
	cout << "\t[ 5 ] to Return a book to the library\n";
	cout << "\t[ 6 ] to Check for up-coming due-dates\n";
	cout << "\t[ 0 ] to EXIT\n";
}


/* 
 * registerNewUser: creates a new user prompts for input of data , then and adds them to the user list
 * @param: inName, inID, &UsersList: input name, input ID, and pass by reference of the UsersList
 * @return: none.
 */
void registerNewUser(string inName, int inID, list <user> &UsersList)
{
	user newUser;
	newUser.setUserID(inID);
	newUser.setUserName(inName);
	UsersList.push_back(newUser);
	return;
}



/* 
 * userSearch: searches through the user list and prints user info if inputName matches userName
 * @param: inputName, &UsersList: the name of the user you are trying to search and the memory of UsersList.
 * @return: none.
 */
void userSearch(string inputUserName, list<user> &UsersList)
{
    int found = 0;
    list<user>::iterator i = UsersList.begin();
    for (i; i != UsersList.end(); i++){
        if ((*i).getUserName() == inputUserName){
            (*i).print();
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
 * @param: inputTitle, &LibraryList: the title of the media you are searching for and memory location of LibraryList
 * @return: none.
 */
void mediaSearch(string inputTitle, list <media *> &LibraryList)
{
	int found = 0;
	list<media *>::iterator i = LibraryList.begin();
	for (i; i != LibraryList.end(); i++){
		if ((*i)->getTitle() == inputTitle){
			(*i)->print();
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
 * @param: inputID, inputTitle, &LibraryList, &UsersList: the ID of the user, media title, and locations of memory for the two lists
 * @return: none.
 */
void issueBook(int inputID, string inputTitle, tm inputDate, list <media *> &LibraryList, list <user> &UsersList)
{
	list<media *>::iterator i = LibraryList.begin();
	list<user>::iterator j = UsersList.begin();
	for (j; j != UsersList.end(); j++){
		if ((*j).getUserID() == inputID){
			for (i; i != LibraryList.end(); i++){
				if ((*i)->getTitle() == inputTitle){
					(*i)->setQuantity((*i)->getQuantity()-1);
					(*j).addToCollection((*i)->getTitle());
					inputDate.tm_mon -=1;				//tm_mon: months 0-11
					inputDate.tm_year -=1900;			//tm_year: years since 1900
					inputDate.tm_mday += 14;
					(*i)->setDueDate(inputDate);
					cout << "The due date is " << inputDate.tm_mon+1 << " " << inputDate.tm_mday << " " << inputDate.tm_year+1900 << endl;		
				}
			}
		}
	}
	return;
}



/* 
 * returnBook: removes a book from a users collection and adjusts quantity in media list
 * @param: inputID, inputTitle, &LibraryList, &UsersList: the ID of the user, media title, and locations of memory for the two lists
 * @return: none.
 */
void returnBook(int inputID, string inputTitle, list <media *> &LibraryList, list <user> &UsersList)
{
	list<media *>::iterator i = LibraryList.begin();
	list<user>::iterator j = UsersList.begin();
	for (j; j != UsersList.end(); j++){
		if ((*j).getUserID() == inputID){
			for (i; i != LibraryList.end(); i++){
				if ((*i)->getTitle() == inputTitle){
					(*i)->setQuantity((*i)->getQuantity()+1);
					(*j).removeFromCollection((*i)->getTitle());
					tm noDate = {};
					(*i)->setDueDate(noDate);
				}
			}
		}
	}
	return;
}



/* 
 * checkDueDates: loops through media list and looks for match of due date to input due date
 * @param: inputDate, &LibraryList: the due date you are searching for and the location of memory of LibraryList
 * @return: none.
 */
void checkDueDates(tm inputDate, list <media *> &LibraryList)
{
	int found = 0;
	list<media *>::iterator i = LibraryList.begin();
	inputDate.tm_mon -=1;
	inputDate.tm_year -=1900;
	for (i; i != LibraryList.end(); i++){
		if ((*i)->getDueDate().tm_mon == inputDate.tm_mon && (*i)->getDueDate().tm_mday == inputDate.tm_mday){
			(*i)->print();
			found = 1;
		}
	}
	if (found == 0){
		cout << "No results." << endl;
	}
	return;
}
