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
		int quantity;				// Current quantity in Library
		string dueDate;				// The due date of book (or NULL)
		
	public:
		
		media(){}					// Constructor
		~media(){}					// Deconstructor

		virtual void setTitle(string inTitle){ title = inTitle; }		// Set functions
		virtual void setQuantity(int inQuantity){ quantity = inQuantity; }
		virtual void setDueDate(string inDueDate){ dueDate = inDueDate; }

		virtual string getTitle(){ return title; }						// Get functions
		virtual int getQuantity(){ return quantity; }
		virtual string getDueDate(){ return dueDate; }		
};


/*
 * Book derived class
 */
class book : public media			
{
	private:
		long ISBN;					// ISBN of book
		string author;				// Author's name
	public:
		book(){}					// Constructor
		book(string inTitle, int inQuantity, string inDueDate, long inISBN, string inAuthor)
		{
			setTitle(inTitle); setQuantity(inQuantity); setDueDate(inDueDate);
			setISBN(inISBN); setAuthor(inAuthor);
		}
		~book(){}					// Deconstructor

		void setISBN(int inISBN){ ISBN = inISBN; }			// Set functions 
		void setAuthor(string inAuthor){ author = inAuthor; }

		long getISBN(){ return ISBN; }						// Get functions
		string getAuthor(){ return author; }

		void print()										// Print data
		{
			cout << "\tTitle: " << this->getTitle() << endl;
			cout << "\tQuantity: " << this->getQuantity() << endl;
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
			setTitle(inTitle); setQuantity(inQuantity); setDueDate(inDueDate);
			setDirector(inDirector); setReleaseYear(inReleaseYear);
		}
		~movie(){}					// Deconstructor
		
		void setDirector(string inDirector){ director = inDirector; }				// Set functions 
		void setReleaseYear(int inReleaseYear){ releaseYear = inReleaseYear; }
		string getDirector(){ return director; }										// Get functions
		int getReleaseYear(){ return releaseYear; }
		
		void print()			// Print data
		{
			cout << "\tTitle: " << this->getTitle() << endl;
			cout << "\tQuantity: " << this->getQuantity() << endl;
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
		music(string inTitle, int inQuantity, string inDueDate, string inArtist, string inGenre)
		{
			setTitle(inTitle); setQuantity(inQuantity); setDueDate(inDueDate);
			setArtist(inArtist); setGenre(inGenre);
		}
		~music(){}					// Deconstructor
		
		void setArtist(string inArtist){ artist = inArtist; }			// Set functions 
		void setGenre(string inGenre){ genre = inGenre; }
		
		string getArtist(){ return artist; }							// Get functions 
		string getGenre(){ return genre; }
		
		void print()	// Print data
		{
			cout << "\tTitle: " << this->getTitle() << endl;
			cout << "\tQuantity: " << this->getQuantity() << endl;
			cout << "\tArtist: " << this->artist << endl;
			cout << "\tGenre: " << this->genre << endl;
		}					
};