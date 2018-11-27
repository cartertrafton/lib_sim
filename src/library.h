/* 
 * library.h
 * 
 * This file contains the class outlines for the various media types of the library.
 * The base class is media, with the three derived classes beign Book, Movie, and Music.
 * Each has a set of info special to the class, and a set of functions.
 * These are the classes that will be stored in the library list.
 *
 */

#include <iostream>
#include <string>

using namespace std;


/*
 * Media base class
 */
class media 						// Base class of all media
{
	private:
		
		string title;				// Title of media (Book, movie, or album)
		int quantityInLibrary;		// Current quanitity in Library
		string dueDate;				// The due date of book (or NULL)
		
	public:
		
		media(){}						// Constructor
		//media(){}	
		~media(){}						// Deconstructor
		
		virtual void setTite(){}		// Set functions
		virtual void setQuantity(){}
		virtual void setDueDate(){}
		
		virtual string getTitle(){}		// Get functions
		virtual int getQuantity(){}
		virtual string getDueDate(){}
		

		
};



/*
 * Book derived class
 */

class book : public media			
{
	private:

		int ISBN;					// ISBN of book
		string author;				// Author's name
		
	public:
		
		book(){}					// Constructor
		//book(){}
		~book(){}					// Deconstructor

		void setISBN(){}			// Set functions 
		void setAuthor(){}

		int getISBN(){}				// Get functions
		string getAuthor(){}

		void print(){}				// Print data
		
};



/*
 * Movie derived class
 */

class movie : public media			// Derived movie from media as sub-class
{
	private:
		
		string director;			// Director of movie
		int releaseYear;			// Year of release

	public:
		
		movie(){}					// Constructor
		//movie(){}
		~movie(){}					// Deconstructor
		
		setDirector(){}				// Set functions 
		setReleaseYear(){}
		
		getDirector(){}				// Get functions
		getReleaseYear(){}
		
		void print(){}				// Print data
		
};

/*
 * Music derived class
 */

class music : public media			// Derived music from media as sub-class
{	
	private:	
		string artist;				// Album artist
		string genre;				// Name of genre

	public:
		
		movie(){}					// Constructor
		//movie(){}
		~movie(){}					// Deconstructor
		
		void setArtist(){}			// Set functions 
		void setGenre(){}
		
		string getArtist(){}		// Get functions 
		string getGenre(){}
		
		void print(){}				// Print data
		
};
