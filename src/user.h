/* 
 * user.h
 * 
 * This file contains the class outline for the user class.
 * This class will be have information relating to the users data, 
 * and the media that they are currently taking out from the library,
 * as well as functions for adding media to and removing media from the 
 * user's collection.
 *
 */

#include <iostream>
#include <string>

using namespace std;


/*
 * User account class
 */
class user 
{
	private:
		int userID;
		string userName;
		// TODO: media* collection[]			// Users current collection of books.
	public:
		
		user(){}				// Constructor
		user(int inID, string inName)
		{
			setUserID(inID); setUserName(inName);
		}
		~user(){}				// Deconstructor

		void setUserID(int inID){ userID = inID; }		// Set functions
		void setUserName(string inName){ userName = inName; }

		int getUserID(){ return userID; }		// Get funcitons
		string getUserName(){ return userName; }

		void print() 	// Print data
		{
			cout << "\tUserID: " << this->userID << endl;
			cout << "\tName: " << this->userName << endl;
		}			
			
		// TODO: void addToCollection[]
		// TODO : void removeFromCollection[]

		
		
};