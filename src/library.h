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

class media 
{
	private:
		/*
		name
		quantity
		due_date
		*/
	public:
		/*
		constructor
		deconstructor
		get
		set
		print
		*/
};

class book : public media
{
	private:
		/*
		ISBN
		author
		*/
	public:
		/*
		constructor
		deconstructor
		get
		set
		print
		*/
};

class movie : public media
{
	private:
		/*
		director
		releaseYear
		*/
	public:
		/*
		constructor
		deconstructor
		get
		set
		print
		*/
};

class music : public media
{
	private:
		/*
		artist
		genre
		*/
	public:
		/*
		constructor
		deconstructor
		get
		set
		print
		*/
};
