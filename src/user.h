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
#include <vector>

using namespace std;


/*
 * User account class
 */
class user 
{
	private:
		int userID;
		string userName;
		vector<string> collection;		// Users current collection of books.
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
			cout << "\n\tUserID: " << this->userID << endl;
			cout << "\tName: " << this->userName << endl;
			cout << "\tCollection: \n";
            for (int i; i < collection.size(); i++)
            {
            	cout << "\t\t" << collection[i];
            }
		}			
			
		/*
		 * addToCollection: adds the title of a piece object to the collection vector.
		 * @param: inMedia: title of media to add to colletion.
		 * @return: none.
		 */
		void addToCollection(string inMedia)
		{ 
			collection.push_back(inMedia);
		}

		/*
		 * removeFromCollection: Loops through collection vector and erases if title matches.
		 * @param: inMedia: title of media to remove from collection.
		 * @return: none.
		 */
		void removeFromCollection(string inMedia)
		{
			    for (int i = 0; i < collection.size(); i++) 
			    {
					if ( inMedia == collection.at(i))
					{
						collection.erase(collection.begin()+i);
					}
			    }
		}


		
		
};