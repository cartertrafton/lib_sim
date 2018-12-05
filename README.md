# lib_sim (WIP)
## Library Simulation Software - OOP Final
----------------------------------------------------------------------------
	  _ _ _         _           
	 | (_) |       (_)          
	 | |_| |__  ___ _ _ __ ___  
	 | | | '_ \/ __| | '_ ` _ \ 
	 | | | |_) \__ \ | | | | | |
	 |_|_|_.__/|___/_|_| |_| |_|
                            
 
----------------------------------------------------------------------------

## Description 
Digitize the library management system 

## Installation
Download the ```src``` file, then using ```g++```, compile ```main.cpp``` and ```functions.cpp``` together and open the ```*.out``` file.

```
git clone https://github.com/cartertrafton/lib_sim
cd lib_sim/
g++ -o lib_sim.out src/main.cpp src/functions.cpp
./lib_sim.out
```

## Features:
  - [x] Registering a member 
  - [x] Look up member info
  - [x] Add books/media to the library
  - [x] Issue a book to member
  - [x] Delete from library	
  - [x] Search for books/media
  - [x] Check book info (quantity, facts, etc)
  - [x] Handling book returns
  - [x] Check up coming due dates

## Outline

### PSEUDOCODE
```
Start
Print welcome screen
Create media list
Create user list
Loop for function choice
  Registering a user
    Create new user and add to user list
  Look up customer info
    Search through user list
    Print info and held media
  Issue a book to user
    Add book to user's collection
    Change quantity of book in library
  Search for books/media
    Search through library lists 
    Print results and info
  Return books / Add new books to system
    Remove from user collection
    Change library quantity
  Check due dates
    Search through customer list
    Check for due dates
Exit
```

###  OBJECTS

- User
- Media
	- Books
	- Movies
	- Music
- ~~Employee~~

### FUNCTIONS

- Registering a customer
- Look up customer info
- Issue a book to member
- Search for books/media
- Check media quantity
- Return books / Add new books to system
- Check up coming due dates

----------------------------------------------------------------------------

## Meta
### Contributers
[@cartertrafton](https://github.com/cartertrafton/) - cartertrafton@gmail.com

[@juliacotter](https://github.com/juliacotter) - cotterj@wit.edu

### Timeline
- [x] Outline
- [x] Pseudocode 
- [x] Objects
- [x] Functions
- [x] Main program
- [ ] Report video

### Resources
- Profesor Carpenters's lectures


:~)