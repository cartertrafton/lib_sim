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

class user 
{
	private:
		
		int userID;
		string userName;
		//collection[]			// Users current collection of books.
		
	public:
		
		user(){}				// Constructor
		//user(){}
		~user(){}				// Deconstructor

		void setUserID(){}		// Set functions
		void setUserName(){}

		int getUserID(){}		// Get funcitons
		string getUserName(){}

		void print(){}			// Print data
			
		// addMedia to collection
		// removeMedia form collection

		
		
};