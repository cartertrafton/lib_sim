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
		
		media(){}										// Constructor
		~media(){}										// Deconstructor

		virtual void setTitle(){}						// Set functions
		virtual void setQuantity(){}
		virtual void setDueDate(){}

		virtual string getTitle(){ return title; }		// Get functions
		virtual int getQuantity(){ return quanitity; }
		virtual string getDueDate(){ return dueDate; }		
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
		book(string inTitle, int inQuantity, string inDueDate, int inISBN, string inAuthor)
		{
			setTitle(inTitle); setQuantity(inQuantity); set setDueDate(inDueDate);
			setISBN(inISBN); setAuthor(inAuthor);
		}
		~book(){}					// Deconstructor

		void setISBN(int inISBN){ ISBN = inISBN; }			// Set functions 
		void setAuthor(string inAuthor){ author = inAuthor; }

		int getISBN(){ return ISBN; }						// Get functions
		string getAuthor(){ return author; }

		void print()										// Print data
		{
			cout << "\tTitle: " << this->title << endl;
			cout << "\tQuantity: " << this->quanitity << endl;
			cout << "\tAuthor: " << this->author << endl;
			cout << "\tISBN: " << this->ISBN << endl;
		}	
		
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
		movie(string inTitle, int inQuantity, string inDueDate, string inDirector, int inReleaseYear)
		{
			setTitle(inTitle); setQuantity(inQuantity); set setDueDate(inDueDate);
			setDirector(inDirector); setReleaseYear(inReleaseYear);
		}
		~movie(){}					// Deconstructor
		
		setDirector(string inDirector){ director = inDirector; }				// Set functions 
		setReleaseYear(int inReleaseYear){ releaseYear = inReleaseYear; }
		getDirector(){ return director; }										// Get functions
		getReleaseYear(){ return releaseYear; }
		
		void print()			// Print data
		{
			cout << "\tTitle: " << this->title << endl;
			cout << "\tQuantity: " << this->quanitity << endl;
			cout << "\tDirector: " << this->director << endl;
			cout << "\tRelease Year: " << this->releaseYear << endl;
		}					
		
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
		
		music(){}					// Constructor
		music(string inTitle, int inQuantity, string inDueDate, string inArtist, int inGenre)
		{
			setTitle(inTitle); setQuantity(inQuantity); set setDueDate(inDueDate);
			setArtist(inArtist); setGenre(inGenre);
		}
		~music(){}					// Deconstructor
		
		void setArtist(string inArtist){ artist = inArtist; }			// Set functions 
		void setGenre(string inGenre){ genre = inGenre; }
		
		string getArtist(){ return artist; }							// Get functions 
		string getGenre(){ return genre; }
		
		void print()	// Print data
		{
			cout << "\tTitle: " << this->title << endl;
			cout << "\tQuantity: " << this->quanitity << endl;
			cout << "\tArtist: " << this->artist << endl;
			cout << "\tGenre: " << this->genre << endl;
		}				
		
};
